#include "lab.h"
const string js = "Accept: application/json";
const string key = 
"X-Mashape-Key: q9bHltcHV2mshsWdmYro91TZDWyCp1vFXk8jsnHs80kSDWR3Co";

size_t handleData(void* ptr, size_t size, size_t nmemb, void* g)
{
    *(static_cast<string*>(g)) += (static_cast<char*>(ptr));
    return size * nmemb;
}

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

list<Card> getData(string query, string endpoint)
{
    list<Card> cardlist;
    
    string search = "https://omgvamp-hearthstone-v1.p.mashape.com/cards/";
    search = search + endpoint + "/";
    while (query.find(" ")!=string::npos)
        query.replace(query.find(" "), 1, "%20");
    search = search + query + "?collectible=1";
    
    struct curl_slist *slist1 = NULL;
    slist1 = curl_slist_append(slist1, js.c_str());
    slist1 = curl_slist_append(slist1, key.c_str());

    FILE *carddata;
    CURL* curl = curl_easy_init();
    if (curl) {
	carddata = fopen("carddb.txt","wb");
	curl_easy_setopt(curl, CURLOPT_URL, search.c_str());
	curl_easy_setopt(curl,CURLOPT_HTTPHEADER, slist1);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, carddata);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	fclose(carddata);
    }

    ifstream ifs ("carddb.txt");    
    json ji = json::parse(ifs);
    
    for (int i = 0; i < ji.size(); i++)
    {
	Card card;
	if (!ji[i]["name"].is_null()) card.name = ji[i]["name"];
	if (!ji[i]["cardSet"].is_null()) card.cardSet = ji[i]["cardSet"];
	if (!ji[i]["type"].is_null()) card.type = ji[i]["type"];
	if (!ji[i]["text"].is_null()) card.text = ji[i]["text"];
	if (!ji[i]["playerClass"].is_null())
	    card.playerClass = ji[i]["playerClass"];
	if (!ji[i]["race"].is_null()) card.race = ji[i]["race"];
	if (!ji[i]["img"].is_null()) card.img = ji[i]["img"];
	if (!ji[i]["health"].is_null()) card.health = ji[i]["health"];
	if (!ji[i]["attack"].is_null()) card.attack = ji[i]["attack"];
	if (!ji[i]["durability"].is_null()) 
	    card.durability = ji[i]["durability"];
	if (!ji[i]["cost"].is_null()) card.cost = ji[i]["cost"];
	card.fit = 0;
	cardlist.push_back(card);
    }
    

    return cardlist;
}
