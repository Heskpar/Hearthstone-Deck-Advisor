#include "lab.h"

Fl_Cairo_Window * dw;
Fl_Box * b1;
Fl_Box * b2;
Fl_Box * b3;
extern Fl_Input * sq;

Fl_Cairo_Window * makeDisplayWindow(Card inputCard)
{
    list<Card> cardlist;
    list<Card> topThree;
    
    dw = new Fl_Cairo_Window (921,415);
    dw->color(FL_WHITE);
    dw->label("Recommended Cards");
    
    b1 = new Fl_Box(FL_FLAT_BOX,0,0, 307,415,"");
    b1->color(FL_WHITE);
    
    b2 = new Fl_Box(FL_FLAT_BOX,307,0, 307,415,"");
    b2->color(FL_WHITE);
    
    b3 = new Fl_Box(FL_FLAT_BOX,614,0, 307,415,"");
    b3->color(FL_WHITE);
    
    if(inputCard.type == "Minion")
	 cardlist = compareMinions(inputCard);
    else if(inputCard.type == "Spell")
	cardlist = compareSpell(inputCard);
    else if(inputCard.type == "Weapon")
	cardlist = compareWeapons(inputCard);
    
    topThree = cullCards(cardlist);
    Card one = topThree.front();
    topThree.pop_front();
    Card two = topThree.front();
    topThree.pop_front();
    Card three = topThree.front();
    
    FILE *img1;
    CURL* curl = curl_easy_init();
    if (curl) {
	img1 = fopen("one.png","wb");
	curl_easy_setopt(curl, CURLOPT_URL, one.img.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, img1);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	fclose(img1);
    }
    
    FILE *img2;
    CURL* curl2 = curl_easy_init();
    if (curl2) {
	img2 = fopen("two.png","wb");
	curl_easy_setopt(curl2, CURLOPT_URL, two.img.c_str());
	curl_easy_setopt(curl2, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl2, CURLOPT_WRITEDATA, img2);
	curl_easy_perform(curl2);
	curl_easy_cleanup(curl2);
	fclose(img2);
    }
    
    FILE *img3;
    CURL* curl3 = curl_easy_init();
    if (curl3) {
	img3 = fopen("three.png","wb");
	curl_easy_setopt(curl3, CURLOPT_URL, three.img.c_str());
	curl_easy_setopt(curl3, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl3, CURLOPT_WRITEDATA, img3);
	curl_easy_perform(curl3);
	curl_easy_cleanup(curl3);
	fclose(img3);
    }

    b1->image(new Fl_PNG_Image("one.png"));
    b1->color(FL_WHITE);
    b1->redraw();
    b2->image(new Fl_PNG_Image("two.png"));
    b2->color(FL_WHITE);
    b2->redraw();
    b3->image(new Fl_PNG_Image("three.png"));
    b3->color(FL_WHITE);
    b3->redraw();
    
    return dw;
}
