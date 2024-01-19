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
    ULListStr package;
    package.pop_back();
    for (int i = 10; i >= 0; i--){
        package.push_front(to_string(i));
    }
    for (int i = 11; i < 23; i++){
        package.push_back(to_string(i));
    }
    package.pop_back();
    package.pop_back();
    for (int i = 0; i < 21; i++){
        cout << package.get(i) << endl;
    }
    cout << "front: " << package.front() << endl;
    cout << "back: " << package.back() << endl;
}
