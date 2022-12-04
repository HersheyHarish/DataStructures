/*
LAB 4
HARISH SUNDARAKUMAR
THE PURPOSE OF THIS ASSIGNMENT IS TO IMPLEMENT A BINARY SEARCH TREE WITH USAGE OF THE CURRENCY CLASS IN LAB 2
*/
#include <iostream>
#include <fstream>
#include "currency.h"
#include "BST.h"

using namespace std;



int main(){
   Currency *d[20] = {new Dollar(57.12),new Dollar(23.44), new Dollar(87.43), new Dollar(68.99), new Dollar(111.22), new Dollar(44.55), new Dollar(77.77),new Dollar(18.36),new Dollar(543.21), new Dollar(20.21), new Dollar(345.67),new Dollar(36.18),new Dollar(48.48),new Dollar(101.00),new Dollar(11.00),new Dollar(21.00),new Dollar(51.00),new Dollar(1.00),new Dollar(251.00),new Dollar(151.00)};
   
    BST bt;
    bt.insert(new BSTNode(d[0]));
    bt.insert(new BSTNode(d[1]));
    bt.insert(new BSTNode(d[2]));
    bt.insert(new BSTNode(d[3]));
    bt.insert(new BSTNode(d[4]));
    bt.insert(new BSTNode(d[5]));
    bt.insert(new BSTNode(d[6]));
    bt.insert(new BSTNode(d[7]));
    bt.insert(new BSTNode(d[8]));
    bt.insert(new BSTNode(d[9]));
    bt.insert(new BSTNode(d[10]));
    bt.insert(new BSTNode(d[11]));
    bt.insert(new BSTNode(d[12]));
    bt.insert(new BSTNode(d[13]));
    bt.insert(new BSTNode(d[14]));
    bt.insert(new BSTNode(d[15]));
    bt.insert(new BSTNode(d[16]));
    bt.insert(new BSTNode(d[17]));
    bt.insert(new BSTNode(d[18]));

    
    fstream fio;
    fio.open("lab4.txt", ios::trunc | ios::out | ios::in);
    cout << "Breadth first" << endl;
    fio << "Breadth first: ";
    bt.breadthFirst(bt.root, fio);
    fio << endl;
    cout << endl;
    cout << "Inorder" << endl;
    fio << "Inorder: ";
    bt.inorder(bt.root, fio);
    fio << endl;
    cout << endl;
    cout << "Preorder" << endl;
    fio << "Preorder: ";
    bt.preOrder(bt.root, fio);
    fio << endl;
    cout << endl;
    cout << "Postorder" << endl;
    fio << "Postorder: ";
    bt.postOrder(bt.root, fio);
    fio << endl;
    cout << endl;
    cout << endl;
     
    cout << "Enter 1 to print BreadthFirst, Inorder, PreOrder, and postOrder" << endl;
    cout << "Enter 2 to insert Dollar object into binary search tree" << endl;
    cout << "Enter 3 to delete Dollar object from binary search tree" << endl;
    cout << "Enter 4 to search for Dollar Object" << endl;
    cout << "Enter 5 to exit" << endl;
    cout << "Enter 6 for help" << endl;
    
    int input;
    while(1){
        cin >> input;
        switch(input){
            case 1:
                cout << "Breadth first" << endl;
                fio << "Breadth first: ";
                bt.breadthFirst(bt.root, fio);
                fio << endl;
                cout << endl;
                cout << "Inorder" << endl;
                fio << "Inorder: ";
                bt.inorder(bt.root, fio);
                fio << endl;
                cout << endl;
                cout << "Preorder" << endl;
                fio << "Preorder: ";
                bt.preOrder(bt.root, fio);
                fio << endl;
                cout << endl;
                cout << "Postorder" << endl;
                fio << "Postorder: ";
                bt.postOrder(bt.root, fio);
                fio << endl;
                cout << endl;
                cout << endl;
                break;
            case 2:
                double aParam;
                cout << "Enter Dollar object to be inserted" << endl;
                fio << "Enter Dollar object to be inserted" << endl;
                cin >> aParam;
                if(aParam < 0 ){
                    fio << "Dollar object " << aParam << " is invalid" << endl;
                    cout << "Dollar object " << aParam << " is invalid" << endl;
                    break;
                }else{
                   bt.insert(new BSTNode(new Dollar(aParam)));
                    cout << "Insertion of " << aParam << " is complete" << endl;
                    fio << "Insertion of " << aParam << " is complete" << endl;
                    break;
                }
                break;

            case 3:
                double dParam;
                cout << "Enter Dollar object to be deleted" << endl;
                cin >> dParam;
                if(dParam < 0){
                    fio << "Dollar object " << dParam << " is invalid" << endl;
                    cout << "Dollar object " << dParam << " is invalid" << endl;
                    break;
                }else{
                    bt.del(new Dollar(dParam));
                    fio << "Dollar object " << dParam << " is deleted" << endl;
                    cout << "Dollar object " << dParam << " is deleted" << endl;
                    break;
                }
            case 4:
                double sParam;
                cout << "Enter Dollar object to be searched for" << endl;
                cin >> sParam;

                if(sParam < 0){
                    fio << "Dollar object " << sParam << " is invalid" << endl;
                    cout << "Dollar object " << sParam << " is invalid" << endl;
                    break;
                }else{
                    if(bt.search(new Dollar(sParam))){
                        cout << "Object exists in Binary Search Tree" << endl;
                    }else{
                        cout << "Object does not exist" << endl;
                    }
                    break;
                }

            case 5:
                fio << "Exiting application" << endl;
                cout << "Exiting application" << endl;
                cout << "Breadth first" << endl;
                fio << "Breadth first: ";
                bt.breadthFirst(bt.root, fio);
                fio << endl;
                cout << endl;
                cout << "Inorder" << endl;
                fio << "Inorder: ";
                bt.inorder(bt.root, fio);
                fio << endl;
                cout << endl;
                cout << "Preorder" << endl;
                fio << "Preorder: ";
                bt.preOrder(bt.root, fio);
                fio << endl;
                cout << endl;
                cout << "Postorder" << endl;
                fio << "Postorder: ";
                bt.postOrder(bt.root, fio);
                fio << endl;
                exit(1);
            case 6:
                cout << "Enter 1 to print BreadthFirst, Inorder, PreOrder, and postOrder" << endl;
                cout << "Enter 2 to insert Dollar object into binary search tree" << endl;
                cout << "Enter 3 to delete Dollar object from binary search tree" << endl;
                cout << "Enter 4 to search for Dollar Object" << endl;
                cout << "Enter 5 to exit" << endl;
                cout << "Enter 6 for help" << endl;
                break;
            
            default:
                cout << "Invalid input, press 9 for help or 8 to exit application" << endl;
                break;
        }
    }

    fio.close();    
   
    return 0;
}

