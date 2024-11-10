#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../HashTable.h"
#include <string>

using namespace std; // todo dual hash table tests.

BOOST_AUTO_TEST_SUITE(HashTableUnitTests)

BOOST_AUTO_TEST_CASE(InsertionTest) {
    HashTable table;
    table.insert("key1", "value1");
    table.insert("key2", "value2");

    const string* value1 = table.lookup("key1");
    BOOST_CHECK(value1 != nullptr);
    BOOST_CHECK_EQUAL(*value1, "value1");

    const string* value2 = table.lookup("key2");
    BOOST_CHECK(value2 != nullptr);
    BOOST_CHECK_EQUAL(*value2, "value2");
}

BOOST_AUTO_TEST_CASE(LookupTest) {
    HashTable table;
    table.insert("key1", "value1");

    const string* value = table.lookup("key1");
    BOOST_CHECK(value != nullptr);
    BOOST_CHECK_EQUAL(*value, "value1");

    const string* nonExistentValue = table.lookup("nonexistent");
    BOOST_CHECK(nonExistentValue == nullptr);
}

BOOST_AUTO_TEST_CASE(DuplicateKeyTest) {
    HashTable table;
    table.insert("key1", "value1");
    table.insert("key1", "value2"); 

    const string* value = table.lookup("key1");
    BOOST_CHECK(value != nullptr);
    BOOST_CHECK_EQUAL(*value, "value2"); 
}

BOOST_AUTO_TEST_CASE(RehashTest) {
    HashTable table(2); 
    table.insert("key1", "value1");
    table.insert("key2", "value2");
    table.insert("key3", "value3");

    const string* value1 = table.lookup("key1");
    BOOST_CHECK(value1 != nullptr);
    BOOST_CHECK_EQUAL(*value1, "value1");

    const string* value2 = table.lookup("key2");
    BOOST_CHECK(value2 != nullptr);
    BOOST_CHECK_EQUAL(*value2, "value2");

    const string* value3 = table.lookup("key3");
    BOOST_CHECK(value3 != nullptr);
    BOOST_CHECK_EQUAL(*value3, "value3");
}

BOOST_AUTO_TEST_CASE(LoadFactorTest) {
    HashTable table(2); 
    table.insert("key1", "value1");
    table.insert("key2", "value2");

    BOOST_CHECK_CLOSE(table.loadFactor(), 1.0, 0.01); 

    table.insert("key3", "value3"); 
    BOOST_CHECK_CLOSE(table.loadFactor(), 0.75, 0.01); 
}

BOOST_AUTO_TEST_SUITE_END()