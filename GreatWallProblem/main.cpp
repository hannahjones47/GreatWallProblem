#include <iostream>
#include "BinarySearchTree.h"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

using namespace std;

int main2() {
	BinarySearchTree bst;
    bst.insert(10, "ten");
    bst.insert(5, "five");
    bst.insert(15, "fifteen");

    bst.displayTree();
}