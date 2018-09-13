#include "lab.h"

list<Card> compareSpell(Card inputCard)
{    
    list<Card> spells = getData("Spell", "types");
    list<Card> outList;
    for (list<Card>::iterator it=spells.begin(); it != spells.end(); ++it)
    {
	if ((*it).playerClass == inputCard.playerClass 
	    && (*it).name != inputCard.name){
	    string text = inputCard.text;
	    text.erase(remove(text.begin(), text.end(), ','), text.end());
	    text.erase(remove(text.begin(), text.end(), '.'), text.end());
	    list<string> words = tokenize(text);
    //cout << text << "... ";
    //cout << words.size() << endl;
    
	    for(list<string>::iterator wit=words.begin();wit!=words.end();wit++)
		{
		    if ((*it).text.find(*wit) != string::npos) {
			(*it).fit += 3;
			if( (*wit).find("<b>") != string::npos) (*it).fit += 5;
		    }//cout << *it << " " << fit << endl;
		}
	    (*it).fit -= pow((inputCard.cost - (*it).cost), 2);
	    outList.push_back(*it);
	}
    }
    return outList;
}

list<string> tokenize(string str)
{
    list<string> words;
    istringstream iss(str);
    while (iss)
    {
	string substring;
	iss >> substring;
	words.push_back(substring);
    }
    return words;
}
