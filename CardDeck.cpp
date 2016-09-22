//
//  CardDeck.cpp
//  wargame
//
//  Created by Kelly Hall on 9/7/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#include "CardDeck.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]){
    CardDeck newGame = CardDeck();

    bool endgame = false;
    //prompt user with menu
    cout << "1) Get a new card deck" << endl;
    cout << "2) Show all cards in the deck" << endl;
    cout << "3) Shuffle" << endl;
    cout << "4) Play WAR!" << endl;
    cout << "5) Exit" << endl;
    
    //while the game is not over
    while(!endgame){
        char choice;
        
        cin >> choice;
        while (choice == '1'){ //choice 1 makes a new deck
            cout << "New deck is made" << endl;
            cin >> choice;
        }
        while (choice == '2'){ // choice 2 displays all cards in the deck
            newGame.displayAll();
            cin >> choice;
        }
        while(choice == '3'){ //choice 3 shuffles the deck
            
            newGame.shuffle();
            newGame.displayAll();
            cout << "The deck is shuffled" << endl;
            
            cin >> choice;
        }
        while(choice == '4'){ //choice 4 starts a game of WAR
            newGame.WAR();
            cin >> choice;
            while (tolower(choice) == 'y'){
                newGame.WAR();
                cin >> choice;
                
            }
            if(tolower(choice) == 'n'){endgame = true;}
            cin >> choice;
        }
        if (choice == '5'){//choice 5 exits the program
            cout << "goodbye" << endl;
            endgame = true;
        }
        
        
        
    }//end of while
}//end of main

    


CardDeck::CardDeck(){

    maincard = 51;
    int x = 0;
    int rank[] = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    char suit[] = {'H', 'D', 'C', 'S'};

    //initialize deck
    for (int r=0; r < 13; r++){
        for(int s = 0; s<4; s++){
            Deck[x].rank = rank[r];
            Deck[x].suit = suit[s];
            x++;
        }
    }
}//end of CardDeck::CardDeck

void CardDeck::displayAll(){ //displays all cards in the deck
    for (int a = 0; a < maincard; a++){
        Deck[a].displayCard();
    }
}

void CardDeck::deal(){ //deals out cards
        Deck[maincard].displayCard();
        maincard--;
}

void CardDeck::displayCardAt(int index){ //displays card at specific location
    Deck[index].displayCard();
   
}

void CardDeck::shuffle(){ //shuffles deck
    random_shuffle(&Deck[0], &Deck[maincard]);
    
}

void CardDeck::WAR(){ //main war program
    int player = 0;
    int player2 = 0;
    int comp = 0;
    int comp2 = 0;
    int playerscore = 0;
    int compscore = 0;
    int main = 0;
    
    cout << "Get ready to play two-card WAR!!!" << endl;
    cout << "There are 52 cards in the deck." << endl;
    cout << "...dealing..." << endl;
    cout << "One for me..." << endl;
    deal();
    comp = Deck[maincard].getValue();
    cout << "One for you..." << endl;
    deal();
    player = Deck[maincard].getValue();
    cout << "Two for me..." << endl;
    deal();
    comp2 = Deck[maincard].getValue();
    cout << "Two for you..." << endl;
    deal();
    player2 = Deck[maincard].getValue();
    //calculates scores
    playerscore = player + player2;
    compscore = comp + comp2;
    
    cout << "You have " << playerscore << " points" << endl;
    cout << "I have " << compscore << " points" << endl;
    //determines who wins, loses or ties
    if (compscore > playerscore) { cout << "In your face! - I win!" << endl;}
    else if (compscore < playerscore){ cout << "You win" << endl;}
    else if ( compscore == playerscore) {cout << "Tie game - I challenge you again." << endl;}

    cout << "There are " << (maincard + 1) << " cards in the deck." << endl;
    if(maincard == 0){ cout << "GAME OVER - There are no more cards in the deck" << endl;
        exit(0);}
    cout << "Wanna play again? (Y/N)" << endl;
} //end of WAR
