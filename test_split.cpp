/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

#include <iostream>
using namespace std;


//helper function to add a new value to a list
void append(Node*& head, int v){
  //creates new value
  Node* newNode = new Node(v, nullptr);
  //checks if list is empty or not
  if(head == nullptr){
    head = newNode;
  } else{
    Node* temp = head;
    while(temp->next != nullptr){
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void clearList(Node*& head){
  while(head != nullptr){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main(int argc, char* argv[])
{
  Node* even_list = nullptr;
  Node* odd_list = nullptr;
  Node* input_list = nullptr;
  append(input_list, 2);
  append(input_list, 4);
  append(input_list, 6);
  
  Node* temp = input_list;
  while(temp != nullptr){
    cout << temp->value << endl;
    temp = temp->next;
  }

  split(input_list, odd_list, even_list);

  //checks value of input list
  if(input_list == nullptr){
    cout << "input list set to null successfully!" << endl;
  }
  //print values of evens list
  Node* temp2 = even_list;
  while(temp2 != nullptr){
    cout << temp2->value << endl;
    temp2 = temp2->next;
  }
  //print values of evens list
  Node* temp3 = odd_list;
  while(temp3 != nullptr){
    cout << temp3->value << endl;
    temp3 = temp3->next;
  }

  clearList(even_list);
  clearList(odd_list);

}
