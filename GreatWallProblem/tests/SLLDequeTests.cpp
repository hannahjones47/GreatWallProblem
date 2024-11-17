#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../include/SLLDeque.h"
#include <string>
using namespace std;

BOOST_AUTO_TEST_SUITE(SLLDequeUnitTests)

BOOST_AUTO_TEST_CASE(PushFrontTest_Valid) {
    SLLDeque deque;
    deque.push_front("first");
    deque.push_front("second");
    deque.push_front("third");

    stringstream output;
    deque.display(output);
    BOOST_CHECK_EQUAL(output.str(), "third\nsecond\nfirst\n");
}

BOOST_AUTO_TEST_CASE(PushFrontTest_Invalid_EmptyString) {
    SLLDeque deque;
    BOOST_CHECK_THROW(deque.push_front(""), invalid_argument);
}

BOOST_AUTO_TEST_CASE(PushBackTest_Valid) {
    SLLDeque deque;
    deque.push_back("first");
    deque.push_back("second");
    deque.push_back("third");

    stringstream output;
    deque.display(output);
    BOOST_CHECK_EQUAL(output.str(), "first\nsecond\nthird\n");
}

BOOST_AUTO_TEST_CASE(PushBackTest_Invalid_EmptyString) {
    SLLDeque deque;
    BOOST_CHECK_THROW(deque.push_back(""), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(PushFrontAndBackTest_Valid) {
    SLLDeque deque;
    deque.push_back("first");
    deque.push_front("second");
    deque.push_back("third");
    deque.push_front("fourth");

    stringstream output;
    deque.display(output);
    BOOST_CHECK_EQUAL(output.str(), "fourth\nsecond\nfirst\nthird\n");
}

BOOST_AUTO_TEST_CASE(DisplayTest_Valid_Empty) {
    SLLDeque deque;
    
    stringstream output;
    deque.display(output);
    BOOST_CHECK_EQUAL(output.str(), "");
}

BOOST_AUTO_TEST_SUITE_END()
