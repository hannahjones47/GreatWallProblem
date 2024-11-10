#include "GreatWall.h"
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

GreatWall::GreatWall(const string& filePath) : inputDataPath(filePath) 
{
    readData();
}

void GreatWall::readData() 
{
    ifstream inputFile(inputDataPath);
    if (!inputFile.is_open()) 
        throw runtime_error("Unable to open file: " + inputDataPath);
    
    string line;
    while (getline(inputFile, line)) 
    {
        size_t commaPosition = line.find(',');
        if (commaPosition == string::npos) 
            throw runtime_error("Invalid input file format");
        
        string key = line.substr(0, commaPosition);
        string value = line.substr(commaPosition + 1);
        unsortedBricks.insert(key, value);         
    }

    inputFile.close();
}

void GreatWall::sortBricks() {
    
}

void GreatWall::displaySortedBricks() const 
{
    // todo
}

string GreatWall::writeSortedBricksToFile() const 
{
    // todo
    return "";
}