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
    unordered_map<int, DSVector<DSString>> pageNumsAndLines; //page number and corresponding lines on that page
    DSVector<DSString> keyPhrases;
    map<DSString, DSVector<int>, DSStringCompare> keyWordAndPages;  //the key word and a DSVector of page numbers it was found

public:
    void retrieveBook(const DSVector<DSString>&);
    void displayBook()const;
    void addKeyPhrases(const DSVector<DSString>&);
    void displayKeyPhrases()const;
    map<DSString, DSVector<int>>& calculateKWP(const DSVector<DSString>&); //calculate the keywords and the pages (return type not sure)


};
#endif //INC_21F_PA02_INDEXER_H
