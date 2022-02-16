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


    SECTION("push_back and locating functions") {
        REQUIRE((test.at(1) == "DSString"));
        REQUIRE((test.at(0) == "Avocado"));
        REQUIRE((test.at(3) == "doggo"));
        REQUIRE((test.at(10) == "past capacity"));
        REQUIRE((test.find("Halloween") == 6));
        REQUIRE((test.find("google") == 9));
        REQUIRE((test.find("The moon") == 2));
    }
}