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
#include "FileManager.h"

using namespace std;

int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        FileManager IO;
        DSVector<DSString> test = IO.readFile(argv[1]);
        for (int i = 0; i < test.getSize(); i++) {
            cout << test.at(i) << endl;
        }
    }
    return 0;
}