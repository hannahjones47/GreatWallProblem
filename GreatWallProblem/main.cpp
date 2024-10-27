#include <iostream>
#include "GreatWall.h"
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    GreatWall wall("/Users/hannahjones/Git/GreatWallProblem/GreatWallProblem/GreatWallProblem/tests/TestData/20/input-pairs-20.txt"); // todo pass by console param
    wall.unsortedBricks.display();
    cout << "Goodbye, World!" << endl;
    return 0;
}