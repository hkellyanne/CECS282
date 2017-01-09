//
//  UpDate.h
//  Proj4_OpOverload
//
//  Created by Kelly Hall on 10/11/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#ifndef __Proj4_OpOverload__UpDate__
#define __Proj4_OpOverload__UpDate__

#include <stdio.h>
#include <iostream>
#include <new>

using namespace std;

class UpDate{
    
public:
    //default constructor
    UpDate();
    //overload Constructor
    UpDate(int M, int D, int Y);
    //deallocate memory stored in UpDate
    ~UpDate();
    //create new Date
    void setDate(int M, int D, int Y);
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();
    static int getDateCount();
    int Julian();
    
    UpDate(const UpDate &other); //copy constructor
    
    UpDate& operator=(const UpDate& other);//assignment operator
    
    //overload increment operator
    UpDate& operator++();
    UpDate operator++(int);
    
    //overload decrement operator
    UpDate& operator--();
    UpDate operator--(int);
    
    UpDate& operator+=(const UpDate &other);
    UpDate& operator-=(const UpDate &other);
    
    //adding and subtracting int for obj + int
    const UpDate operator+(int days) const;
    const UpDate operator-(int days) const;
    
    //adding and subtracting int for int + obj
    friend UpDate operator+ (int d1, const UpDate& d2);
    friend UpDate operator- (int d1, const UpDate& d2);
    
    //adding and subtracting objects
    friend int operator+ (const UpDate& d1, const UpDate& d2);
    friend int operator- (const UpDate& d1, const UpDate& d2);
    
    //overload cout function
    friend ostream& operator<<(ostream& os, const UpDate& obj);
        
    //relational operators
    friend bool operator == (const UpDate &d1, const UpDate &d2);
    friend bool operator > (const UpDate &d1, const UpDate &d2);
    friend bool operator < (const UpDate &d1, const UpDate &d2);
    friend bool operator != (const UpDate &d1, const UpDate &d2);
    
    static int counter;
    
    
private:
    int * Date = new int [3];
    int JD;
    int toJulian(int *JD, int M, int D, int Y);
    void toGregorian(int JD, int *M, int *D, int *Y);

};




#endif /* defined(__Proj4_OpOverload__UpDate__) */
