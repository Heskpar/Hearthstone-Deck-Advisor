#include "lab.h"

list<Card> compareMinions(Card theirCard)
{
    list<Card> cardSet = getData("Minion", "types");
    list<Card> fitList;
    
    for (list<Card>::iterator it=cardSet.begin(); it != cardSet.end(); it++)
    {
	if ( ( (*it).playerClass == theirCard.playerClass ||
		(*it).playerClass == "Neutral" )
	    && (*it).name != theirCard.name)
	    {
	    int x = 0;
	    
	    if ((*it).cost - theirCard.cost > 0)
		x -= 3*((*it).cost - theirCard.cost);
	    else if ((*it).cost - theirCard.cost < 0)
		x += 3*((*it).cost - theirCard.cost);
	    else
		x +=3;
	    
	    if ((*it).attack - theirCard.attack > 0)
		x -= (*it).attack - theirCard.attack;
	    else if ((*it).attack - theirCard.attack < 0)
		x += (*it).attack - theirCard.attack;
	    else
		x +=3;
	    
	    if ((*it).health - theirCard.health > 0)
		x -= 2*((*it).health - theirCard.health);
	    else if ((*it).health - theirCard.health < 0)
		x += 2*((*it).health - theirCard.health);
	    else
		x +=3;	
		
	    (*it).fit = x;
	    fitList.push_front((*it));
	}
    }
	//for(list<Card>::iterator it=fitList.begin();it!=fitList.end();++it);
	//cout<<(*it).name<< " " << (*it).fit << endl;
    return fitList;
}
