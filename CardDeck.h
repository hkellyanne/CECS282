//
//  CardDeck.h
//  wargame
//
//  Created by Kelly Hall on 9/7/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#include<iostream>
#include<string>
#include "Card.h"


using namespace std;

class CardDeck{

public:
    CardDeck();
    void displayCardAt(int);
    void displayAll();
    void deal();
    int cardsLeft();
    void shuffle();
    void WAR();
    int maincard;
    Card Deck[52];
    
  
};


