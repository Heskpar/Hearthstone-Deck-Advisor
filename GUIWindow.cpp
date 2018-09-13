#include "lab.h"

Fl_Input * sq;
Fl_Cairo_Window * gw;
Fl_Box * cw;
Fl_Button * sr;
void cbSearch(Fl_Button*,void*);

Fl_Cairo_Window * makeSearchWindow()
{
    int width = 310;
    int height = 500;

    gw = new Fl_Cairo_Window (width,height);
    gw->color(FL_WHITE);
    gw->label("Card Replacement Searcher");
    
    cw = new Fl_Box(FL_FLAT_BOX,0,85, width,415,"");
    cw->color(FL_WHITE);
    
    sq = new Fl_Input(.025* width, .055*height, .55*width, .05*height, "Card");
    sq->align(FL_ALIGN_TOP);
    
    sr = new Fl_Button(.65*width, .075 *height, .3*width, .07*height, "Search");
    sr->callback((Fl_Callback*)cbSearch);
    
    return gw;
}
