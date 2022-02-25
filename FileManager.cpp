//
// Created by leila on 2/17/2022.
//

#include "FileManager.h"


/**
 *@param filename
 *@return DSVector<DSString> containing each line of the file
 */
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

/**
 *@param filename, KPP is the map of key phrases and vector pages numbers
 */
void FileManager::writeFile(const DSString& filename, map<DSString, DSVector<int>>& KPP){
    ofstream file;
    file.open(filename.c_str());
    if (!file.is_open()) {
        cout << "Failed to open training file!" << endl;
    }
    char currLetter = (KPP.begin()->first).toUpper()[0]; //first pos
    file << "[" << currLetter << "]" << endl;
    for(auto itr = KPP.begin(); itr != KPP.end(); itr++){
        if((currLetter != itr->first.toUpper()[0])){
            currLetter = itr->first.toUpper()[0];
            file << "[" << currLetter << "]" << endl;
        }
        file << itr->first << ": ";
        if(!itr->second.isEmpty()){
            file << itr->second.at(0);
            int i, val;
            for(i = 1, val = itr->first.getLength(); i < itr->second.getSize(); i++){
                //the value in this if is lower than 70 to take the spaces and commas into account
                //(70/3) since there are 3 possible items being printed.
                if(val+countDigits(itr->second.at(i))> (70 - itr->first.getLength())){
                    val = 0;
                    file << endl;
                    file << "    ";
                    file << itr->second.at(i);
                    val += decideIncrease1(countDigits(itr->second.at(i)));
                }
                else {
                    file << ", " << itr->second.at(i);
                    val += decideIncrease2(countDigits(itr->second.at(i)));
                }
            }
        }
        file << endl;
    }
    file.close();
}

/**
 *@param num is the number of digits
 *@return how much val should increase
 */
int FileManager::decideIncrease1(int num){
    if(num == 1){      //1 digit
        return 5;
    }
    else if(num == 2){ //2 digit
        return 6;
    }
    else if(num == 3){ //3 digit
        return 7;
    }
    else {  //4 digit page number?? just in case
        return 8;
    }
}

/**
 * for second condition from writeFile function
 *@param num is the number of digits
 *@return how much val should increase
 */
int FileManager::decideIncrease2(int num){
    if(num == 1){      //1 digit
        return 3;
    }
    else if(num == 2){ //2 digit
        return 4;
    }
    else if(num == 3){ //3 digit
        return 5;
    }
    else {  //4 digit page number?? just in case
        return 6;
    }
}

/**
 *@param val is a number
 *@return the count of the digits
 */
int FileManager::countDigits(int val){
    int temp = val;
    int count = 0;
    while(temp != 0){
        count++;
        temp /= 10;
    }
    return count;
}