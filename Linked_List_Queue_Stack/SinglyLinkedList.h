/*
LAB 3
HARISH SUNDARAKUMAR
THE PURPOSE OF THIS ASSIGNMENT IS TO IMPLEMENT A SINGLY-LINKED LIST, A STACK, AND A QUEUE
WITH THE USAGE OF THE CURRENCY CLASS CREATED IN LAB 2
*/

#include <iostream>
#include "LinkNode.h"
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class SinglyLinkedList{
    private:
    int count;
    LinkNode *start;
    LinkNode *end;

    public:
    SinglyLinkedList(){
        start = NULL;
        end = NULL;
    }

    LinkNode* getStart(){return this->start;}
    void setStart(LinkNode* start){this->start = start;}
    LinkNode* getEnd(){return this->end;}
    void setEnd(LinkNode* end){this->end = end;}

    void addTail(Currency *data);
    void addHead(Currency *data);
    void addCurrency(Currency *data, int index);
    void removeCurrency(Currency *data);
    void removeCurrency(int index);
    int findCurrency(Currency *data);   
    Currency getCurrency(int index);
    void printList();
    bool isListEmpty();
    int countCurrency();

};

/* 
Function addTail(Currency Object)

This function adds a Currency data type to the end of the linked list

Pre:Currency object - 

Post: NA

FUNCTION addTail(Currency Object)
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

 void SinglyLinkedList ::addTail(Currency *data){
    LinkNode *temp = new LinkNode();
    LinkNode *traverse = start;
    temp->data = data;
    temp->next = NULL;

    if(start == NULL){
            start = temp;
    }else{
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = temp;
    }
}
/* 
Function addHead(Currency Object)

This function adds a Currency data type to the start of the linked list

Pre:Currency object 

Post: NA

FUNCTION addHead(Currency Object)
    Create a new Node called temp and assign the Currency Objects data value to temp->data
    assign temp next pointer to the head
    assign head value as temp
END FUNCTION
*/
void SinglyLinkedList :: addHead(Currency *data){
    LinkNode *temp = new LinkNode();
    temp->data = data;
    temp->next = start;
    start = temp;
}

/* 
Function addCurrency(Currency Object, int indexc)

This function adds a Currency data type to the start of the linked list

Pre:Currency object 
    index(integer)

Post: NA

FUNCTION addCurrency(Currency Object, int index)
    Create a 3 New Nodes: Curr, Prev, and temp
    Assign temp data value to Currency Object
    Assign Curr to head of the list
    int count = 0 

    if(the start of the list is NOT NULL)
        while (curr's next pointer is NOT NULL and count is not EQUAL to index)
            iterate through the list by:
                making prev equal to curr
                make curr equal to curr->next pointer
                increment count
        end while
        
        if the index is equivalent to 0
            call addHead function and pass currency object
        else if the curr next pointer is NULL and the index value is 1 more than count's value
            call addTail function and pass currency object
        else if the count is equivalent to index
            assign prev's next pointer to temp
            assign temp's next pointer to curr
        end if

    else if the start of the list is NULL
        assign start of list to temp
        assign temp's next pointer as NULL
    end if
END FUNCTION
*/
void SinglyLinkedList :: addCurrency(Currency *data, int index){
    LinkNode *curr = new LinkNode();
    LinkNode *prev = new LinkNode();
    LinkNode *temp = new LinkNode();
    temp->data = data;
    curr = start;
    int count = 0;

    if(start != NULL){
        while(curr->next != NULL && count != index){
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(index==0){    
            addHead(data);
        }else if(curr->next == NULL && index == count+1){
            addTail(data);
        }else if(count == index){
            prev->next = temp;
            temp->next = curr;
        }
    }else{
    start = temp;
    temp->next=NULL;
    }
};

/* 
Function removeCurrency(Currency object)

This function searches and deletes Currency data value with given input of a Currency object

Pre:Currency object

Post: NA

FUNCTION removeCurrency(Currency object)
   create a temp node that is assigned to start of the list
   create another node named prev

   if(temp is NOT NULL and if TEMP's data is equivalent to Currency object)
        point start to temp's next pointer
        delete temp
    else
        while temp is NOT NULL and TEMP data is NOT equivalent to Currency Object
            iterate through the list:
                make prev equal to temp
                assign temp to temps next pointer
        end while

        if temp is NULL
            print could not find item
        end if

        assign prev's next pointer to temp's next pointer
        delete temp;

END FUNCTION
*/

void SinglyLinkedList :: removeCurrency(Currency *data){
    LinkNode *temp = start;
    LinkNode *prev = new LinkNode();    
        //                      Equivalent to if temp data is equal to data
    if( temp != NULL && ((temp->data->getNote() == data->getNote())  && (temp->data->getCoin() == data->getCoin()))  ){
        start = temp->next;
        delete temp;
        return;
    }else{
        while(temp != NULL && ((temp->data->getNote() != data->getNote())  && (temp->data->getCoin() != data->getCoin()))){
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL){
            std::cout << "Could not find item" << std::endl;
        }
        prev->next = temp->next;
        delete temp;
    }       
}

/* 
Function removeCurrency(int index)

This function searches and deletes Currency data value with given input of a index

Pre:index(integer)

Post: NA

FUNCTION removeCurrency(int index)
   create a curr node that is assigned to start of the list
   create another node named prev
    create count wiht ineger data type

    if (index is equal to 0)
        assign start to currs next pointer
        delete curr
    else
        while (count isnt equal to index and curr is NOT NULL)
            assign prev to curr
            assing curr to curr's next pointer
            increment count
        end while

        if(count is equal to index)
            assign prev->next pointer to curr's next pointer
        end if
    end if
   
END FUNCTION
*/

 void SinglyLinkedList :: removeCurrency(int index){
        LinkNode *prev = new LinkNode();
        LinkNode *curr = start;
        int count = 0;

        if(index == 0){
            start = curr->next;
            delete curr;
        }else{
            while(count != index && curr != NULL){
                prev = curr;
                curr = curr ->next;
                count++;
            }
            if(count == index){
                prev->next = curr->next;
                delete curr;
            }
        }
    }

/* 
Function findCurrency(Currency Object)

This function searches for the currency object in list and returns integer type

Pre: Currency object

Post: index(integer)

FUNCTION findCurrency(currency object)
    create a new node curr and assign it to start
    create integer named index

    while(curr is not NULL)
        if(curr's data is equivalent to Currency Object)
            return index
        else
            increment index
            iterate through list by assigning curr to curr-> next
        end if
    end while

    return -1 if object is not found
  
END FUNCTION
*/

 int SinglyLinkedList :: findCurrency(Currency *data){
    LinkNode *curr = start;
    int index = 0;
       
    while(curr != NULL){
        if((curr->data->getNote() ==  data->getNote()) && (curr->data->getCoin() == data->getCoin())){
            return index;
        }else{
            index++;
            curr = curr->next;
        }
    }
    return -1;
}

/* 
Function getCurrency(int index)

This function returns a currency object at given index

Pre: index(integer)

Post: Currency(object)

FUNCTION getCurrency(int index)
    create a new node curr and assign it to start
    create integer named count and assign to 0

    if index is equal to 0
        return a pointer to start->data
    else
        while(count is not equal to index and curr is NOT NULL)
            iterate through list
        end while

        if(count is equal to index)
            return a pointer to curr->data
        end if
    end if
  
END FUNCTION
*/

Currency SinglyLinkedList :: getCurrency(int index){
    LinkNode *curr = start;
    count = 0;
    if(index == 0){
        return *start->data;
    }else{
        while(count != index && curr!= NULL){
            curr= curr->next;
        }

        if(count == index){
            return *curr->data;
        }

    }
}

/* 
Function printList()

This function prints all the objects in the list

Pre: NA

Post: NA

FUNCTION printList()
    create a counter and equal to 0
    Create a temp node and assign to start

    if(head of list is NULL)
        print list is empty
    end if

    while(p is not NULL)
        print index and p->data value
        increment count
        assign p to p->next pointer
    end while

END FUNCTION
*/

void SinglyLinkedList :: printList(){
        int count=0;
        if(start == NULL){
            std::cout << "List is empty" << std:: endl;
        }
        LinkNode *p = new LinkNode();
        p = start;
        while(p != NULL){
            std::cout << "INDEX: " << count << "   VALUE: " << p->data->getNote() << "." << p->data->getCoin() << std::endl;
            count++;
            p = p->next;

        }
        
    }

/* 
Function isListEmpty()

This function checks if the list is empty or not

Pre: NA

Post: TRUE OR FALSE(Boolean)

FUNCTION isListEmpty()
    if(the head and tail is NULL)
        return true
    end if
    return false
END FUNCTION
*/
bool SinglyLinkedList :: isListEmpty(){
    if(start == NULL && end == NULL){
        return true; 
    }
        return false;
}

/* 
Function countCurrency()

This function returns how many nodes are in the list

Pre: NA

Post: count(integer)

FUNCTION countCurrency()
    create a new node temp and assign to head
    create count with integer data type and assign to 0

    while(temp next pointer is not NULL)
        increment count
        assign temp to temp->next pointer
    end while

    return count
END FUNCTION
*/

int SinglyLinkedList :: countCurrency(){
    LinkNode *temp = start;
    int i = 0;
    while(temp->next != NULL){
        i++;
        temp = temp->next;
    }
        return i;
    }
#endif