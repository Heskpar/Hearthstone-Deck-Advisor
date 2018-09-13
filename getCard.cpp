#include "lab.h"
const string js = "Accept: application/json";
const string key = 
"X-Mashape-Key: q9bHltcHV2mshsWdmYro91TZDWyCp1vFXk8jsnHs80kSDWR3Co";

Card getCard(string query)
{
    Card card;
    string output;
    
    struct curl_slist *slist1 = NULL;
    slist1 = curl_slist_append(slist1, js.c_str());
    slist1 = curl_slist_append(slist1, key.c_str());
    
    string cmd = "https://omgvamp-hearthstone-v1.p.mashape.com/cards/search/";
    
    while (query.find(" ")!=string::npos)
        query.replace(query.find(" "), 1, "%20");
    
    string search = cmd + query + "?collectible=1";
    
    CURL* handle = curl_easy_init();
    curl_easy_setopt(handle,CURLOPT_URL,search.c_str());
    curl_easy_setopt(handle,CURLOPT_HTTPHEADER, slist1);
    curl_easy_setopt(handle,CURLOPT_WRITEFUNCTION,handleData);
    curl_easy_setopt(handle,CURLOPT_WRITEDATA,&output);
    curl_easy_perform(handle);

    while (!(output.back() == '}'||output.back() == ']') ) output.pop_back();
    //cout << output << endl;

    json ji = json::parse(output);
    if (output.find("Card not found") != string::npos){
	cout << "error card not found" << endl;
	card.name = "error";
    }
    else
    {
	if (!ji[0]["name"].is_null()) card.name = ji[0]["name"];
	if (!ji[0]["cardSet"].is_null()) card.cardSet = ji[0]["cardSet"];
	if (!ji[0]["type"].is_null()) card.type = ji[0]["type"];
	if (!ji[0]["text"].is_null()) card.text = ji[0]["text"];
	if (!ji[0]["playerClass"].is_null())
	    card.playerClass = ji[0]["playerClass"];
	if (!ji[0]["race"].is_null()) card.race = ji[0]["race"];
	if (!ji[0]["img"].is_null()) card.img = ji[0]["img"];
	if (!ji[0]["health"].is_null()) card.health = ji[0]["health"];
	if (!ji[0]["attack"].is_null()) card.attack = ji[0]["attack"];
	if (!ji[0]["durability"].is_null()) 
	    card.durability = ji[0]["durability"];
	if (!ji[0]["cost"].is_null()) card.cost = ji[0]["cost"];
    }
    return card;
}
