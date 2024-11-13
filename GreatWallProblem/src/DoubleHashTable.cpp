#include "../include/DoubleHashTable.h"
#include <iostream>
using namespace std;

DoubleHashTable::DoubleHashTable(int capacity) : eastTravelTable(capacity), westTravelTable(capacity) {
    size_ = 0;
}

void DoubleHashTable::insert(const string& north, const string& south) {
    eastTravelTable.insert(north, south);
    westTravelTable.insert(south, north);
    size_++;
}

string* DoubleHashTable::lookupEast(const string& north) const {
    return eastTravelTable.lookup(north);
}

string* DoubleHashTable::lookupWest(const string& south) const {
    return westTravelTable.lookup(south);
}

Bucket* DoubleHashTable::getFirstBucket() const {
    return eastTravelTable.getFirstBucket();
}

int DoubleHashTable::size() const {
    return size_;
}

void DoubleHashTable::display() const {
    eastTravelTable.display();
}