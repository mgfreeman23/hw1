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

//split function
void split(Node*& in, Node*& odds, Node*& evens)
{
//base case, checks if input list is empty
  if(in == nullptr){
    return;
  }
  //recursive element to reach last list item (head recursion)
  split(in->next, odds, evens);

  //checks if value is even or odd
  if(in->value % 2 == 0){
    //connects the nodes correctly in evens and odds lists
    in->next = evens;
    evens = in;
  
  } else {
    in->next = odds;
    odds = in;
    
  }
  /*assigns current input list item to nullptr,
  working backwards through input list*/
  in = nullptr;
  return;
}
