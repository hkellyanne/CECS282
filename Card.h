//
//  Card.h
//  wargame
//
//  Created by Kelly Hall on 9/7/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//
#pragma once
#ifndef _Card_H
#define _Card_H
#include <iostream>
#include <string>

using namespace std;

class Card
{

    
public:
    Card();
    Card(char s, int r);
    int getValue();
    void displayCard();
    
    

    char suit;
    int rank;
    
    
};

#endif
