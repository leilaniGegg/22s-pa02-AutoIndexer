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
    //planning
public:
    DSVector<DSString> readFile(const DSString&);
    void writeFile(const DSString&, map<DSString, DSVector<int>>&);
};

#endif //INC_21F_PA02_FILEMANAGER_H
