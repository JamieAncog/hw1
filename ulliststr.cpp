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

void ULListStr::push_back(const std::string& val){
  if (head_ == NULL){
    Item* newItem = new Item();
    newItem->last = ARRSIZE;
    newItem->first = ARRSIZE-1;
    //newItem->prev = NULL;
    //newItem->next = NULL;
    head_ = newItem;
    tail_ = newItem;
    newItem->val[ARRSIZE-1] = val;   
  }
  else {
    if (tail_->last == ARRSIZE){
      Item* newItem = new Item();
      newItem->last = ARRSIZE;
      newItem->first = ARRSIZE-1;
      newItem->prev = tail_;
      //newItem->next = NULL;
      tail_->next = newItem;
      tail_ = newItem;
      newItem->val[ARRSIZE-1] = val;
    }
    else {
      tail_->last++;
      tail_->val[tail_->last] = val;
    }
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){

}

void ULListStr::pop_back(){

}

void ULListStr::pop_front(){
  
}

/*
std::string const & ULListStr::back() const{

}

std::string const & ULListStr::front() const{

}
*/

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc > size_ || head_ == NULL){
    return NULL;
  }
  Item* temp = head_;
  return &head_->val[head_->first+loc];
  while (temp != NULL){
    size_t range = temp->last - temp->first;
    if (loc <= range){
      return &temp->val[temp->first+loc];
    }
    else {
      loc -= range;
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
