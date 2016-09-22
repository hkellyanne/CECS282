//
//  Card.cpp
//  wargame
//
//  Created by Kelly Hall on 9/7/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#include "Card.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include <array>


using namespace std;

Card::Card(){
    char s;
    int r = 0;
    
}
Card::Card(char s, int r){
     suit = s;
     rank = r;

}



void Card::displayCard(){
    switch(rank){
        case 2:
            cout << "2";
            break;
        case 3:
            cout << "3";
            break;
        case 4:
            cout << "4";
            break;
        case 5:
            cout << "5";
            break;
        case 6:
            cout << "6";
            break;
        case 7:
            cout << "7";
            break;
        case 8:
            cout << "8";
            break;
        case 9:
            cout << "9";
            break;
        case 10:
            cout << "10";
            break;
        case 11:
            cout << "Jack";
            break;
        case 12:
            cout << "Queen";
            break;
        case 13:
            cout << "King";
            break;
        case 14:
            cout << "Ace";
            break;
    }
    
    cout << " of ";
    switch (suit){
        case 'S': cout << "Spades" << endl;
            break;
        case 'H': cout << "Hearts" << endl;
            break;
        case 'D': cout << "Diamonds" << endl;
            break;
        case 'C': cout << "Clubs" << endl;
            break;

            
    }
}

int Card::getValue(){
    return rank;
}
