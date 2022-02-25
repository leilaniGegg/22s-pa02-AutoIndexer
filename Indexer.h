//
// Created by leila on 2/18/2022.
//

#ifndef INC_21F_PA02_INDEXER_H
#define INC_21F_PA02_INDEXER_H
#include "DSVector.h"
#include "DSString.h"
#include <iterator>
#include <map>
#include <unordered_map>

using namespace std;

class Indexer{
private:
    DSVector<DSString> book;
    map<DSString, DSVector<int>> keyPhrasesAndPages;  //the key word and a DSVector of page numbers it was found

public:
    void retrieveBook(const DSVector<DSString>&);
    void displayBook()const;
    void addKeyPhrases(const DSVector<DSString>&);
    void displayKeyPhrases()const;
    map<DSString, DSVector<int>>& calculateKPP(); //calculate the keywords and the pages (return type not sure)
    void displayKPP(); //display the key phrases and the list of pages, as they would in the output file (for testing purposes)
    void sortKPP();
    map<DSString, DSVector<int>>& getKPP();
};
#endif //INC_21F_PA02_INDEXER_H
