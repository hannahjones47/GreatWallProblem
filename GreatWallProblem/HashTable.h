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

class HashTable {
  private:
    Bucket** arr_;
    unsigned int capacity_;
    unsigned int size_;
    unsigned int hash(string);
    float loadFactor();
    void rehash();
  
  public:
    HashTable(int = 10);
    ~HashTable();
    void insert(string, string);
    string* lookup(string);
    unsigned int size();
    void display() const; 
};

#endif // HASHTABLE_H