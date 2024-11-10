// DualHashTable.h

#ifndef DUALHASHTABLE_H
#define DUALHASHTABLE_H

#include "HashTable.h"
#include <deque>
#include <stdexcept>
#include <string>

class DualHashTable {
public:
    // Constructor: Initialize with default capacity for both tables
    DualHashTable(int capacity = 10);

    // Method to insert a brick (north, south) into both hash tables
    void insert(const std::string& north, const std::string& south);

    // Method to look up the south symbol based on the north symbol
    std::string* lookupEast(const std::string& north) const;

    // Method to look up the north symbol based on the south symbol
    std::string* lookupWest(const std::string& south) const;

    // Method to get the first bucket from the east hash table for starting traversal
    Bucket* getFirstBucket() const;

    // Method to get the size of the hash tables
    int size() const;

    // Method to display the contents of the hash tables
    void display() const;

    HashTable getEastTravelTable() const { return eastTravelTable; }
    HashTable getWestTravelTable() const { return westTravelTable; }

private:
    // Two hash tables: one for eastward travel (north -> south) and one for westward travel (south -> north)
    HashTable eastTravelTable;  // For eastward travel (north -> south)
    HashTable westTravelTable;  // For westward travel (south -> north)
    int size_;

};

#endif // DUALHASHTABLE_H
