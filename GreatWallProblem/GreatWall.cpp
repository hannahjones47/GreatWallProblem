#include "GreatWall.h"
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

GreatWall::GreatWall(const string& filePath) : inputDataPath(filePath), sorted(false) {
    readData();
}

void GreatWall::readData() {
    ifstream inputFile(inputDataPath);

    if (!inputFile.is_open()) throw runtime_error("Unable to open file: " + inputDataPath);
    
    string line;
    while (getline(inputFile, line)) 
    {
        size_t commaPosition = line.find(',');
        if (commaPosition == string::npos) throw runtime_error("Invalid input file format");
        
        string north = line.substr(0, commaPosition);
        string south = line.substr(commaPosition + 1);
        unsortedBricks.insert(north, south);         
    }

    inputFile.close();
}

void GreatWall::sortBricks() {
    if (sorted) return;
    if (unsortedBricks.getFirstBucket() == nullptr) throw runtime_error("No bricks to sort.");

    Bucket* startBucket = unsortedBricks.getFirstBucket();
    if (startBucket == nullptr) throw runtime_error("HashTable is empty.");

    string startNorthSymbol = startBucket->key;
    string startSouthSymbol = startBucket->value;

    sortedBricks.push_back(startNorthSymbol);  
    sortedBricks.push_back(startSouthSymbol);  

    string currentSymbol = startSouthSymbol;
    
    while (string* nextSouthSymbol = unsortedBricks.lookupEast(currentSymbol)) {
        sortedBricks.push_back(*nextSouthSymbol);  
        currentSymbol = *nextSouthSymbol; 
    }

    currentSymbol = startNorthSymbol; 

    while (string* nextNorthSymbol = unsortedBricks.lookupWest(currentSymbol)) {
        sortedBricks.push_front(*nextNorthSymbol);  
        currentSymbol = *nextNorthSymbol; 
    }

    sorted = true;
}

void GreatWall::displaySortedBricks(ostream& out) const {
    sortedBricks.display(out);
}
