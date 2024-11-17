#include "../include/DoubleHashTable.h"
#include <iostream>
using namespace std;

DoubleHashTable::DoubleHashTable(int capacity) : eastTravelTable_(capacity), westTravelTable_(capacity) {
    size_ = 0;
}

void DoubleHashTable::insert(const string& north, const string& south) {
    eastTravelTable_.insert(north, south);
    westTravelTable_.insert(south, north);
    size_++;
}

string* DoubleHashTable::lookupEast(const string& north) const {
    return eastTravelTable_.lookup(north);
}

string* DoubleHashTable::lookupWest(const string& south) const {
    return westTravelTable_.lookup(south);
}

Bucket* DoubleHashTable::getFirstBucket() const {
    return eastTravelTable_.getFirstBucket();
}

int DoubleHashTable::size() const {
    return size_;
}

void DoubleHashTable::display(ostream& out) const {
    eastTravelTable_.display(out);
}