/*
LAB 3
HARISH SUNDARAKUMAR
THE PURPOSE OF THIS ASSIGNMENT IS TO IMPLEMENT A SINGLY-LINKED LIST, A STACK, AND A QUEUE
WITH THE USAGE OF THE CURRENCY CLASS CREATED IN LAB 2
*/
#include <iostream>
#include "SinglyLinkedList.h"
#ifndef QUEUE_H
#define QUEUE_H

class Queue : private SinglyLinkedList{
    public:
    void enqueue(Currency *curr);
    Currency dequeue();
    Currency peekFront();
    Currency peekRear();
    void printQueue();
};

/* 
Function enqueue(Currency Object)

This function adds a Currency data type to the end of the queue

Pre:Currency object - 

Post: NA

FUNCTION enqueue(Currency Object)
   Create a 2 nodes:
   temp which contains the data and the next pointer points to NULL
   and p which is equal to start

   if(start is NULL)
        set start to temp
    else 
        while(p->next is NOT NULL)
         iterate through queue
        end while

        assign p-> next pointer to temp
    end if
END FUNCTION
*/

void Queue :: enqueue(Currency *curr){
    LinkNode* p = new LinkNode();
    p = getStart();
    LinkNode* temp = new LinkNode();
    temp->data = curr;
    temp->next = NULL;
    if(getStart() == NULL){
        setStart(temp);
    }else{
        while(p->next != NULL){
            p = p-> next;
        }
        p->next = temp;
    }
}

/* 
Function dequeue()

This function deletes a Currency data type at the start of the queue

Pre: NA

Post: Currency object

FUNCTION  dequeue()
   if(start is NULL)
        print (list is empty)
    end if

    create a temp node and assign to start
    assign start to start->next and return temp's data value
END FUNCTION
*/

Currency Queue :: dequeue(){
        if(getStart()==NULL){
            std::cout << "Queue is empty" << std::endl;
        }
        LinkNode*temp=getStart();
        setStart(getStart()->next);
        
        return *temp->data;
}

/* 
Function peekFront()

This function peeks and returns the value of the start of Queue

Pre: NA

Post: Currency object

FUNCTION  peekFront()
   if(start is NULL)
        print (list is empty)
    else{
       create a temp node and assign to start
       return a pointer to temp->data value
    }

    
END FUNCTION
*/


Currency Queue :: peekFront(){
    LinkNode *temp = getStart();
    if(getStart() == NULL){
        std::cout << "Queue is empty" << std::endl;
    }else{
        return *temp->data;
    }
}

/* 
Function peekRear()

This function peeks and returns the value of the end of Queue

Pre: NA

Post: Currency object

FUNCTION  peekRear()
    create temp node and assign to start

   if(start is NULL)
        print (list is empty)
    else
        while(temp-> next pointer is NOT NULL)
            iterate through list
        end while
    end if

    return a pointer to temps data value

END FUNCTION
*/



Currency Queue :: peekRear(){
    LinkNode *temp = getStart();
    if(getStart() == NULL){
        std::cout << "Queue is empty" << std::endl;
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        //Currency curr = *temp-> data;
        return *temp-> data;
    }
}

/* 
Function printQueue()

This function prints all the items within the queue

Pre: NA

Post: NA

FUNCTION  printQueue()
    create temp node and assign to start
    create counter with integer data type

   if(start is NULL)
        print (list is empty)
   end if

   while(temp is NOT NULL)
        print counter value and temp->data value
        increment counter
        assign temp to temp->next pointer
    end while

END FUNCTION
*/


 void Queue :: printQueue(){
     int count=0;
        if(getStart() == NULL){
            std::cout << "List is empty" << std:: endl;
        }
        LinkNode *p = getStart();
        
        while(p != NULL){
            std::cout << "INDEX: " << count << "   VALUE: " << p->data->getNote() << "." << p->data->getCoin() << std::endl;
            count++;
            p = p->next;

        }
       
}

#endif