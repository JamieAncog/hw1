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


void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in != NULL){
    if (in->value % 2 == 1){
     if (odds == NULL){
        Node firstOdd = Node(in->value, NULL);
        odds = &firstOdd;
        in = in->next;
      }
      else {
        Node newOdd = Node(in->value, NULL);
        odds->next = &newOdd;
        odds = &newOdd;
        in = in->next;
      }
    }
    else {
      if (evens == NULL){
        Node firstEven = Node(in->value, NULL);
        evens = &firstEven;
        in = in->next;
      }
      else {
        Node newEven = Node(in->value, NULL);
        evens->next = &newEven;
        evens = &newEven;
        in = in->next;
      }
    }
  }
  else {
    return;
  }
  split(in, odds, evens);
}
/* If you needed a helper function, write it here */
