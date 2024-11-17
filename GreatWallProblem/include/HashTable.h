#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
using namespace std;

struct Bucket {
  string key;
  string value;
  Bucket *next;
  Bucket(string, string, Bucket* = nullptr);
};

// This class is adapted from the hash table implementation developed in-class, provided in the SOFT37002 module repository.
// Available at: https://olympus.ntu.ac.uk/CMP3RODRIN/ASE-DA/tree/main/S18-19_HT [Accessed 17 November 2024]
// Original author: Module Leader (Nuno Rodrigues Amálio)
// Key modifications: changed key type to string, added traversal support, reworked hashing, rehashing
//                    and lookup methods and added display functionality for the Great Wall Problem.
class HashTable {
  private:
    Bucket** arr_;
    Bucket* firstBucket_;
    unsigned int capacity_;
    unsigned int size_;
    unsigned int hash(string) const;
    void rehash();
    
  public:
    HashTable(int = 10);
    ~HashTable();
    void insert(string, string);
    string* lookup(string) const;
    unsigned int size() const;
    float loadFactor() const;
    void display(ostream& out) const; 
    Bucket* getFirstBucket() const;
};

#endif // HASHTABLE_H