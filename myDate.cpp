//
//  myDate.cpp
//  assign2_ADT
//
//  Created by Kelly Hall on 9/14/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#include "myDate.h"
#include <ctime>
using namespace std;


//default constructor
myDate::myDate(){
    
}

myDate::myDate(int M, int D, int Y){
    this->M = M;
    this->D = D;
    this->Y = Y;
    
    
    int testJ = toJulian(&JD, M, D, Y);
    auto test = toGregorian(testJ, &M, &D, &Y);
    int testM = get< 0>(test);
    int testD = get< 1>(test);
    int testY = get< 2>(test);
    cout << M << " " << D << " " << Y << endl;
    cout << testM << " " << testD << " " << testY << endl;
    cout << toJulian(&JD, M, D, Y) << endl;
    cout<< toJulian(&JD, testM, testD, testY) << endl;
    
    if (toJulian(&JD, M, D, Y) != toJulian(&JD, testM, testD, testY)){
        this->M = 5;
        this->D = 11;
        this->Y = 1959;
    }


    
}

//computes Julian date from Gregorian
int myDate::toJulian(int *JD, int M, int D, int Y){
    int I = Y;
    int J = M;
    int K = D;
    
    *JD = K - 32075 + 1461 * (I + 4800 +(J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
    
    return *JD;
    
}

//computes Gregorian Date from Julian
tuple<int,int,int> myDate::toGregorian(int JD, int *M, int *D, int *Y){
    int I;
    int J;
    int K;
    int L;
    int N;
    
    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N - 49) + I + L;
    
    *Y = I;
    *M = J;
    *D = K;
    
    return make_tuple(*M, *D, *Y);
    
    
}

//display date in formate month day, year.
void myDate::display(){
    switch (M){
        case 1:
            cout << "January ";
            break;
        case 2:
            cout << "Feburary ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case 8:
            cout << "August ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << "October ";
            break;
        case 11:
            cout << "November ";
            break;
        case 12:
            cout << "December ";
            break;
    }
    
    cout << D << ", " << Y << endl;
    
   
    
}// end of display

//increment the date by N days
void myDate::incrDate(int N){
    
    int A = N/360;
    int B = A/12;
    int C = B/30;

    M = M + B;
    D = D + C;
    Y = Y + A;
    
}

//decrement the date by N days
void myDate::decrDate(int N){
    int A = N/365;
    int B = A/12;
    int C = B/30;
    
    M = M - B;
    D = D - C;
    Y = Y - A;
    

    
}

//return number of days between this date and date D
int myDate::daysBetween(myDate Date){
    int current = toJulian(&JD, M, D, Y);
    int date = toJulian(&JD, Date.getMonth(), Date.getDay(), Date.getYear());

    int dayoffset = current - date;
    
    if (dayoffset < 0){
        dayoffset = dayoffset * -1;
    }
    return dayoffset;
}

//return month in  int
int myDate::getMonth(){
    return M;
    
}

//return day of the month
int myDate::getDay(){
    return D;
}

//return year
int myDate::getYear(){
    return Y;
}

//return number of days since the current year began
int myDate::getYearOffset(){
    int current = toJulian(&JD, M, D, Y);
    int date = toJulian(&JD, 1, 1, Y);
    int yearoffset = current - date;
    
    return yearoffset;
}
