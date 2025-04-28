#pragma once


#include <vector>
#include <string>
#include "Card.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;


class Deck {
public:
    Card* cards[52];
    int currentCard = 0;
Deck() 
{
        string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        int i = 0;
        for (const auto& suit : suits) {
            for (const auto& rank : ranks) {
                cards[i++] = new Card(rank, suit);
            }
        }
        shuffle();
    }
    //function of shuffling
    void shuffle() {
        for (int i = 0; i < 52; i++) {
            int j = rand() % (52 - i) + i;  // Random index
            swap(cards[i], cards[j]);
        }
    }

    Card* dealCard() {
        if (currentCard < 52) {
            return cards[currentCard++];
        } else {
            return nullptr;
        }
    }
};