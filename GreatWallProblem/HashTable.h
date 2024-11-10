#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
using namespace std;

struct Bucket {
    string northSymbol;
    string southSymbol;
    Bucket *next;
    Bucket(string, string, Bucket* = nullptr);
};

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
    string* lookup(string, bool) const;
    unsigned int size() const;
    float loadFactor() const;
    void display() const; 
    Bucket* getFirstBucket() const;
};

#endif // HASHTABLE_H