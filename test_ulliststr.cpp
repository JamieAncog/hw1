#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr package;
    package.push_back("bob");
    package.push_back("by");
    cout << package.get(1) << endl;
}
