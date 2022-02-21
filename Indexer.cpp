//
// Created by leila on 2/18/2022.
//

#include "Indexer.h"

void Indexer::retrieveBook(const DSVector<DSString>& input){
    //keeping the page as one DSString to make using the find() function easier
    DSVector<DSString> tempPage;
    DSString tempLine;
    int currPageNum = atoi(input.at(0).parseLineIntoString("<>").c_str());
    cout << currPageNum << endl;
    for(int i = 1; input.at(i) != "<-1>"; i++){
        tempLine = input.at(i);
        if(tempLine[0] == '<'){
            cout << "In if" << endl;
            //if at the next page, add all lines gathered so far to the map with its page #
            pageNumsAndLines.insert(pair<int, DSVector<DSString>>(currPageNum, tempPage));

            //convert the <#> to an int and update the current page number
            currPageNum = atoi(input.at(i).parseLineIntoString("<>").c_str());
            cout << currPageNum << endl;
            continue;
        }
        tempLine.toLower();
        tempPage.push_back(tempLine);
        cout << tempLine << "*" << endl;
        //when I try adding this line below to line 25 it gives exit code 11 but idk why.
        //.parseLineIntoString("!@#$&,-()<>")
    }
}

void Indexer::displayBook()const{
    //map<int, DSString>::iterator itr;
    for(auto itr = pageNumsAndLines.begin(); itr != pageNumsAndLines.end(); itr++){
        cout << itr->first << endl;
        //cout << itr->second << endl;
    }
}

void Indexer::addKeyPhrases(const DSVector<DSString>& temp){
    keyPhrases = temp;
}

void Indexer::displayKeyPhrases()const{
    keyPhrases.display();
}

/*map<DSString, DSVector<int>>& Indexer::calculateKWP(const DSVector<DSString>&){
    //have book lines sorted into categories by page number (in map?)
    //loop through each keyword (DSVector
    //go through the lines in each page, if the keyword is found once, store that page number and
    //continue to next iteration
    //

}*/