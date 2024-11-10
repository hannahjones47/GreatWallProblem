// DualHashTable.h

#ifndef DUALHASHTABLE_H
#define DUALHASHTABLE_H

#include "HashTable.h"
#include <deque>
#include <stdexcept>
#include <string>

class DualHashTable {
public:
    DualHashTable(int capacity = 10);
    void insert(const string& north, const string& south);
    string* lookupEast(const string& north) const;
    string* lookupWest(const string& south) const;
    Bucket* getFirstBucket() const;
    int size() const;
    void display() const;

    HashTable getEastTravelTable() const { return eastTravelTable; }
    HashTable getWestTravelTable() const { return westTravelTable; }

private:
    HashTable eastTravelTable;  // for eastward travel (north -> south)
    HashTable westTravelTable;  // for westward travel (south -> north)
    int size_;

};

#endif // DUALHASHTABLE_H
