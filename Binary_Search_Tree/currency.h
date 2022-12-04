/*
LAB 2
HARISH SUNDARAKUMAR
THE PURPOSE OF THIS ASSIGNMENT IS TO SHOW USAGE OF OBJECTS, POLYMORPHISM, and INHERITANCE
A CURRENCY SIMULATOR
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#ifndef CURRENCY_H
#define CURRENCY_H


class Currency{
    private:
    int currNote,currCoin;
	
    public:
    Currency();
    Currency(double param);
    Currency(const Currency &copy);
    ~Currency(){}

    int getNote() { return currNote; }
    int getCoin() { return currCoin; }
    void add(const double value);
    void subtract(const double value);
	bool isEqual(const double value);	
	bool isGreater(const double value);
    virtual void toString();

};


Currency :: Currency(){
    currNote = 0;
    currCoin = 0;
}

Currency :: Currency(double param){
     if(param < 0){
            std::cout << "Recieved negative value!" << std::endl;
        }else{
            currNote = int(param);
            currCoin = std::round((currNote-param) * -100);
        }
		//std::cout << currNote << "." << currCoin << std::endl; 
}

Currency :: Currency(const Currency &copy){
        currNote = copy.currNote;
        currCoin = copy.currCoin;
}


/* 
Function add(double value)

This function adds given value to the dollar or pound object derived from the Currency class

Pre: double (value) - the amount wanted to be added

Post: NA


FUNCTION add(double value)

    int tempNote
    int tempCoin

    if given value is negative
        print recieved negative value
    else 
        convert double into int and store into tempNote
        subtract tempNote by value, multiply that by -100, and round answer to store into tempCoin
    end if


  currency note is added with the tempNote
  currency cents is added with the tempCoin

    if currency coin exceeds 100,
        take the remainder of currency coin from dividing by 100
        then add 1 to currency note
    end if

END FUNCTION
*/


void Currency :: add(const double value){

    int tempNote,tempCoin;

    if(value < 0){
            std::cout << "Recieved negative value!" << std::endl;
        }else{
            tempNote = int(value);
            tempCoin = std::round((tempNote-value) * -100);
        }
    currNote += tempNote;
    currCoin += tempCoin;

    if(currCoin >= 100){
        currCoin = currCoin % 100;
        currNote++;
    }
}

/* 
Function subtract(double value)

This function subtracts given value to the dollar or pound object derived from the Currency class

Pre: double (value) - the amount wanted to be subtracted
Post: NA


FUNCTION subtract(double value)
    int tempNote
    int tempCoin

    if given value is negative
        print recieved negative value
    else 
        convert double into int and store into tempNote
        subtract tempNote by value, multiply that by -100, and round answer to store into tempCoin
    end if

    if either currency coin - tempCoin or currency note - tempNote is negative
        print cannot subtract
    else
        subtract currency coin by tempCoin
        subtract currency note by tempNote
    end if

END FUNCTION
*/


void Currency :: subtract(const double value){

    int tempNote,tempCoin;

    if(value < 0){
            std::cout << "Recieved negative value!" << std::endl;
        }else{
            tempNote = int(value);
            tempCoin = std::round((tempNote-value) * -100);
        }

        if(isEqual(value) == true){
            currNote = 0;
            currCoin = 0;
        }

        if(isGreater(value) == true){
            currNote -= tempNote;
            currCoin -= tempCoin;
        }else{
            std::cout << "cannot subtract!" << std::endl;
        }

		// if(currNote - tempNote < 0 || currCoin - currNote < 0){
        //     std::cout << "cannot subtract!" << std::endl;
        // }else{
        //     currNote -= tempNote;
        //     currCoin -= tempCoin;
        // }

	}


/* 
Function isEqual(double value)

This function checks if curr class has equivalent value to current object value

Pre:  double (value) - the amount wanted to be subtracted

Post: True or False


FUNCTION isEqual(double value)
    int tempNote
    int tempCoin

    convert value(double) into integer and store into tempNote and tempCoin
        then:

    if the current currency note and coin values are equivalent to tempNote and tempCoin
        return true
    end if

    return false if otherwise

END FUNCTION
*/

bool Currency :: isEqual(double value){

    int tempNote,tempCoin;

    if(value < 0){
        std::cout << "Recieved negative value!" << std::endl;
    }else{
        tempNote = int(value);
        tempCoin = std::round((tempNote-value) * -100);
    }



	if(currNote == tempNote && currCoin == tempCoin){
		return true;
	}
	return false;
}

/* 
Function isGreater(double value)

This function checks if current object value is greater than inputted value

Pre:  double (value) - the amount wanted to be compared 

Post: True or False


FUNCTION isGreater(double value)

    int tempNote
    int tempCoin

    convert value(double) into integer and store into tempNote and tempCoin
        then:

   if the current note value is greater than tempNote value
        return true
    else if (current coin value is greater than  tempCoin value 
    and current note and  tempNote is the same)
        return true
    end if

    return false otherwise

END FUNCTION
*/

bool Currency :: isGreater(const double value){
    int tempNote,tempCoin;

    if(value < 0){
        std::cout << "Recieved negative value!" << std::endl;
    }else{
        tempNote = int(value);
        tempCoin = std::round((tempNote-value) * -100);
    }

	if (currNote > tempNote){
		return true;
	}else if (currCoin > tempCoin && currNote == tempNote){
		return true;
	}
	return false;
}

/* 
Function toString

This function prints out the current object value by using getters

Pre: 

Post:


FUNCTION toString()
  print out values using getNote() and getCoin() 
END FUNCTION
*/

void Currency :: toString(){
  std::cout<<std::setprecision(2);
  std::cout << getNote() << "." << std::fixed << getCoin() << std::endl;
}

 
#endif

