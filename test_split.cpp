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

int main(int argc, char* argv[])
{
    int dat[] = {1,4,6,7,8,9,10,11,12};
    Node* node9 = new Node(dat[8], NULL);
    Node* node8 = new Node(dat[7], node9);
    Node* node7 = new Node(dat[6], node8);
    Node* node6 = new Node(dat[5], node7);
    Node* node5 = new Node(dat[4], node6);
    Node* node4 = new Node(dat[3], node5);
    Node* node3 = new Node(dat[2], node4);
    Node* node2 = new Node(dat[1], node3);
    Node* node1 = new Node(dat[0], node2);
    Node* myNode = node1;

    while (myNode != NULL){
        cout << myNode->value << " ";
        myNode = myNode->next;
    }

    cout << endl;

    Node* head = node1;
    Node* odds = NULL;
    Node* evens = NULL;

    split(head, odds, evens);

    while (odds != NULL){
        cout << odds->value << " ";
        Node* temp = odds;
        odds = odds->next;
        delete temp;
    }
    cout << endl;

    while (evens != NULL){
        cout << evens->value << " ";
        Node* temp = evens;
        evens = evens->next;
        delete temp;
    }

    cout << endl;

}
