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
        if(*line != NULL) {
            DSString newLine(line);
            data.push_back(newLine);
        }
    }
    file.close();
    return data;
}

void FileManager::writeFile(const DSString& filename, map<DSString, DSVector<int>>& KPP){
    ofstream file;
    file.open(filename.c_str());
    if (!file.is_open()) {
        cout << "Failed to open training file!" << endl;
    }
    char currLetter = toupper((KPP.begin()->first)[0]); //first pos
    file << "[" << currLetter << "]" << endl;
    for(auto itr = KPP.begin(); itr != KPP.end(); itr++){
        if((currLetter != toupper(itr->first[0]))){
            currLetter = toupper(itr->first[0]);
            file << "[" << currLetter << "]" << endl;
        }
        file << itr->first << ": ";
        if(!itr->second.isEmpty()){
            file << itr->second.at(0);
            int i, val;
            for(i = 1, val = 1; i < itr->second.getSize(); i++, val++){
                //the value in this if is lower than 70 to take the spaces and commas into account
                //(70/3) since there are 3 possible items being printed.
                if(val > (23 - itr->first.getLength())){
                    val = 0;
                    file << endl;
                    file << "    "; //4 spaces as requested :D
                    file << itr->second.at(i);
                }
                else {
                    file << ", " << itr->second.at(i);
                }
            }
        }
        file << endl;
    }
    file.close();
}