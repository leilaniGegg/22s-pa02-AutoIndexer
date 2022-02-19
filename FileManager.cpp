//
// Created by leila on 2/17/2022.
//

#include "FileManager.h"

DSVector<DSString> FileManager::readFile(const DSString& filename){
    ifstream file;
    file.open(filename.c_str());
    if (!file.is_open()) {
        cout << "Failed to open training file!" << endl;
    }
    DSVector<DSString> data;
    char line[500];
    while(file.getline(line, 500)) {
        if(*line != ' ') {
            DSString newLine(line);
            data.push_back(newLine);
        }
    }
    file.close();
    return data;
}

void FileManager::writeFile(const DSString&, map<DSString, DSVector<int>>){

}