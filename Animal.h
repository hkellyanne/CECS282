//
//  Animal.h
//  Inheritance
//
//  Created by Kelly Hall on 10/24/16.
//  Copyright (c) 2016 Kelly Hall. All rights reserved.
//

#ifndef __Inheritance__Animal__
#define __Inheritance__Animal__

#include <stdio.h>
#include <iostream>
using namespace std;
//Ultimate base class
class Animal{
public:
    //default constructor
    Animal() : Animal("emtpy", "empty", "empty")
    {
        cout << "";
    }
    //overload constructor
    Animal(string movement, string sound, string type){
        this->aptr[0] = movement;
        this->aptr[1] = sound;
        this->aptr[2] = type;
        counter++;
    }
    ~Animal(){
        delete[] aptr;
        counter--;}
    
    static int counter;
    
    static int getCounter(){
        return counter;
    }
    
    
    //pure virtual functions to make Animal Abstract
    virtual string AnimalType()=0;
    virtual void talk()=0;
    virtual void move()=0;
    
    //overload << operator
    friend ostream& operator<<(ostream& os, const Animal& obj){
        string test = obj.aptr[2] + ", " + obj.aptr[0] + ", " + obj.aptr[1];
        cout << test << endl;
        return os;
    };
    
protected:
    string * aptr = new string[3];
    string movement;
    string sound;
    string type;
    
    
};

//base class (general animal) used for an "empty" index of array
class animal : public virtual Animal{
public:
    animal() : Animal("empty", "empty", "empty")
    {
        cout << "";
    }
    
    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}
    
    
    
    
};
    




//base class (Reptile)
class Reptile: public virtual Animal{
public:
    Reptile() : Animal("Reptile Crawl", "Reptile sound", "Reptile")
    {
        cout << "";
    }

    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}

};



//derived classes of Reptile
class Lizard: public Reptile, public virtual Animal{
public:
    Lizard() : Animal("Crawl", "tokay-tokay", "Lizard")
    {
        cout << "";
    }


    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}
    
    
};

class Snake: public Reptile, public virtual Animal{
public:
    Snake() : Animal("Slither", "sssssssss", "Snake")
    {
        cout << "";
    }


    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}
    
    
};




//base class (Bird)
class Bird: public virtual Animal{
public:
    Bird() : Animal("Bird Fly", "Bird chirps", "Bird")
    {
        cout << "";
    }


    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}

};

//derived classes of Bird

class Eagle: public Bird, public virtual Animal{
public:
    Eagle() : Animal("Fly", "Cawwww!", "Eagle")
    {
        cout << "";
    }


    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}
    
    
};

class Chicken: public Bird, public virtual Animal{
public:
    Chicken() : Animal("Waddle", "Bawk!", "Chicken")
    {
        cout << "";
    }


    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}
    
    
};




//base class (Mammal)
class Mammal: public virtual Animal{
public:
    Mammal() : Animal("Mammal Walk", "Mammal sound", "Mammal")
    {
        cout << "";
    }


    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}

};

//derived classes of Mammal
class Bear: public Mammal, public virtual Animal{
public:
    Bear() : Animal("Walk", "Growl", "Bear")
    {
        cout << "";
    }


    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}


};

class Hyena: public Mammal, public virtual Animal{
public:
    Hyena() : Animal("Strut", "Laugh", "Hyena")
    {
        cout << "";
    }


    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}
    
    
};

class Lion: public Mammal, public virtual Animal{
public:
    Lion() : Animal("Prowl", "RAWR", "Lion")
    {
        cout << "";
    }


    string AnimalType(){return aptr[2];}
    void talk(){this->sound = sound;}
    void move(){this->movement = movement;}
    
    
};


#endif /* defined(__Inheritance__Animal__) */
