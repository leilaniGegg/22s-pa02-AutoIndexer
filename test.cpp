//
// Created by leila on 2/14/2022.
//
#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"

TEST_CASE("DSVector class", "[vector]"){
    DSVector<DSString> test;
    test.push_back("Avocado");
    test.push_back("DSString");
    test.push_back("The moon");
    test.push_back("doggo");
    test.push_back("tissue");
    test.push_back("sharpie");
    test.push_back("Halloween");
    test.push_back("this is a sentence");
    test.push_back("random");
    test.push_back("google");
    test.push_back("past capacity");


    SECTION("MODIFIERS AND ACCESSORS") {
        //push_back is tested by the vector existing I guess
        test.insert("INSERTED", 3);
        test.insert("INSERTED2", 7);
        test.insert("INSERTED3", 9);
        REQUIRE((test.at(3) == "INSERTED"));
        REQUIRE((test.at(7) == "INSERTED2"));
        REQUIRE((test.at(9) == "INSERTED3"));
        test.removeIndex(3);
        test.removeIndex(6); // 6 instead of 7 to consider the offset
        test.removeIndex(7);
        REQUIRE((test[3] != "INSERTED"));
        REQUIRE((test[7] != "INSERTED2"));
        REQUIRE((test[9] != "INSERTED3"));
        REQUIRE((test.find("tissue") == 4));
        REQUIRE((test.find("doggo") == 3));
        REQUIRE((test.find("google") == 9));
        test.sort();
        REQUIRE((test.at(10) == "tissue")); //should be last element now
        REQUIRE((test.at(9) == "this is a sentence"));
        REQUIRE((test.at(8) == "The moon"));
    }

    SECTION("ACCESSORS"){
        REQUIRE((test.begin() == "Avocado"));
        REQUIRE((test.end() == "past capacity"));
        //this only way I could think to test hasNext and getNext
        cout << "Testing next functions" << endl << test.begin() << endl;
        while(test.hasNext()){
            cout << test.getNext() << endl;
        }
        DSVector<DSString> temp;
        REQUIRE((temp.isEmpty()));
    }

    SECTION("GETTERS AND PRINT FUNCTIONS"){
        REQUIRE((test.getSize() == 11));
        REQUIRE((test.getCapacity() == 20)); //size went over capacity once, so initial capacity of 10 should be doubled to 20
        //Not sure if or how these need testing
        cout << "Printing elements per line" << endl;
        test.displayNewLine();
        cout << "Printing elements seperated by comma" << endl;
        test.displayComma();
    }
}

TEST_CASE("DSString class", "[string]"){

    DSString list[10];

    list[0] = DSString("potato");
    list[1] = DSString("lilyPad");
    list[2] = DSString("wild west");
    list[3] = DSString("");
    list[4] = DSString("\n");
    list[5] = DSString("A CHILD");
    list[6] = DSString("a child");
    list[7] = DSString("!!!!");
    list[8] = DSString("How much wood can a wood chuck chuck");
    list[9] = DSString("cOkE ZeRO");
    //list[10] = DSString("lily");


    SECTION("Comparison Operators" ) {
        REQUIRE((list[0] > list[1]));
        REQUIRE((list[6] < list[2]));
        REQUIRE((list[5] > list[7]));
        REQUIRE((list[0] == "potato"));
        REQUIRE(!(list[5] == list[6]));
        REQUIRE((list[3] == ""));
    }

    SECTION("Adding Operators"){
        REQUIRE((list[0] + list[2] == "potatowild west"));
        REQUIRE((list[2] + list[3] == "wild west"));
        REQUIRE((list[5] + list[7] == "A CHILD!!!!"));
        REQUIRE((list[3] + list[4] == "\n"));
    }
    SECTION("Assignment Operator?"){
        REQUIRE((list[1][4] == 'P' ));
        REQUIRE((list[0][0] == 'p'));
        REQUIRE((list[2][8] == 't'));
        REQUIRE((list[5][2] == 'C'));
    }

    SECTION("Length Function"){
        REQUIRE((list[0].getLength() == 6));
        REQUIRE((list[2].getLength() == 9));
        REQUIRE((list[3].getLength() == 0));
        REQUIRE((list[7].getLength() == 4));
    }
    SECTION("c_str function"){
        char* p = "potato";
        char* x = "cOkE ZeRO";
        REQUIRE((strcmp(list[0].c_str(), p) == 0));
        REQUIRE(!(strcmp(list[6].c_str(), p) == 0));
        REQUIRE((strcmp(list[9].c_str(), x) == 0));

    }
    SECTION("Parse Tweet Function"){
        DSVector<DSString> words = list[8].parseLine(" ");
        REQUIRE((words.at(2) == "wood"));
        REQUIRE((words.at(4) == "a"));
        REQUIRE((words.at(6) == "chuck"));
    }

    SECTION("To Lower Function"){
        REQUIRE((list[5].toLower() == "a child"));
        REQUIRE((list[1].toLower() == "lilypad"));
        REQUIRE((list[9].toLower() == "coke zero"));
    }
    /*SECTION("To Upper Function"){
        DSString x = list[5].toUpper();
        DSString y = list[5].toUpper();
        DSString z = list[5].toUpper();

        //REQUIRE((x == "A CHILD"));
        //REQUIRE((y == "LILYPAD"));
        //REQUIRE((z == "COKE ZERO"));
    }*/
}