//
// Created by leila on 2/18/2022.
//

#include "Indexer.h"

/*void Indexer::retrieveBook(const DSVector<DSString>& input){
    //keeping the page as one DSString to make using the find() function easier
    DSString line;
    int currPageNum = atoi(input.at(0).parseLineIntoString("<>").c_str());
    cout << currPageNum << endl;
    for(int i = 1; input.at(i) != "<-1>"; i++){
        //DSString* tempLine = &input.at(i).toLower();
        if(input.at(i)[0] == '<'){
            cout << "In if" << endl;
            //if at the next page, add all lines gathered so far to the map with its page #
            //pageNumsAndLines.insert(pair<int, DSVector<DSString>>(currPageNum, tempPage));
            pageNumsAndLines[currPageNum] = DSString(line);
            line = "";
            //convert the <#> to an int and update the current page number
            currPageNum = atoi(input.at(i).parseLineIntoString("<>").c_str());
            cout << currPageNum << endl;
            continue;
        }
        //tempLine.toLower();
        line = line + input.at(i).toLower();
        cout << input.at(i) << endl;
        cout << "*" << endl;
        //when I try adding this line below to line 25 it gives exit code 11 but idk why.
        //.parseLineIntoString("!@#$&,-()<>")
    }
}*/

void Indexer::retrieveBook(const DSVector<DSString>& input) {
    book = input;
}

void Indexer::displayBook()const{
    //map<int, DSString>::iterator itr;
    /*for(auto itr = pageNumsAndLines.begin(); itr != pageNumsAndLines.end(); itr++){
        cout << itr->first << endl;
    }*/
    book.displayNewLine();
}

void Indexer::addKeyPhrases(const DSVector<DSString>& temp){
    for(int i = 0; i < temp.getSize();i++) {
        keyPhrasesAndPages[temp.at(i).toLower()] = DSVector<int>();
    }
}

void Indexer::displayKeyPhrases()const{
    map<DSString, DSVector<int>>::const_iterator itr;
    for(itr = keyPhrasesAndPages.begin(); itr != keyPhrasesAndPages.end(); itr++){
        cout << itr->first << endl;
    }
}

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

void Indexer::sortKPP(){
    for(auto itr = keyPhrasesAndPages.begin(); itr != keyPhrasesAndPages.end(); itr++){
        itr->second.sort();
    }
}

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

map<DSString, DSVector<int>>& Indexer::getKPP(){
    return keyPhrasesAndPages;
}