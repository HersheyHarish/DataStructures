/*
LAB 4
HARISH SUNDARAKUMAR
THE PURPOSE OF THIS ASSIGNMENT IS TO IMPLEMENT A BINARY SEARCH TREE WITH USAGE OF THE CURRENCY CLASS IN LAB 2
*/
#include <iostream>
#include <fstream>
#include "dollar.h"
#include "BSTNode.h"
#ifndef BST_H
#define BST_H

class BST
{
private:
     
public:
    BSTNode* root;
    BST(){ 
        root = NULL;
    };
    BSTNode* getRoot(){return root;}
    void setRoot(BSTNode* x){this->root = x;}
    void insert (BSTNode* x);
    void del (Currency *val);
    bool search(Currency *val);
    bool isEmpty();
    int count(BSTNode* root);
    std::string printNode(BSTNode*x);
    void breadthFirst(BSTNode* root, std::fstream &outPut);
    void printCurrLevel(BSTNode* root, int level, std::fstream &outPut);
    int height(BSTNode* node);
    void inorder(BSTNode* root, std::fstream &outPut);
    void preOrder(BSTNode* root, std::fstream &outPut);
    void postOrder(BSTNode* root, std::fstream &outPut);
    BST(Currency val);
    ~BST();
};



/* 
Function breadthFirst(BSTNode* root, file )
This function prints the binary tree based on level order

Pre: BSTNode (root)
     File to be written on

Post: NA

FUNCTION breadthFirst(BSTNode* root, file )
    integer h contains the height(starting from root)
    set i equal to one
    for(i is less than or equal to height)
        call printCurrLevel function and pass BSTNode, int i , and the file as parameters
    end for

END FUNCTION
*/

void BST :: breadthFirst(BSTNode* root, std::fstream &outPut){
    int h = height(root);
    for(int i = 1; i<= h; i++){
        printCurrLevel(root,i, outPut);
    }
}

/* 
Function  printCurrLevel(BSTNode* curr, int level, file)
This function prints the binary tree level based on height parameter

Pre: BSTNode (curr)
     level : height which is to be printed
     File to be written on

Post: NA

FUNCTION printCurrLevel(BSTNode* curr, int level, file){
    if curr is NULL
        return
    end if

    if int level is equivalent to 1
        print node value
    else if( int level is greater than one)
        recursively call printCurrLevel and pass:
            curr's left pointer, int level - 1, and file

        recursively call printCurrLevel and pass:
            curr's right pointer, int level - 1, and file
    end if

END FUNCTION
*/

void BST:: printCurrLevel(BSTNode* curr, int level, std::fstream &outPut){
    if(curr == NULL){
        return;
    }
    if(level == 1){
        std::cout << printNode(curr) << " ";
        outPut << printNode(curr) << " ";
    }else if (level > 1){
        printCurrLevel(curr->left, level-1, outPut);
        printCurrLevel(curr->right, level-1, outPut);
    }
}

/* 
Function height(BSTNode* node)
This function finds the height of the binary search tree

Pre: BSTNode 
   

Post: int height

FUNCTION height(BSTNode* node)
   if node is null, return
   else
    create 2 integers, left and right
    set left to recursively call height with parameters being node->left
    set right to recursively call height with parameters being node->right

    

    if (left is greater than right)
        return int left +1
    else return int right +1

    end if
end if

END FUNCTION
*/

int BST::  height(BSTNode* node){
    if(node == NULL){
        return 0;
    }else{
        int l = height(node->left);
        int r = height(node->right);

        if(l > r){
            return(l+1);
        }else{
            return(r+1);
        }
    }
}


/* 
Function isEmpty()
This function checks if the Binary search tree is empty

Pre:
   

Post: 

FUNCTION isEmpty()
   if node is null, return true
   else return false
   end if

END FUNCTION
*/

bool BST :: isEmpty(){
    if(root == NULL){
        return true;
    }
    return false;
}

/* 
Function insert(BSTNode x)
This function inserts a node in the binary search tree

Pre: BSTNode - wanted to be added to tree
   
Post: NA

FUNCTION insert(BSTNode x)
   if the node is null 
        return
    else
        create a new BSTNode curr, and assign to root
        while(curr is not NULL)
            if(curr's data value is greater than x's data value)
                if(curr's left pointer is NULL)
                    assign curr's left pointer to x
                    set curr equal to NULL
                else
                    assign curr to curr's left pointer
                end if
            else if (curr's data value is less than x's data value)
                if(curr's right pointer is NUll)
                    assign curr's right pointer to x
                    set curr to NULL
                else
                    assign curr to curr's right pointer
                end if
            end if
        end while
    end if
            
END FUNCTION
*/


void BST :: insert(BSTNode* x){
    if(root == NULL){
        root = x;
    }else{
        BSTNode* curr = root;
        while(curr != NULL){
            if(x->data->getNote() < curr->data->getNote()){
                if(curr->left == NULL){
                    curr->left = x;
                    curr = NULL;
                }
                else {
                    curr = curr->left;
                }
            }else{
                if(curr->right == NULL){
                    curr->right = x;
                    curr = NULL;
                }else{
                    curr = curr->right;
                }
            }
        }
    }
}

/* 
Function del(Currency val)
This function deletes a node in the binary search tree

Pre: Currency val - value that wants to be deleted in tree
   
Post: NA

FUNCTION del(Currency val)

    create 2 BSTNodes, par and curr, and assign to NULL and root respectively
   
    while curr is NOT NULL
        if(currs value is equal to Currency val's value)
            if(both curr pointers are NULL)
                if par is NULL
                    set root to NULL
                else if par's left pointer is equal to curr
                    set par's left pointer to NULL
                else
                    set par's right pointer to NULL
                end if
            
            else if (curr has a left child (curr's right pointer is NULL))
                if par is NUll
                    set root to curr's left pointer
                else if par's left pointer is equal to curr
                    set par's left pointer to curr's left pointer
                else 
                    set par's right pointer to currs left pointer
                end if
            
            else if (curr has a right child)
                 if par is NUll
                    set root to curr's right pointer
                else if par's left pointer is equal to curr
                    set par's left pointer to curr's right pointer
                else 
                    set par's right pointer to currs right pointer
                end if
            
            else(if curr has 2 children)
                create a new BSTNode succ and assign to curr's right pointer
                while succ's left pointer is NOT NULL
                    iterate through the tree, going towards the left
                end while

                create a copy of succ and delete succ by recursively calling del function
                assign currs data to copy data
            end if
        end if

    end while 
        print "could not find"
   
END FUNCTION
*/

void BST :: del(Currency *val){
    BSTNode *par = NULL;
    BSTNode *curr = root;
    while(curr != NULL){
        if(curr->data->getNote() == val->getNote()){
            if(curr->left == NULL && curr->right == NULL){
                if(par == NULL){
                    root = NULL;
                }else if(par->left == curr){
                    par->left = NULL;
                }else{
                    par->right = NULL;
                }
            }
            //Wiht one  left child
            else if(curr->right == NULL){
                if(par == NULL){
                    root = curr->left;
                }else if(par->left == curr){
                    par->left = curr->left;
                }else{
                    par->right = curr->left;
                }
            //WITH ONE RIGHT CHILD
            }else if(curr->left == NULL){
                if(par == NULL){
                    root = curr->right;
                }else if (par->left == curr){
                    par->left = curr->right;
                }else{
                    par->right = curr->right;
                }
            //IF HAS 2 CHILDREN
            }else{
                BSTNode *succ = curr->right;
                while(succ->left != NULL){
                    succ = succ->left;
                }
                BSTNode *copy = succ;
                del(succ->data);
                curr->data = copy->data;
            }
            return;
        }else if(curr->data->getNote() < val->getNote()){
            par = curr;
            curr = curr->right;
        }else{
            par = curr;
            curr = curr->left;
        }
    }
    std::cout << "Could not find node" << std::endl;
}



/* 
Function search(Currency val)
This function searches for currency value in binary search tree

Pre: Currency val - data that wants to be found
   

Post: BOOLEAN (True or False)

FUNCTION search(Currency val)
  create a BSTNode curr and assign to root
  while curr is not null
    if curr's data is equal to val
        return true
    else if (val is less than curr)
        set curr to currs left pointer
    else
        set curr to currs right pointer
    end if
end while

return false

END FUNCTION
*/

bool BST::search(Currency *val){
    BSTNode *curr = root;
    while(curr != NULL){
        if(curr->data->getNote() == val->getNote()){
            return true;
        }else if(val->getNote() < curr->data->getNote()){
            curr= curr->left;
        }else{
            curr = curr->right;
        }
    }
    return false;
}

/* 
Function printNode(BSTNode x)
This function prints the given node

Pre: BSTNode x
   

Post: String

FUNCTION printNode(BSTNode x)
    create 3 strings
    string one contains dollar note
    string two contains dollar coin
    string three contains the character "."
    return string(1+2+3)
END FUNCTION
*/
std::string BST:: printNode(BSTNode*x){
    std::string tempNote = std::to_string(x->data->getNote());
    std::string tempCoin = std::to_string(x->data->getCoin());
    std::string c = ".";
    return tempNote+c+tempCoin;
}

/* 
Function inorder(BSTNode root, file)
This function prints the binary search tree in order

Pre: BSTNode x
     file
   

Post: NA

FUNCTION inorder(BSTNode root, file)
    if root is null, return
    else 
        recursively call inorder and pass parameters root's left pointer and file
        print the node value
        recursively call inorder and pass parameters root's right pointer and file
    end if
 
END FUNCTION
*/


void BST::inorder(BSTNode* root, std::fstream &outPut){
    if (root == NULL){
        return;
    }else{
        inorder(root->left, outPut);
        std::cout << root->data->getNote() << "." << root->data->getCoin() << " ";
        outPut << root->data->getNote() << "." << root->data->getCoin() << " ";
        inorder(root->right, outPut);
    }
}

/* 
Function preOrder(BSTNode root, file)
This function prints the binary search tree in pre order

Pre: BSTNode x
     file
   

Post: NA

FUNCTION preOrder(BSTNode root, file)
    if root is null, return
    else 
        print the node value
        recursively call preOrder and pass parameters root's left pointer and file
        recursively call preOrder and pass parameters root's right pointer and file
    end if
 
END FUNCTION
*/


void BST::preOrder(BSTNode* root,  std::fstream &outPut){
    if (root != NULL){
        std::cout << root->data->getNote() << "." << root->data->getCoin() << " ";
        outPut << root->data->getNote() << "." << root->data->getCoin() << " ";
        preOrder(root->left, outPut);
        preOrder(root->right, outPut);
    }
}

/* 
Function postOrder(BSTNode root, file)
This function prints the binary search tree in post order

Pre: BSTNode x
     file
   

Post: NA

FUNCTION postOrder(BSTNode root, file)
    if root is null, return
    else 
        recursively call postOrder and pass parameters root's left pointer and file
        recursively call postOrder and pass parameters root's right pointer and file
        print the node value
    end if
 
END FUNCTION
*/

void BST::postOrder(BSTNode* root, std::fstream &outPut){
    if(root != NULL){
        preOrder(root->left, outPut);
        preOrder(root->right, outPut);
        std::cout << root->data->getNote() << "." << root->data->getCoin() << " ";
        outPut << root->data->getNote() << "." << root->data->getCoin() << " ";
    }
}

/* 
Function count(BSTNode root)
This function finds the total value of nodes in the binary search tree

Pre: BSTNode root
   
   

Post: int

FUNCTION count(BSTNode root)
    if root is NULL 
        return 0
    end if

    set a int i to 0

    if(root left pointer and right pointer is NOT NULL)
        increment i
        recursively call count TWICE and use parameters root left pointer and right pointer
                add the value returned together
        add this value to i
    end if

    return i

 
END FUNCTION
*/


int BST:: count(BSTNode* root){
  if (root == NULL){
    return 0;
  }

  int c=0;
    if(root->left && root->right){
        c++;
        c+= (count(root->left)+ count(root->right));
    }
    return c;

}

BST::~BST()
{
}


#endif