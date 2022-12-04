/*
LAB 4
HARISH SUNDARAKUMAR
THE PURPOSE OF THIS ASSIGNMENT IS TO IMPLEMENT A BINARY SEARCH TREE WITH USAGE OF THE CURRENCY CLASS IN LAB 2
*/


#include <iostream>
#include "currency.h"
#ifndef BSTNode_H
#define BSTNode_H

class BSTNode{
    public:
    
    BSTNode(Currency *curr){
        data = curr;
        right = NULL;
        left = NULL; 
    }
    Currency *data;
    BSTNode* left;
    BSTNode* right;
};




#endif