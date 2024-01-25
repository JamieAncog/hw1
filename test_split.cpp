/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstddef>

using namespace std;

void newList(Node*& first, int* dat, int datSize);
void printList(Node* first);
void deallocateList(Node*& first);

int main(int argc, char* argv[])
{
    Node* odds = NULL;
    Node* evens = NULL;
    Node* head = NULL;

    //Testing Average Case
    cout << "Next List: " << endl;
    int datA[] = {1,4,6,7,8,9,10,11,12};
    newList(head, datA, 9);
    printList(head);
    split(head, odds, evens);
    printList(odds);
    printList(evens);
    deallocateList(odds);
    deallocateList(evens);
    cout << "--------------------" << endl;

    //Testing All Evens
    cout << "Next List: " << endl;
    int datB[] = {2,4,6,8,10,12,14,16,18};
    newList(head, datB, 9);
    printList(head);
    split(head, odds, evens);
    printList(odds);
    printList(evens);
    deallocateList(odds);
    deallocateList(evens);
    cout << "--------------------" << endl;

    //Testing All Odds
    cout << "Next List: " << endl;
    int datC[] = {1,3,5,7,9,11,13,15,17};
    newList(head, datC, 9);
    printList(head);
    split(head, odds, evens);
    printList(odds);
    printList(evens);
    deallocateList(odds);
    deallocateList(evens);
    cout << "--------------------" << endl;

    //Testing All Same
    cout << "Next List: " << endl;
    int datD[] = {2,2,2,3,5,5,5,6};
    newList(head, datD, 8);
    printList(head);
    split(head, odds, evens);
    printList(odds);
    printList(evens);
    deallocateList(odds);
    deallocateList(evens);
    cout << "--------------------" << endl;

    //Testing Zeros
    cout << "Next List: " << endl;
    int datE[] = {0,0,2,3};
    newList(head, datE, 4);
    printList(head);
    split(head, odds, evens);
    printList(odds);
    printList(evens);
    deallocateList(odds);
    deallocateList(evens);
    cout << "--------------------" << endl;

}

void newList(Node*& first, int* dat, int datSize){
    first = new Node(dat[0], NULL);
    Node* temp = first;
    for (int i = 1; i < datSize; i++){
        Node* newNode = new Node(dat[i], NULL);
        temp->next = newNode;
        temp = newNode;
    }
}

void printList(Node* first){
    while (first != NULL){
        cout << first->value << " ";
        first = first->next;
    }
    cout << endl;
}

void deallocateList(Node*& first){
    while (first != NULL){
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}