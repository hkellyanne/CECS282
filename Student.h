//
//  Student.h
//  StudentList
//
//  Created by Kelly Hall on 9/27/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#ifndef __StudentList__Student__
#define __StudentList__Student__
#include "myDate.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

struct Student{
    int ID;
    char name[20];
    string birthday;
    int age;
    int grade;
};

int getID();
int getAge();
string getBirthday();
int getGrade();
int randMonth();
int randDay();
int randYear();
bool sortByID(const Student &lhs, const Student &rhs);
bool sortByAge(const Student &lhs, const Student &rhs);
bool sortByName(const Student &lhs, const Student &rhs);
bool sortByGrade(const Student &lhs, const Student &rhs);


#endif /* defined(__StudentList__Student__) */
