#include "../include/GreatWall.h"
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

GreatWall::GreatWall(const string& filePath) : inputDataPath_(filePath), sorted_(false) {
    readData();
}

void GreatWall::readData() {
    ifstream inputFile(inputDataPath_);

    if (!inputFile.is_open()) throw runtime_error("Unable to open file: " + inputDataPath_);
    
    string line;
    bool hasData = false;
    while (getline(inputFile, line)) 
    {
        size_t commaPosition = line.find(',');
        if (commaPosition == string::npos) throw runtime_error("Invalid input file format");
        
        string north = line.substr(0, commaPosition);
        string south = line.substr(commaPosition + 1);
        unsortedBricks_.insert(north, south);       
        hasData = true;  
    }

    inputFile.close();

    if (!hasData) throw runtime_error("Input file is empty: " + inputDataPath_);
}

void GreatWall::sortBricks() {
    if (sorted_) return;

    Bucket* startBucket = unsortedBricks_.getFirstBucket();
    if (startBucket == nullptr) throw runtime_error("No bricks to sort.");

    string startNorthSymbol = startBucket->key;
    string startSouthSymbol = startBucket->value;

    sortedBricks_.push_back(startNorthSymbol);  
    sortedBricks_.push_back(startSouthSymbol);  

    string currentSymbol = startSouthSymbol;
    
    while (string* nextSouthSymbol = unsortedBricks_.lookupEast(currentSymbol)) {
        sortedBricks_.push_back(*nextSouthSymbol);  
        currentSymbol = *nextSouthSymbol; 
    }

    currentSymbol = startNorthSymbol; 

    while (string* nextNorthSymbol = unsortedBricks_.lookupWest(currentSymbol)) {
        sortedBricks_.push_front(*nextNorthSymbol);  
        currentSymbol = *nextNorthSymbol; 
    }

    sorted_ = true;
}

void GreatWall::displaySortedBricks(ostream& out) const {
    if (!sorted_) {
        throw runtime_error("Bricks have not been sorted."); 
        return;
    }
    sortedBricks_.display(out);
}
