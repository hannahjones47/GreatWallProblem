// DualHashTable.cpp

#include "DualHashTable.h"
#include <iostream>

DualHashTable::DualHashTable(int capacity)
    : eastTravelTable(capacity), westTravelTable(capacity) {}

void DualHashTable::insert(const std::string& north, const std::string& south) {
    // Insert the north-south pair into the eastTravelTable (for eastward travel)
    eastTravelTable.insert(north, south);
    
    // Insert the south-north pair into the westTravelTable (for westward travel)
    westTravelTable.insert(south, north);

    size_++;
}

std::string* DualHashTable::lookupEast(const std::string& north) const {
    // Look up the south symbol for a given north symbol in the eastTravelTable
    return eastTravelTable.lookup(north, true);
}

std::string* DualHashTable::lookupWest(const std::string& south) const {
    // Look up the north symbol for a given south symbol in the westTravelTable
    return westTravelTable.lookup(south, false);
}

Bucket* DualHashTable::getFirstBucket() const {
    // Return the first bucket of the eastTravelTable for traversal
    return eastTravelTable.getFirstBucket();
}

int DualHashTable::size() const {
    return size_;
}

void DualHashTable::display() const {
    eastTravelTable.display();
}