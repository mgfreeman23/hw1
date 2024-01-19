#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

//new item to back of list in O(1)
void ULListStr::push_back(const std::string& val){

  //case if list is completely empty
  if(head_ == nullptr){
    Item* item = new Item();
    (item->val)[0] = val;
    item->first = 0;
    item->last = 1;
    head_ = item;
    tail_ = item;
    size_++;
    return;
  }
  
  //check if tail val array is full
  if((tail_->last - tail_->first) == ARRSIZE){
    //create a new item
    Item* newTail = new Item();
    (newTail->val)[0] = val;
    newTail->first = 0;
    newTail->last = 1;
    //bridge the items
    newTail->prev = tail_;
    tail_->next = newTail;
    tail_ = newTail;
  } else {
    //if unfilled item, but vals of array at back indices
    if(tail_->last == ARRSIZE){
      std::string temp = (tail_->val)[tail_->first];
      (tail_->val)[tail_->first] = val;
      tail_->first = tail_->first - 1;
      (tail_->val)[tail_->first] = temp;
    } 
    //if space to add to back indices normally
    else{
      
      (tail_->val)[tail_->last] = val;
      tail_->last = tail_->last + 1;

    } 
  }
  size_++;

}

//removes last string in list
void ULListStr::pop_back(){
  //checks if val array of item would become empty
  if((tail_->last - tail_->first) == 1){
    //check if only item in list
    if(tail_->prev == nullptr){
      //SOME ISSUE HERE
      delete tail_;
      // delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    } 
    // else point to a new tail item
    else {
      Item* temp = tail_;
      (temp->prev)->next = nullptr;
      tail_ = tail_->prev;
      delete temp;
    }
  } 
  //else just shift index last points to
  else {
    tail_->last = tail_->last - 1;
  }
  size_--;

}

//new item to front of list in O(1)
void ULListStr::push_front(const std::string& val){

  //check if list is completely empty
  if(head_ == nullptr){
    Item* item = new Item();
    (item->val)[ARRSIZE - 1] = val;
    item->first = ARRSIZE - 1;
    item->last = ARRSIZE;
    head_ = item;
    tail_ = item;
    size_++;
    return;
  }

  //check if head val array is full
  if((head_->last - head_->first) == ARRSIZE){
    //create new Item
    Item* newHead = new Item();
    (newHead->val)[ARRSIZE-1] = val;
    newHead->first = ARRSIZE - 1;
    newHead->last = ARRSIZE;
    //bridge the items
    newHead->next = head_;
    head_->prev = newHead;
    head_ = newHead;

  } else {
    //if unfilled head, but values pushed to front indices of array
    if(head_->first == 0){
      std::string temp = (head_->val)[head_->first];
      (head_->val)[head_->first] = val;
      head_->last = head_->last + 1;
      (head_->val)[head_->last - 1] = temp;
    } 
    //normal approach for adding to not yet full val array 
    else {
      (head_->val)[head_->first - 1] = val;
       head_->first = head_->first - 1;
    }
  }
  size_++;
}

//removes first string in list
void ULListStr::pop_front(){
  //checks if val array would become empty
  if((head_->last - head_->first) == 1){
    //check if this is the only item in list
    if(head_->next == nullptr){
      //SOME ISSUE HERE
      delete head_;
      // delete tail_;
      tail_=nullptr;
      head_=nullptr;
    } 
    // otherwise make next item the head
    else {
       Item* temp = head_;
       (temp->next)->prev = nullptr;
       head_ = temp->next;
       delete temp;
    }

  } else {
    head_->first = head_->first + 1;
  }
  size_--;

}

//gets string at back of list
std::string const & ULListStr::back() const{
  return (tail_->val)[tail_->last - 1];

}

//gets string at front of list
std::string const & ULListStr::front() const{
  return (head_->val)[head_->first];

}
 

//return string pointer at specified location
std::string* ULListStr::getValAtLoc(size_t loc) const{
  //checks if valid location
  if(loc < 0 || loc > size_-1){
    return NULL;
  }

  //initializes variables
  unsigned int i = 0;
  Item* temp = head_;
  int arrIndex = temp->first;
  //gets first string in val array
  std::string* tempString = (temp->val);
  tempString = tempString + arrIndex;
  
  //loops until reaching string at loc
  while(i < loc){
    /*checks if it needs to go to next item 
    or stay within same val array*/
    if(arrIndex + 1 == ARRSIZE){
      temp = temp->next;
      tempString = temp->val;
      arrIndex = temp->first;
    } else {
      arrIndex = arrIndex + 1;
      tempString = tempString + 1;
    }
    i = i + 1;
  }
  return tempString;

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
