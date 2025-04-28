
#ifndef CARD_H      
#define CARD_H      



#include <iostream>
#include <string>
using namespace std;

class Card{
    public:
    string rank;
    string suit;
    bool isFaceup;
    
    Card(string rank, string suit):rank(rank), suit(suit), isFaceup(false) {}
    string ToString() const{
        if(isFaceup)
        {
            return rank + "of" + suit;
        }
        else{
            return "XXX";
        }
    }
};


#endif