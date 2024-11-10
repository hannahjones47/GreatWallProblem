#include "HashTable.h"
#include <iostream>
#include <functional> 

#define LF_THRESHOLD .7

Bucket::Bucket(string north, string south, Bucket *nextBucket)
{
    northSymbol = north;
    southSymbol = south;
    next = nextBucket;
}

HashTable::HashTable(int capacity)
{
    capacity_ = capacity;
    arr_ = new Bucket *[capacity_];
    size_ = 0;
}

HashTable::~HashTable()
{
    for (int i = 0; i < capacity_; i++)
    {
        Bucket *p = arr_[i];
        while (p != nullptr)
        {
            Bucket *t = p;
            p = p->next;
            delete t;
        }
    }
    delete[] arr_;
}

void HashTable::insert(string north, string south) {
    if (loadFactor() > LF_THRESHOLD) {
        rehash();
    }

    unsigned int hashIndex = hash(north);  // Use north symbol to hash
    Bucket* p = arr_[hashIndex];

    if (p == nullptr) {
        arr_[hashIndex] = new Bucket(north, south);  
        size_++;

        if (firstBucket_ == nullptr) 
            firstBucket_ = arr_[hashIndex];
    } else {
        bool inserted = false;
        Bucket* b = nullptr;

        // Traverse the bucket to see if we already have the key
        while (p != nullptr && !inserted) {
            if (p->northSymbol == north) {
                p->southSymbol = south;  // Ensure both north and south symbols are set
                inserted = true;
            } else {
                b = p;
                p = p->next;
            }
        }

        if (!inserted) {
            p = new Bucket(north, south);
            b->next = p;
            size_++;
        }
    }
}

string* HashTable::lookup(string symbol, bool isNorth) const {
    unsigned int index = hash(symbol);  // Still use north's hash for simplicity
    Bucket* bucket = arr_[index];

    while (bucket != nullptr) {
        // If looking for north, return south, if looking for south, return north
        if (isNorth && bucket->northSymbol == symbol) {
            return new string(bucket->southSymbol);  // Return the south symbol
        } else if (!isNorth && bucket->southSymbol == symbol) {
            return new string(bucket->northSymbol);  // Return the north symbol
        }
        bucket = bucket->next;
    }
    return nullptr;
}

unsigned int HashTable::size() const
{
    return size_;
}

unsigned int HashTable::hash(string key) const
{
    std::hash<string> hasher;
    return hasher(key) % capacity_;
}

float HashTable::loadFactor() const 
{
    return static_cast<float>(size_) / static_cast<float>(capacity_);
}

void HashTable::rehash() {
    int oldCapacity = capacity_;
    capacity_ *= 2;
    Bucket** oldArr = arr_;
    arr_ = new Bucket*[capacity_];
    for (int i = 0; i < capacity_; ++i) {
        arr_[i] = nullptr;
    }

    size_ = 0;
    for (int i = 0; i < oldCapacity; ++i) {
        Bucket* entry = oldArr[i];
        while (entry != nullptr) {
            insert(entry->northSymbol, entry->southSymbol);
            Bucket* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] oldArr;
}

void HashTable::display() const {
    for (int i = 0; i < capacity_; ++i) {
        Bucket* entry = arr_[i];
        while (entry != nullptr) {
            cout << "North: " << entry->northSymbol << ", South: " << entry->southSymbol << endl;
            entry = entry->next;
        }
    }
}

Bucket* HashTable::getFirstBucket() const { 
    return firstBucket_; 
}
