/**
 * Fall 2021 PA 02 Template Repo.
 */

#include <iostream>
#include <fstream>

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"
#include "DSVector.h"
#include "DSString.h"

using namespace std;

int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        //DSVector<DSString>::iterator itr;
        DSVector<DSString> test;
        test.push_back("tomato");
        test.push_back("potato");
        test.push_back("doggo");
        cout << test.at(2) << endl;
        cout << "index" << test.find("potato") << endl;
        test.removeIndex(1);
        test.display();
    }
    return 0;
}
