#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
#include <string>
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr mylist;

    //Testing push_back()
    mylist.push_back("12");
    for (int i = 0; i < 9; i++){
        mylist.push_back(to_string(i));
    }
    cout << mylist.size() << endl; //Tail is full
    mylist.push_back("14");
    for (int i = 0; i < (int) mylist.size(); i++){
        cout << mylist.get(i) << " ";
    }
    cout << endl;

    //Testing push_front()
    mylist.clear();
    mylist.push_front("24");
    for (int i = 0; i < 9; i++){
        mylist.push_front(to_string(i));
    }
    cout << mylist.size() << endl; //Head is full
    mylist.push_front("87");
        for (int i = 0; i < (int) mylist.size(); i++){
        cout << mylist.get(i) << " ";
    }
    cout << endl;

    //Testing pop_back()
    mylist.clear();
    mylist.pop_back();
    mylist.push_back("76");
    mylist.pop_back();
    for (int i = 0; i < 12; i++){
        mylist.push_back(to_string(i));
    }
    for (int i = 0; i < 11; i++){
        mylist.pop_back();
    }
    cout << mylist.size() << endl;

   //Testing back() and front()
   mylist.clear();
   for (int i = 5; i < 21; i++){
    mylist.push_back(to_string(i));
   }
   for (int i = 4; i >= 0; i--){
    mylist.push_front(to_string(i));
   }
   for (int i = 0; i < (int) mylist.size();i++){
    cout << mylist.get(i) << " ";
   }
    cout << endl;
    cout << "front: " << mylist.front() << endl;
    cout << "back: " << mylist.back() << endl;
    mylist.pop_back();
    mylist.pop_front();
    cout << "front: " << mylist.front() << endl;
    cout << "back: " << mylist.back() << endl;

}
