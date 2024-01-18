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
    newItem->last = ARRSIZE-1;
    newItem->first = ARRSIZE-1;
    //newItem->prev = NULL;
    //newItem->next = NULL;
    head_ = newItem;   
  }
  else {
    Item* temp = head_;
    while (temp->next != NULL){
      temp = temp->next;
    }
    if (temp->last == ARRSIZE-1){
      Item* newItem = new Item();
      newItem->last = 
    }
  }
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

//FIX THIS!!!!
std::string a = "hi";
std::string* ULListStr::getValAtLoc(size_t loc) const {
  return &a;
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
