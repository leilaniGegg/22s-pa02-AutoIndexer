/**
 * Fall 2021 PA 02 Template Repo.
 */

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
#include "Indexer.h"

using namespace std;

int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        FileManager IO;
        Indexer ind;
        ind.retrieveBook(IO.readFile(argv[1]));
        //ind.displayBook();
        //cout << "------" << endl;
        ind.addKeyPhrases(IO.readFile(argv[2]));
        //ind.displayKeyPhrases();
        //cout << "------" << endl;
        ind.calculateKPP();
        //ind.displayKPP();
        IO.writeFile(argv[3], ind.getKPP());
    }
    return 0;
}