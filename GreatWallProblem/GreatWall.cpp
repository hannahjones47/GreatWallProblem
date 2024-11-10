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
        
        string north = line.substr(0, commaPosition);
        string south = line.substr(commaPosition + 1);
        unsortedBricks.insert(north, south);         
    }

    inputFile.close();
}

void GreatWall::sortBricks() {
    if (unsortedBricks.getFirstBucket() == nullptr) throw std::runtime_error("No bricks to sort.");

    // Step 1: Start with any brick (arbitrary start point)
    Bucket* startBucket = unsortedBricks.getFirstBucket();
    if (startBucket == nullptr) throw std::runtime_error("HashTable is empty.");

    string startNorthSymbol = startBucket->northSymbol;
    string startSouthSymbol = startBucket->southSymbol;

    // Step 2: Eastward Traversal (use the eastTravelTable)
    sortedBricks.push_back(startNorthSymbol);  // Start by adding the north symbol
    sortedBricks.push_back(startSouthSymbol);  // Then add the south symbol

    string currentSymbol = startSouthSymbol;
    
    // Traverse eastward by looking for the next brick with the current south symbol
    while (string* nextSouthSymbol = unsortedBricks.lookupEast(currentSymbol)) {
        sortedBricks.push_back(*nextSouthSymbol);  // Add the next south symbol
        currentSymbol = *nextSouthSymbol;  // Move to the next symbol
    }

    // todo cant i use this same while loop?

    // Step 3: Westward Traversal (use the westTravelTable)
    currentSymbol = startNorthSymbol;  // Reset to starting point for westward traversal

    while (true) {
        bool found = false;

        // Search for the brick that has currentSymbol as its south symbol in the westTravelTable
        std::string* westBrickNorthSymbol = unsortedBricks.lookupWest(currentSymbol);
        if (westBrickNorthSymbol != nullptr) {
            sortedBricks.push_front(*westBrickNorthSymbol);  // Add the north symbol to the front
            currentSymbol = *westBrickNorthSymbol;  // Move west to the new brick
            found = true;
        }

        if (!found) {
            // We have reached the westernmost brick
            break;
        }
    }
}

void GreatWall::displaySortedBricks() const {
    // Display all the sorted bricks in the list
    sortedBricks.display(cout);
}

string GreatWall::writeSortedBricksToFile() const 
{
    // todo
    return "";
}