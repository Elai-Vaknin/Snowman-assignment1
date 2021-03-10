#include "doctest.h"
#include "snowman.hpp"

using namespace ariel;

#include <string>
#include <algorithm>

using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12121212)) == nospaces("_===_\n(..o)/\n<( : )\n(\" \")"));
    CHECK(nospaces(snowman(12121234)) == nospaces(" _===_\n(..o)/\n<(> <)\n(   )"));
    CHECK(nospaces(snowman(14141414)) == nospaces("_===_\n(. -)\n<( : ) \n(   )"));
    CHECK(nospaces(snowman(41114114)) == nospaces("___ \n(_*_)\n(.,.)\n( : )>\n(   )"));
    CHECK(nospaces(snowman(43211114)) == nospaces("___\n(_*_)\n(o_.)\n<( : )>\n(   )"));
    CHECK(nospaces(snowman(12341234)) == nospaces("_===_\n(O.-)/\n<(> <)\n(   )"));
    CHECK(nospaces(snowman(12311432)) == nospaces("_===_\n(O..)\n<(> <)\n(\" \")"));
    CHECK(nospaces(snowman(44444444)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
}

TEST_CASE("Check Base") {
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11111112)) == nospaces("_===_\n(.,.)\n<( : )>\n(\" \")"));
	CHECK(nospaces(snowman(11111113)) == nospaces("_===_\n(.,.)\n<( : )>\n(___)"));
	CHECK(nospaces(snowman(11111114)) == nospaces("_===_\n(.,.)\n<( : )>\n(   )"));	
}

TEST_CASE("Check Torso") {
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11111121)) == nospaces("_===_\n(.,.)\n<(] [)>\n( : )"));
	CHECK(nospaces(snowman(11111131)) == nospaces("_===_\n(.,.)\n<(> <)>\n( : )"));
	CHECK(nospaces(snowman(11111141)) == nospaces("_===_\n(.,.)\n<(   )>\n( : )"));
}

TEST_CASE("Check Right Hand") {
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11111211)) == nospaces("_===_\n(.,.)/\n<( : )\n( : )"));
	CHECK(nospaces(snowman(11111311)) == nospaces("_===_\n(.,.)\n<( : )\\\n( : )"));
	CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
}

TEST_CASE("Check Left Hand") {
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11112111)) == nospaces("_===_\n\\(.,.)\n( : )>\n( : )"));
	CHECK(nospaces(snowman(11113111)) == nospaces("_===_\n(.,.)\n/( : )>\n( : )"));
	CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
}

TEST_CASE("Check Right Eye") {
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11121111)) == nospaces("_===_\n(.,o)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11131111)) == nospaces("_===_\n(.,O)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11141111)) == nospaces("_===_\n(.,-)\n<( : )>\n( : )"));
}


TEST_CASE("Check Left Eye") {
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11211111)) == nospaces("_===_\n(o,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11311111)) == nospaces("_===_\n(O,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(11411111)) == nospaces("_===_\n(-,.)\n<( : )>\n( : )"));
}

TEST_CASE("Check Nose Eye") {
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(12111111)) == nospaces("_===_\n(...)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(13111111)) == nospaces("_===_\n(._.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(14111111)) == nospaces("_===_\n(. .)\n<( : )>\n( : )"));
}

TEST_CASE("Check Hat") {
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(21111111)) == nospaces("___\n.....\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(31111111)) == nospaces("_\n/_\\\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(41111111)) == nospaces("___\n(_*_)\n(.,.)\n<( : )>\n( : )"));
}


TEST_CASE("Short snowman code") {
	CHECK_THROWS(snowman(111));
	CHECK_THROWS(snowman(1233));
	CHECK_THROWS(snowman(14412));
	CHECK_THROWS(snowman(1112333));
	CHECK_THROWS(snowman(112231));
	CHECK_THROWS(snowman(12));
	CHECK_THROWS(snowman(4));
}

TEST_CASE("Long snowman code") {
	CHECK_THROWS(snowman(111111111));
	CHECK_THROWS(snowman(222222222));
	CHECK_THROWS(snowman(1111111111));
	CHECK_THROWS(snowman(123144412));
}

TEST_CASE("Out of bounds digits 5~9,0") {
	CHECK_THROWS(snowman(12345678));
	CHECK_THROWS(snowman(12211511));
	CHECK_THROWS(snowman(33361112));
	CHECK_THROWS(snowman(44444447));
	CHECK_THROWS(snowman(51234123));
	CHECK_THROWS(snowman(11223011));
}
