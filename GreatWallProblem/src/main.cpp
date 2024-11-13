#include <iostream>
#include "../include/GreatWall.h"
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file_path>" << endl;
        return 1;
    }

    string filePath = argv[1];
    GreatWall wall(filePath);
    wall.sortBricks();
    wall.displaySortedBricks(cout);
    return 0;
}