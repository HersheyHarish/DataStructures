/*
Lab 5
Harish Sundarakumar 
The purpose of this assignment is to implement a hash table with the usage of the CURRENCY class from lab 2
*/


#include <iostream>
#include "dollar.h"
#include "hashTable.h"


using namespace std;

int main(){

   Currency *d[20] = {new Dollar(57.12),new Dollar(23.44), new Dollar(87.43), new Dollar(68.99), new Dollar(111.22), new Dollar(44.55), new Dollar(77.77),new Dollar(18.36),new Dollar(543.21), new Dollar(20.21), new Dollar(345.67),new Dollar(36.18),new Dollar(48.48),new Dollar(101.00),new Dollar(11.00),new Dollar(21.00),new Dollar(51.00),new Dollar(1.00),new Dollar(251.00),new Dollar(151.00)};
   HashTable bt(29,2,3);

    for(int i = 0; i<20; i++){
        bt.hashInsert(d[i]);
    }

    cout << "Number of data items loaded: " << bt.getInsert() << endl;
    cout << "Number of Collisions:" << bt.getCollisions() << endl;
    cout << "Load Factor:" << bt.getS()/20 << endl;
    

    int q;
   while(1){
   
    cout << "Enter 1 to search for currency item or 2 to quit application" << endl;

    cin >> q;
    switch(q){
        case 1:
            cout << "Enter the currency value to be searched for in hash table" << endl;
            double temp;
            cin >> temp;
            if(bt.hashFind(new Dollar(temp)) == -1){
                cout << "Invalid data" << endl;
                break;
            }else{
                cout << "Item exists at index: " << bt.hashFind(new Dollar(temp)) << endl; 
            }
            break;
        
        case 2:
            exit(1);

        default:
            cout << "Enter 1 to search for currency item or 2 to quit application" << endl;
    }

   }

    
    


    return 0;
}