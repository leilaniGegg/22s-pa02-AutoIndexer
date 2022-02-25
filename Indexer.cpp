//
// Created by leila on 2/18/2022.
//

#include "Indexer.h"


/**
 *@param input the DSVector read from the input test_book file
 */
void Indexer::retrieveBook(const DSVector<DSString>& input) {
    book = input;
}

/**
 * Display the book. For testing purposes
 */
void Indexer::displayBook()const{
    book.displayNewLine();
}

/**
 *@param temp DSVector read from the input terms file
 */
void Indexer::addKeyPhrases(const DSVector<DSString>& temp){
    for(int i = 0; i < temp.getSize();i++) {
        keyPhrasesAndPages[temp.at(i).toLower()] = DSVector<int>();
    }
}

/**
 * Display the key phrases. Testing purposes only
 */
void Indexer::displayKeyPhrases()const{
    map<DSString, DSVector<int>>::const_iterator itr;
    for(itr = keyPhrasesAndPages.begin(); itr != keyPhrasesAndPages.end(); itr++){
        cout << itr->first << endl;
    }
}

/**
 * Iterate through each key phrase
 * Iterate through each line of the book and look for the key phrase
 * Update the current page number if an '<' is encountered
 *@return a reference to class data member map containing key phrase and vector of page numbers
 */
map<DSString, DSVector<int>>& Indexer::calculateKPP(){
    //have book lines sorted into categories by page number (in map?)
    //loop through each keyword (DSVector
    //go through the lines in each page, if the keyword is found once, store that page number and
    //continue to next iteration
    //
    for(auto itr = keyPhrasesAndPages.begin(); itr != keyPhrasesAndPages.end(); itr++){
        int currPage = atoi(book.at(0).parseLineIntoString("<>").c_str());
        bool foundInPage = false;
        for (int i = 1; i < book.getSize(); i++){
            if(book.at(i)[0] == '<'){
                currPage = atoi(book.at(i).parseLineIntoString("<>").c_str());
                foundInPage = false;
                continue;
            }
            if (book.at(i).toLower().find(itr->first) && !foundInPage){ //if curr line contains current keyphrase
                itr->second.push_back(currPage);
                foundInPage = true;
            }
        }
    }
    sortKPP();
    return keyPhrasesAndPages;
}

/**
 * Sort the list of page numbers in ascending order
 */
void Indexer::sortKPP(){
    for(auto itr = keyPhrasesAndPages.begin(); itr != keyPhrasesAndPages.end(); itr++){
        itr->second.sort();
    }
}

/**
 * Display the key phrases and pages. For testing purposes
 */
void Indexer::displayKPP(){
    char currLetter = (keyPhrasesAndPages.begin()->first).toUpper()[0]; //first pos
    cout << "[" << currLetter << "]" << endl;
    for(auto itr = keyPhrasesAndPages.begin(); itr != keyPhrasesAndPages.end(); itr++){
        if((currLetter != itr->first.toUpper()[0])){
            currLetter = itr->first.toUpper()[0];
            cout << "[" << currLetter << "]" << endl;
        }
        cout << itr->first << ": ";
        if(!itr->second.isEmpty()){
            itr->second.sort().displayComma();
        }
        cout << endl;
    }
}

/**
 *@return the map object containing the key phrases and pages
 */
map<DSString, DSVector<int>>& Indexer::getKPP(){
    return keyPhrasesAndPages;
}