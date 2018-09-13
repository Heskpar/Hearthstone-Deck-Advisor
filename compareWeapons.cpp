#include "lab.h"

list<Card> compareWeapons(Card theirCard)
{
    list<Card> data = getData("Weapon", "types");
    list<Card> fitList;
    for (list<Card>::iterator it=data.begin(); it != data.end(); it++)
    {	
	//cout << (*it).name << " " << (*it).playerClass << endl;
	if ( (*it).playerClass == theirCard.playerClass 
	    && (*it).name != theirCard.name)
	{
	    if ((*it).cost - theirCard.cost > 0)
		(*it).fit -=  2*pow((*it).cost - theirCard.cost, 2);
	    else if ((*it).cost - theirCard.cost < 0)
		(*it).fit -= pow((*it).cost - theirCard.cost, 2);
	    else
		(*it).fit +=3;

	    if ((*it).attack - theirCard.attack > 0)
		(*it).fit += (*it).attack - theirCard.attack;
	    else
		(*it).fit += 2 * ((*it).attack - theirCard.attack);
	
	    if ((*it).durability - theirCard.durability > 0)
		(*it).fit += 2 * ((*it).durability - theirCard.durability);
	    else
		(*it).fit += 3 * ((*it).durability - theirCard.durability);
	    
	    fitList.push_back((*it));
	}
	}for(list<Card>::iterator it=fitList.begin();it!=fitList.end();++it)
	//cout << (*it).name << " " << (*it).playerClass <<" "<< (*it).fit << endl;
    return fitList;
}
