#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

//Delete this
#include <iostream>
using namespace std;

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

void ULListStr::push_back(const std::string& val){
  if (tail_ == NULL){
    Item* newItem = new Item();
    newItem->last = 1;
    newItem->first = 0;
    newItem->prev = NULL;
    newItem->next = NULL;
    head_ = newItem;
    tail_ = newItem;
    newItem->val[0] = val;   
  }
  else {
    if (tail_->last == ARRSIZE){
      Item* newItem = new Item();
      newItem->last = 1;
      newItem->first = 0;
      newItem->prev = tail_;
      newItem->next = NULL;
      tail_->next = newItem;
      tail_ = newItem;
      newItem->val[0] = val;
    }
    else {
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if (head_ == NULL){
    Item* newItem = new Item();
    newItem->last = ARRSIZE;
    newItem->first = ARRSIZE-1;
    newItem->prev = NULL;
    newItem->next = NULL;
    head_ = newItem;
    tail_ = newItem;
    newItem->val[ARRSIZE-1] = val;   
  }
  else {
    if (head_->first == 0){
      Item* newItem = new Item();
      newItem->last = ARRSIZE;
      newItem->first = ARRSIZE-1;
      newItem->prev = NULL;
      head_->prev = newItem;
      newItem->next = head_;
      head_ = newItem;
      newItem->val[ARRSIZE-1] = val;
    }
    else {
      head_->first--;
      head_->val[head_->first] = val;
    }
  }
  size_++;
}

void ULListStr::pop_back(){

}

void ULListStr::pop_front(){
  
}


std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}


std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc > size_ || head_ == NULL){
    return NULL;
  }
  Item* temp = head_;
  while (temp != NULL){
    size_t numInItem = temp->last - temp->first;
    if (loc < numInItem){
      return &temp->val[temp->first+loc];
    }
    else {
      loc -= numInItem;
    }
    temp = temp->next;
  }
  return NULL;
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
