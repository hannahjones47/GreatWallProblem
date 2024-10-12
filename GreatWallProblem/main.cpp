#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
	BinarySearchTree bst;
    bst.insert(10, "ten");
    bst.insert(5, "five");
    bst.insert(15, "fifteen");

    bst.displayTree();
}