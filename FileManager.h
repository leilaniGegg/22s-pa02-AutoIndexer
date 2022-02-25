//
// Created by leila on 2/17/2022.
//

#ifndef INC_21F_PA02_FILEMANAGER_H
#define INC_21F_PA02_FILEMANAGER_H

#include "DSVector.h"
#include "DSString.h"
#include <fstream>
#include <iomanip>

class FileManager{
public:
    DSVector<DSString> readFile(const DSString&);
    void writeFile(const DSString&, map<DSString, DSVector<int>>&);
    int countDigits(int); //for formatting
    int decideIncrease1(int);
    int decideIncrease2(int);
};

#endif //INC_21F_PA02_FILEMANAGER_H
