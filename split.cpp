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
void checkLast(Node* list, int oppMod2);
void setNext(Node* prev, Node* temp, Node* in, int mod2);

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
      setNext(odds, odds, in, 1);
    }
  }
  else {
    if (evens == NULL){
      evens = in;
    }
    else {
      setNext(evens, evens, in, 0);
    }
  }
  in = in->next;
  split(in, odds, evens);
}

void checkLast(Node* list, int oppMod2){
    if (list->next->next == NULL){
      if (list->next->value % 2 == oppMod2){
        list->next = NULL;
      }
      return;
    }
    else {
      list = list->next;
      checkLast(list, oppMod2);
    }
}

void setNext(Node* prev, Node* temp, Node* in, int mod2){
  if (temp == NULL || temp->value >= in->value){
    prev->next = in;
    return;
  }
  else {
    if (temp->value % 2 == mod2){
      prev = temp;
    }
    setNext(prev, temp->next, in, mod2);
  }
}