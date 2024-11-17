#ifndef DOUBLEHASHTABLE_H
#define DOUBLEHASHTABLE_H
#include "HashTable.h"
#include <string>

class DoubleHashTable {
  public:
    DoubleHashTable(int capacity = 10);
    void insert(const string& north, const string& south);
    string* lookupEast(const string& north) const;
    string* lookupWest(const string& south) const;
    Bucket* getFirstBucket() const;
    int size() const;
    void display(ostream& out) const;
    HashTable getEastTravelTable() const { return eastTravelTable_; }
    HashTable getWestTravelTable() const { return westTravelTable_; }

  private:
    HashTable eastTravelTable_;  // for eastward travel (north -> south)
    HashTable westTravelTable_;  // for westward travel (south -> north)
    int size_;

};

#endif // DOUBLEHASHTABLE_H
