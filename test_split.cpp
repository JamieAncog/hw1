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
    int dat[] = {1,2,3,4,5,6,7,8,9};
    Node node9 = Node(dat[8], NULL);
    Node node8 = Node(dat[7], &node9);
    Node node7 = Node(dat[6], &node8);
    Node node6 = Node(dat[5], &node7);
    Node node5 = Node(dat[4], &node6);
    Node node4 = Node(dat[3], &node5);
    Node node3 = Node(dat[2], &node4);
    Node node2 = Node(dat[1], &node3);
    Node node1 = Node(dat[0], &node2);
    Node* myNode = &node1;

    while (myNode != NULL){
        cout << myNode->value << " ";
        myNode = myNode->next;
    }

    cout << endl;

    Node* head = &node1;
    Node* odds = NULL;
    Node* evens = NULL;

    split(head, odds, evens);

    while (odds != NULL){
        cout << odds->value << " ";
        odds = odds->next;
    }
    
    cout << endl;

    while (evens != NULL){
        cout << evens->value << " ";
        evens = evens->next;
    }

    cout << endl;
}
