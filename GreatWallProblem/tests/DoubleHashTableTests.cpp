#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../include/DoubleHashTable.h"
#include <string>
#include <sstream>
using namespace std;

BOOST_AUTO_TEST_SUITE(DoubleHashTableUnitTests)

BOOST_AUTO_TEST_CASE(InsertionTest) {
    DoubleHashTable table;
    table.insert("north1", "south1");
    table.insert("north2", "south2");

    BOOST_CHECK_EQUAL(table.size(), 2);
}

BOOST_AUTO_TEST_CASE(LookupEastTest) {
    DoubleHashTable table;
    table.insert("north1", "south1");
    table.insert("north2", "south2");

    string* result = table.lookupEast("north1");
    BOOST_CHECK(result != nullptr);
    BOOST_CHECK_EQUAL(*result, "south1");

    result = table.lookupEast("north2");
    BOOST_CHECK(result != nullptr);
    BOOST_CHECK_EQUAL(*result, "south2");

    result = table.lookupEast("north3");
    BOOST_CHECK(result == nullptr);
}

BOOST_AUTO_TEST_CASE(LookupWestTest) {
    DoubleHashTable table;
    table.insert("north1", "south1");
    table.insert("north2", "south2");

    string* result = table.lookupWest("south1");
    BOOST_CHECK(result != nullptr);
    BOOST_CHECK_EQUAL(*result, "north1");

    result = table.lookupWest("south2");
    BOOST_CHECK(result != nullptr);
    BOOST_CHECK_EQUAL(*result, "north2");

    result = table.lookupWest("south3");
    BOOST_CHECK(result == nullptr);
}

BOOST_AUTO_TEST_CASE(GetFirstBucketTest) {
    DoubleHashTable table;
    table.insert("north1", "south1");
    table.insert("north2", "south2");

    Bucket* firstBucket = table.getFirstBucket();
    BOOST_CHECK(firstBucket != nullptr);
    BOOST_CHECK_EQUAL(firstBucket->key, "north1");
    BOOST_CHECK_EQUAL(firstBucket->value, "south1");
}

BOOST_AUTO_TEST_CASE(SizeTest) {
    DoubleHashTable table;
    BOOST_CHECK_EQUAL(table.size(), 0);

    table.insert("north1", "south1");
    BOOST_CHECK_EQUAL(table.size(), 1);

    table.insert("north2", "south2");
    BOOST_CHECK_EQUAL(table.size(), 2);
}

BOOST_AUTO_TEST_CASE(DisplayTest) {
    DoubleHashTable table;
    table.insert("north1", "south1");
    table.insert("north2", "south2");

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    table.display();
    cout.rdbuf(oldCout);

    string output = buffer.str();
    BOOST_CHECK(output.find("[North: north1, South: south1]") != string::npos);
    BOOST_CHECK(output.find("[North: north2, South: south2]") != string::npos);
}

BOOST_AUTO_TEST_SUITE_END()