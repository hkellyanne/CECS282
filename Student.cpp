//
//  Student.cpp
//  StudentList
//
//  Created by Kelly Hall on 9/27/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#include "Student.h"
#include "myDate.h"
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;

int year;

//randomly generate an ID number between 1000 and 9999
int getID(){
    int ID = rand() % 8999 + 1000;
    return ID;
    
}//end of getID

//randomly generate a number between 50 and 100
int getGrade(){
    int grade = rand() % 50 + 50;
    return grade;
}//end of getGrade

//randomly generate a month between 1 and 12
int randMonth(){
    return rand() % 12 + 1;
}

//randomly generate a day between 1 and 31
int randDay(){
    return rand() % 31 + 1;
}

//randomly generate a year between 1990 and 1994
int randYear(){
    return rand() % 5 + 1990;
}



//generate full birthday as a string
string getBirthday(){
    
    myDate birthday(randMonth(), randDay(), randYear());
    string strmonth;
 
    year = birthday.getYear();
    return birthday.display();

}//end of getBirthday

//calculate Age using birthday
int getAge(){
    int age = 2016 - year;
    return age;

    
}//end of getAge

//methods for sorting array by ID, Name, Age and Grade
bool sortByID(const Student &lhs, const Student &rhs){return lhs.ID < rhs.ID;}
bool sortByAge(const Student &lhs, const Student &rhs){return lhs.age < rhs.age;}
bool sortByName(const Student &lhs, const Student &rhs){return lhs.name[0] < rhs.name[0];}
bool sortByGrade(const Student &lhs, const Student &rhs){return lhs.grade < rhs.grade;}



