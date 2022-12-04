/*
LAB 3
HARISH SUNDARAKUMAR
THE PURPOSE OF THIS ASSIGNMENT IS TO IMPLEMENT A SINGLY-LINKED LIST, A STACK, AND A QUEUE
WITH THE USAGE OF THE CURRENCY CLASS CREATED IN LAB 2
*/ 
#include <iostream>
#include "dollar.h"
#include "SinglyLinkedList.h"
#include "Stack.h"
#include "queue.h"

using namespace std;

int main(){
   cout << "Welcome to my implementation of the SinglyLinkedList, Queue and Stack by Harish Sundarakumar" << endl;

   Currency *curr[20] = {new Dollar(57.12),new Dollar(23.44), new Dollar(87.43), new Dollar(68.99), new Dollar(111.22), new Dollar(44.55), new Dollar(77.77),new Dollar(18.36),new Dollar(543.21), new Dollar(20.21), new Dollar(345.67),new Dollar(36.18),new Dollar(48.48),new Dollar(101.00),new Dollar(11.00),new Dollar(21.00),new Dollar(51.00),new Dollar(1.00),new Dollar(251.00),new Dollar(151.00)};
   SinglyLinkedList* sing = new SinglyLinkedList;
   sing->addCurrency(curr[6],0);
   sing->addCurrency(curr[5],1);
   sing->addCurrency(curr[4],2);
   sing->addCurrency(curr[3],3);
   sing->addCurrency(curr[2],4);
   sing->addCurrency(curr[1],5);
   sing->addCurrency(curr[0],6);
   cout << "searching for 87.43" << endl;
   int k  = sing -> findCurrency(new Dollar(87.43));
   if(k == -1){
      cout << "Item was not found" <<endl;
   }else{
      cout << "Item was found at index: " << k << endl;
   }
   int j = sing->findCurrency(new Dollar(44.56));
   
   cout << "Searching for 44.56" << endl;

   if(j == -1){
      cout << "Item was not found" <<endl;
   }else{
      cout << "Item was found at index: " << j << endl;
   }
   cout << "deleting 111.22" << endl;
   sing -> removeCurrency(new Dollar(111.22));
   
   cout << "Delete at index 2" << endl;
   sing -> removeCurrency(2);
   sing -> printList();

   cout << "Adding 4 items" << endl;
   sing->addCurrency(curr[8],5);
   sing->addCurrency(curr[9],6);
   sing->addCurrency(curr[10],7);
   sing->addCurrency(curr[11],8);
   cout << "Total num of nodes: " << sing->countCurrency() << endl;
   cout << "Removing node at TotalNodes %6" << endl;
   sing -> removeCurrency(sing->countCurrency()%6);
   cout << "Removing node at TotalNodes /7" << endl;
   sing -> removeCurrency(sing->countCurrency()/7);
   sing -> printList();

   cout << "Deleting List" <<endl;
   delete sing;

   
   cout << "Creating Stack"<< endl;
   Stack *st = new Stack;
   cout << "Pushing 7 objects from index 12 to 19" << endl;
   st->push(curr[13]);
   st->push(curr[14]);
   st->push(curr[15]);
   st->push(curr[16]);
   st->push(curr[17]);
   st->push(curr[18]);
   st->push(curr[19]);
   cout << "Peeking: ";
   st->peek().toString();

   cout << "Popping 3 times" << endl;
   st->pop();
   st->pop();
   st->pop();
   st->printStack();
   cout << "Adding 5 objects from starting array" <<endl;
   st->push(curr[0]);
   st->push(curr[1]);
   st->push(curr[2]);
   st->push(curr[3]);
   st->push(curr[4]);
   cout << "Popping twice" << endl;
   st->pop();
   st->pop();
   st->printStack();

   cout << "Deleting Stack" << endl;
   delete st;

   cout << "Creating Queue" << endl;
   Queue *temp = new Queue;
   temp->enqueue(curr[5]);
   temp->enqueue(curr[7]);
   temp->enqueue(curr[9]);
   temp->enqueue(curr[11]);
   temp->enqueue(curr[13]);
   temp->enqueue(curr[15]);
   temp->enqueue(curr[17]);
   temp->enqueue(curr[19]);
   cout << "deleting: ";
   temp->dequeue().toString();
   cout << "deleting: ";
   temp->dequeue().toString();
   temp->printQueue();
   cout << "Peeking front: ";
   temp->peekFront().toString();
   cout << "Peeking rear: ";
   Currency breh = temp->peekRear();
   breh.toString();
   temp->enqueue(curr[10]);
   temp->enqueue(curr[11]);
   temp->enqueue(curr[12]);
   temp->enqueue(curr[13]);
   temp->enqueue(curr[14]);
   cout << "deleting: ";
   temp->dequeue().toString();
   cout << "deleting: ";
   Currency d = temp->dequeue();
   d.toString();
   cout << "deleting: ";
   temp->dequeue().toString();
   
   cout<< "Finished removing from top" << endl;
   temp->printQueue();


   cout << "Finished all functions of SinglyStackedList, Stack, and Queue!" << endl;
   system("pause");

   return 0;
}

