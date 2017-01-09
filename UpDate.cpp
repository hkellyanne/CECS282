//
//  UpDate.cpp
//  Proj4_OpOverload
//
//  Created by Kelly Hall on 10/11/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#include "UpDate.h"
#include <iostream>
#include <cstdio>
#include <utility>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

//default constructor
UpDate::UpDate(){
    this->Date[0] = 5;
    this->Date[1] = 11;
    this->Date[2] = 1959;
}
//overload constructor
UpDate::UpDate(int M, int D, int Y){
    this->Date[0] = M;
    this->Date[1] = D;
    this->Date[2] = Y;
    counter++;
    
    //check if date has a valid month and day
    if (this->Date[0] < 1 || this->Date[0] > 12 || this->Date[1] < 1 || this->Date[1] > 31){
        this->Date[0] = 5;
        this->Date[1] = 11;
        this->Date[2] = 1959;
    }
    //check if date has valid day for the month of 2,4,5,9,11
    else if ( (this->Date[1]==31) && (this->Date[0]==2 || this->Date[0]==4 || this->Date[0]==6 || this->Date[0]==9 || this->Date[0]==11) ){
        this->Date[0] = 5;
        this->Date[1] = 11;
        this->Date[2] = 1959;
    }
    //check if date has a valid day for the month 2
    else if ( (this->Date[1]==30) && (this->Date[0]==2) ){
        this->Date[0] = 5;
        this->Date[1] = 11;
        this->Date[2] = 1959;
    }
    
    //check if month is 2, day is 29 and year can be divided by 4 (leap year)
    else if ( (this->Date[0]==2) && (this->Date[1]==29) && ((this->Date[2]%4) != 0) ){
        this->Date[0] = 5;
        this->Date[1] = 11;
        this->Date[2] = 1959;
    }
    
    
    
}

//destructor
UpDate::~UpDate(){
    delete[] Date;
}

//acts like a constructor
void UpDate::setDate(int M, int D, int Y){
    this->Date[0] = M;
    this->Date[1] = D;
    this->Date[2] = Y;

}

//return month in  int
int UpDate::getMonth(){
    return Date[0];
    
}

//return day of the month
int UpDate::getDay(){
    return Date[1];
}

//return year
int UpDate::getYear(){
    return Date[2];
}

//return month name
string UpDate::getMonthName(){
    string MONTH;
    switch (Date[0]){
                case 1:
                    MONTH = "January ";
                    break;
                case 2:
                    MONTH = "Feburary ";
                    break;
                case 3:
                    MONTH = "March ";
                    break;
                case 4:
                    MONTH = "April ";
                    break;
                case 5:
                    MONTH = "May ";
                    break;
                case 6:
                    MONTH = "June ";
                    break;
                case 7:
                    MONTH = "July ";
                    break;
                case 8:
                    MONTH = "August ";
                    break;
                case 9:
                    MONTH = "September ";
                    break;
                case 10:
                    MONTH = "October ";
                    break;
                case 11:
                    MONTH = "November ";
                    break;
                case 12:
                    MONTH = "December ";
                    break;
            }

    return MONTH;
}//end of getMonthName

//count how many objects of UpDate exist
int UpDate::getDateCount(){
    return counter;
}

//computes Julian Date from Gregorian
int UpDate::toJulian(int *JD, int M, int D, int Y){
    int I = Y;
    int J = M;
    int K = D;
    
    *JD = K - 32075 + 1461 * (I + 4800 +(J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
    
    return *JD;
    
}

//computes Gregorian Date from Julian
void UpDate::toGregorian(int JD, int *M, int *D, int *Y){
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
    
    return;
    
    
}


//computes Julian date from Gregorian (without parameters)
int UpDate::Julian(){
    int I = Date[2];
    int J = Date[0];
    int K = Date[1];
    
    JD = K - 32075 + 1461 * (I + 4800 +(J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
    
    return JD;
    
}

//copy constructor
UpDate::UpDate(const UpDate &other){
    Date = new int[3];
    memcpy(Date, other.Date, sizeof(int) * 3);
    
}


//assignment operator
UpDate& UpDate::operator=(const UpDate& other){
    //check for self assignment
    if (this != &other){
    Date[0] = other.Date[0];
    Date[1] = other.Date[1];
    Date[2] = other.Date[2];
    }
    return *this;
}


//operator overload :increment
UpDate& UpDate::operator++(){
    return *this;
}

UpDate UpDate::operator++(int){
    UpDate tmp(*this);
    operator++();
    return tmp;
}

//operator overload : decrement
UpDate& UpDate::operator--(){
    return *this;
}

UpDate UpDate::operator--(int){
    UpDate tmp(*this);
    operator--();
    return tmp;
}


//operator overload assignments
UpDate& UpDate::operator+=(const UpDate &other){
    //*this += other;
    return *this;
}
UpDate& UpDate::operator-=(const UpDate &other){
    *this -= other;
    return *this;
}



//adding an int (obj + int)
const UpDate UpDate::operator+(int days) const{
    UpDate temp(*this);
    

    int A = days/360;
    int B = A/12;
    double C = B/31;
    
    temp.Date[0] = temp.Date[0] + B;
    temp.Date[1] = temp.Date[1] + C;
    temp.Date[2] = temp.Date[2] + A;
    
    return temp;
}
//subtracting an int (obj - int)
const UpDate UpDate::operator-(int days) const{
    UpDate temp(*this);
    
    int A = days/360;
    int B = A/13;
    int C = B/31;
    
    temp.Date[0] = temp.Date[0] - B;
    temp.Date[1] = temp.Date[1] - C + 1;
    temp.Date[2] = temp.Date[2] - A;
    
    return temp;
}



//adding and subj (int + obj)
UpDate operator+(int d1, const UpDate& d2){
    return UpDate(d2 + d1);
    
}
//adding and subj (int - obj)
UpDate operator-(int d1, const UpDate& d2 ){
    return UpDate(d2 - d1);
}


//adding and subj objects
int operator+(const UpDate &d1, const UpDate &d2){
    return UpDate(d1).Julian() + UpDate(d2).Julian();
    
    
}
int operator-(const UpDate &d1, const UpDate &d2){
    return UpDate(d1).Julian() - UpDate(d2).Julian();
}


//operator overload : <<
ostream& operator<<(ostream& os, const UpDate& obj){
    string test = to_string(obj.Date[0]) + "/" + to_string(obj.Date[1]) + "/" + to_string(obj.Date[2]);
    cout << test << endl;
    return os;
}





//relational bool operators
bool operator == (const UpDate &d1, const UpDate &d2){
    if((d1.Date[0] == d2.Date[0]) && (d1.Date[1] == d2.Date[1]) && (d1.Date[2] == d2.Date[2])){
        return true;
    }
    else{return false;}
}

bool operator != (const UpDate &d1, const UpDate &d2){
    return ! (d1 == d2);
}

bool operator < (const UpDate &d1, const UpDate &d2){
    if(d1.Date[2] < d2.Date[2]){
        return true;
    }
    else {return false;}
}

bool operator > (const UpDate &d1, const UpDate &d2){
    if(d1.Date[2] > d2.Date[2]){
        return true;
    }
    else {return false;}
}





