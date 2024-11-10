#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../SLLDeque.h"
#include <string>

using namespace std;

BOOST_AUTO_TEST_SUITE(SLLDequeUnitTests)

BOOST_AUTO_TEST_CASE(PushFrontTest) {
    SLLDeque deque;
    deque.push_front("first");
    deque.push_front("second");
    deque.push_front("third");

    stringstream output;
    deque.display(output);
    BOOST_CHECK_EQUAL(output.str(), "third\nsecond\nfirst\n");
}

BOOST_AUTO_TEST_CASE(PushBackTest) {
    SLLDeque deque;
    deque.push_back("first");
    deque.push_back("second");
    deque.push_back("third");

    stringstream output;
    deque.display(output);
    BOOST_CHECK_EQUAL(output.str(), "first\nsecond\nthird\n");
}

BOOST_AUTO_TEST_CASE(PushFrontAndBackTest) {
    SLLDeque deque;
    deque.push_back("first");
    deque.push_front("second");
    deque.push_back("third");
    deque.push_front("fourth");

    stringstream output;
    deque.display(output);
    BOOST_CHECK_EQUAL(output.str(), "fourth\nsecond\nfirst\nthird\n");
}

BOOST_AUTO_TEST_CASE(DisplayEmptyDequeTest) {
    SLLDeque deque;
    
    stringstream output;
    deque.display(output);
    BOOST_CHECK_EQUAL(output.str(), "");
}

BOOST_AUTO_TEST_SUITE_END()
