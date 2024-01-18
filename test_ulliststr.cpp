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
    for (int i = 0; i < 35; i++){
        package.push_back(to_string(i));
    }
    for (int i = 0; i < 35; i++){
        cout << package.get(i) << endl;
    }
}
