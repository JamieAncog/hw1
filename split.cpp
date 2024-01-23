/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include<cstddef>
#include <iostream>
#include <cstddef>

using namespace std;

/* Add a prototype for a helper function here if you need */
void checkLast(Node*& list, int mod2);

void split(Node*& in, Node*& odds, Node*& evens){
  if (in == NULL){
    checkLast(evens, 1);
    checkLast(odds, 0);
    return;
  }
  if (in->value % 2 == 1){
    if (odds == NULL){
      odds = in;
    }
    else {
      Node* prevOdd = odds;
      Node* tempOdd = odds;
      while (tempOdd != NULL && tempOdd->value < in->value){
        if (tempOdd->value % 2 == 1){
          prevOdd = tempOdd;
        }
        tempOdd = tempOdd->next;
      }
      prevOdd->next = in;
    }
  }
  else {
    if (evens == NULL){
      evens = in;
    }
    else {
      Node* prevEven = evens;
      Node* tempEven = evens;
      while (tempEven != NULL && tempEven->value < in->value){
        if (tempEven->value % 2 == 0){
          prevEven = tempEven;
        }
        tempEven = tempEven->next;
      }
      prevEven->next = in;
    }
  }
  in = in->next;
  split(in, odds, evens);
}

void checkLast(Node*& list, int mod2){
    Node* temp = list;
    while (temp->next->next != NULL){
      temp = temp->next;
    }
    if (temp->next->value % 2 == mod2){
      temp->next = NULL;
    }
}