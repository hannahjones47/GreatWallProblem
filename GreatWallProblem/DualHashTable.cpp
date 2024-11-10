// DualHashTable.cpp

#include "DualHashTable.h"
#include <iostream>

DualHashTable::DualHashTable(int capacity)
    : eastTravelTable(capacity), westTravelTable(capacity) {}

void DualHashTable::insert(const std::string& north, const std::string& south) {
    eastTravelTable.insert(north, south);
    westTravelTable.insert(south, north);
    size_++;
}

std::string* DualHashTable::lookupEast(const std::string& north) const {
    return eastTravelTable.lookup(north, true);
}

std::string* DualHashTable::lookupWest(const std::string& south) const {
    return westTravelTable.lookup(south, false);
}

Bucket* DualHashTable::getFirstBucket() const {
    return eastTravelTable.getFirstBucket();
}

int DualHashTable::size() const {
    return size_;
}

void DualHashTable::display() const {
    eastTravelTable.display();
}