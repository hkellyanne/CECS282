//
//  myDate.h
//  assign2_ADT
//
//  Created by Kelly Hall on 9/14/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#ifndef __assign2_ADT__myDate__
#define __assign2_ADT__myDate__

#include <stdio.h>
#include <ctime>
#include <iostream>
#include <tuple>

using namespace std;

class myDate{

public:
    myDate();
    myDate(int M, int D, int Y);
    void display();
    void incrDate(int N);
    void decrDate(int N);
    int daysBetween(myDate Date);
    int getMonth();
    int getDay();
    int getYear();
    int getYearOffset();
    
private:
    int dayoffset;
    int yearoffset;
    int M = 5;
    int D = 11;
    int Y = 1959;
    int JD;
    int toJulian(int *JD, int M, int D, int Y);
    tuple<int, int, int> toGregorian(int JD, int *M, int *D, int *Y);

};

#endif /* defined(__assign2_ADT__myDate__) */
