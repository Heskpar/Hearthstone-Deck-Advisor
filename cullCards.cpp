#include "lab.h"

list<Card> cullCards(list<Card> cardSet)
{
Card acard = getCard("murloc tinyfin");
Card bcard, ccard;
acard.fit = -1000;
bcard.fit = -1000;
ccard.fit = -1000;
list<Card> topThree;


for (list<Card>::iterator it = cardSet.begin(); it != cardSet.end(); it++){
//cout << (*it).name << " " << (*it).fit <<endl;
    if((*it).fit > acard.fit){
	ccard = bcard;
	bcard = acard;
	acard = *it;
    }
    else if((*it).fit > bcard.fit){
	ccard = bcard;
	bcard = *it;
    }
    else if((*it).fit > ccard.fit)
	ccard = *it;
}

topThree.push_back(acard);
topThree.push_back(bcard);
topThree.push_back(ccard);
return topThree;
}
