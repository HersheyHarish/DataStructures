/*
Lab 5
Harish Sundarakumar 
The purpose of this assignment is to implement a hash table with the usage of the CURRENCY class from lab 2
*/
#include <iostream>
#include "dollar.h"
#include "currency.h"


class HashTable{
    private:
    Currency *val;
    int s;
    double m,n;
    double whole;
    double frac;
    int insert = 0;
    int collisions = 0;

    public:
    HashTable(int size, double m, double n){
        val = new Currency[size];
        s = size;
        HashTable :: m = m;
        HashTable :: n = n;
    }
    void hashInsert(Currency *curr);
    int hashFind(Currency *curr);
    int getS(){return s;}
    int getCollisions(){return collisions;}
    int getInsert(){return insert;}
    
};

//((m*w +  n*f) % size)
void HashTable :: hashInsert(Currency *curr){
    double tempC = curr->getCoin();
    double tempN = curr->getNote();
    whole = (((tempN * 100 )+ tempC) / 100);
    //std::cout << "Whole" << whole << std::endl;
    frac = whole / 100;
    int z = ((int)m*(int)whole +  (int)n*(int)frac) % s;
   // std::cout << z << std::endl;
    if(val[z].getNote() > 0){
        collisions++;
       // std::cout << "collision detected for:" << whole << std::endl;
           for(int i = 1; i< s; i++){
            if(val[z + (i*i)].getNote() <= 0 ){
               // std::cout << "Putting quadratic at: " << z+(i*i) << std::endl;
                val[z + (i*i)] = Dollar(whole);
                insert++;
                break;
            }else{
                collisions++;
                i++;
            }
           } 
    }else{
        insert++;
        val[z] = Dollar(whole);
    }
    
}

int HashTable :: hashFind(Currency *curr){
    double tempC = curr->getCoin();
    double tempN = curr->getNote();
    whole = (((tempN * 100 )+ tempC) / 100);
    frac = whole / 100;
    
    int z = ((int)m*(int)whole +  (int)n*(int)frac) % s;
    //std::cout << z << std::endl;

    if((val[z].getNote() ==  curr->getNote())) {
        return (int)(m*whole +  n*frac) % s;
    }else{
       // std::cout << "Searching through collisions" << std::endl;
       for(int i = 1; i<s; i++){
        if(val[z + (i*i)].getNote() == curr->getNote()){
            return z + (i*i);
            break;
        }else{
           // std::cout <<val[z + (i*i)].getNote() << ":Z and curr is :" << curr->getNote()  << std::endl;
            i++;
        }
       }
       return -1;
    }
    
}

