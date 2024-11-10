#include "DualHashTable.h"
#include <iostream>

DualHashTable::DualHashTable(int capacity) : eastTravelTable(capacity), westTravelTable(capacity) {
    size_ = 0;
}

void DualHashTable::insert(const std::string& north, const std::string& south) {
    eastTravelTable.insert(north, south);
    westTravelTable.insert(south, north);
    size_++;
}

std::string* DualHashTable::lookupEast(const string& north) const {
    return eastTravelTable.lookup(north);
}

std::string* DualHashTable::lookupWest(const string& south) const {
    return westTravelTable.lookup(south);
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