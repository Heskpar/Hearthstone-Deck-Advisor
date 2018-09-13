#include "lab.h"

void cbSearch(Fl_Button*,void*)
{
    string s = sq->value();
    Card ci = getCard(s);
    
    if(ci.name == "error")
    {
	if(dw) dw->hide();
	cw->image(new Fl_Image(0,0,0));
	cw->label("error: card not found");
	cw->redraw();
    }
    
    else
    {
	FILE *picture;
	CURL* curl = curl_easy_init();
	if (curl) {
	    picture = fopen("card.png","wb");
	    curl_easy_setopt(curl, CURLOPT_URL, ci.img.c_str());
	    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, picture);
	    curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	    fclose(picture);
	}
	cw->label();
	cw->image(new Fl_PNG_Image("card.png"));
	cw->redraw();
    
	if(dw) dw->hide();
	makeDisplayWindow(ci)->show();
	dw->redraw();
    }
}
