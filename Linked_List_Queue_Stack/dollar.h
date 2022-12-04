/*
LAB 2
HARISH SUNDARAKUMAR
THE PURPOSE OF THIS ASSIGNMENT IS TO SHOW USAGE OF OBJECTS, POLYMORPHISM, and INHERITANCE
A CURRENCY SIMULATOR
*/
#include <iostream>
#include <iomanip>
#include "currency.h"
#ifndef DOLLAR_H
#define DOLLAR_H

class Dollar : public Currency{
    private:
    std::string dollar = "Dollar";
    
    public:
    Dollar(): Currency(){}
    Dollar(double param): Currency(param){}
    Dollar(Dollar &curr) : Currency(curr){}
	std::string getName() {return dollar;}
	virtual void toString();
};


/* 
Function toString

This OVERWRITTEN function prints out the current object value by using getters as 
well as the dollar string value

Pre: 

Post:


FUNCTION toString()
  print out values using getNote() and getCoin() and getName()
END FUNCTION
*/
void Dollar :: toString(){
  std::cout<<std::setprecision(2);
  std::cout << getNote() << "." << std::fixed <<  getCoin() << " " << getName() << std::endl;
}

#endif