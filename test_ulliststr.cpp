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
        package.push_front(to_string(i));
    }
    for (int i = 0; i < 35; i++){
        cout << package.get(i) << endl;
    }
    ULListStr dat;
    dat.push_back("7");
    dat.push_front("8");
    dat.push_back("9");
    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
    // prints: 8 7 9
    cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
}
