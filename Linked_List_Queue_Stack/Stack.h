/*
LAB 3
HARISH SUNDARAKUMAR
THE PURPOSE OF THIS ASSIGNMENT IS TO IMPLEMENT A SINGLY-LINKED LIST, A STACK, AND A QUEUE
WITH THE USAGE OF THE CURRENCY CLASS CREATED IN LAB 2
*/
#include <iostream>
#include "SinglyLinkedList.h"
#ifndef STACK_H
#define STACK_H

class Stack : private SinglyLinkedList{
    public:
    Stack(){
        LinkNode *temp = new LinkNode();
        temp->next = NULL;
        setStart(temp->next);
        setEnd(temp->next);
    }
    void push(Currency *curr);
    Currency pop();
    Currency peek();
    std::string printStack();
};

/* 
Function push(Currency Object)

This function adds a Currency data type to the end of the linked list

Pre:Currency object - 

Post: NA

FUNCTION push(Currency Object)
    Create a temporary Node that contains the Currency data value
    Create another Node that is assigned to start of the list called TRAVERSE
    Assign temporary Node to NULL as it will be added as the tail

    if the List is empty
        print the list is empty
    else
        while(Traverse -> next pointer is not NULL)
            iterate through the list
        end while
        assign traverse-> next pointer to temp node
    end if 

END FUNCTION
*/


void Stack :: push(Currency *curr){
    LinkNode *temp = new LinkNode();
    temp->data = curr;
    if(getStart() == NULL){
        temp->next = NULL;
        setStart(temp);
    }else{
        temp->next = getStart();
        setStart(temp);
    }  
}

/* 
Function pop()

This function deletes a Currency data type to the start of the stack

Pre:NA

Post: currency object

FUNCTION pop()
   create a temp node and assign to start

   if(start of stack is NULL)
        print(stack is empty)
    else
        assign start to temp's next pointer
        return temp's data value
END FUNCTION
*/

Currency Stack :: pop(){
    LinkNode *p = getStart();
    if(getStart() == NULL){
        std::cout << "Stack is empty" << std::endl;
    }else{
        setStart(p->next);
        return *p->data;
    }
}

/* 
Function peek()

This function returns the value of the head of the Stack

Pre:NA

Post: currency object

FUNCTION peek()
   create a temp node and assign to start
    return temp's data value
END FUNCTION
*/

Currency Stack :: peek(){
    LinkNode *p = new LinkNode();
    p = getStart();
    Currency curr = *p->data;
    return curr;
}

/* 
Function printStack()

This function prints the data in the stack

Pre:NA

Post: NA

FUNCTION printStack()
  create a counter of integer type
  create a temp node and assign to start
  if(start is null)
        print the list is empty
  end if

    while(temp is Not NULL)
        print counter and print temp's data value
        increment counter
        assign temp to temp's next pointer 
    end while

END FUNCTION
*/


std::string Stack :: printStack(){
     int count=0;
        if(getStart() == NULL){
            std::cout << "Stack is empty" << std:: endl;
        }
        LinkNode *p = getStart();
        
        while(p != NULL){
            std::cout << "INDEX: " << count << "   VALUE: " << p->data->getNote() << "." << p->data->getCoin() << std::endl;
            count++;
            p = p->next;

        }
      
}

#endif