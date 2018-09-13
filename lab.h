#include <config.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include "json.hpp"
#include <list>
#include <FL/Fl_Cairo_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <algorithm>

using json = nlohmann::json;
using namespace std;

struct Card{string name, cardSet, type, text, playerClass, race, img;  
    int health, attack, durability, cost, fit;};
Card getCard(string query);
list<Card> getData(string query, string endpoint);
size_t handleData(void* c, size_t s, size_t n, void* g);
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);
Fl_Cairo_Window * makeDisplayWindow(Card inputCard);
Fl_Cairo_Window * makeSearchWindow();
list<string> tokenize(string str);
list<Card> compareSpell(Card inputCard);
list<Card> cullCards(list<Card> retrievedCards);
list<Card> compareMinions(Card theirCard);
list<Card> compareWeapons(Card theirCard);
extern Fl_Cairo_Window * dw;
extern Fl_Box * g;
extern Fl_Input * sq;
extern Fl_Input * sq;
extern Fl_Cairo_Window * gw;
extern Fl_Box * cw;
extern Fl_Button * sr;
extern ofstream history;
