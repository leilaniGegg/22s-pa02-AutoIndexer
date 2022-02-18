//
// Created by leila on 2/18/2022.
//

#ifndef INC_21F_PA02_INDEXER_H
#define INC_21F_PA02_INDEXER_H
#include "DSVector.h"
#include "DSString.h"

class Indexer{
private:
    map<DSString, DSVector<int>> keyWordAndPages;
    DSVector<DSString> keyWords;

public:

    void calculateKWP(DSVector<DSString>); //calculate the keywords and the pages

};
#endif //INC_21F_PA02_INDEXER_H
