#include "HashTable.h"
#include <iostream>
#include <functional> 

#define LF_THRESHOLD .7

Bucket::Bucket(string k, string v, Bucket *nextBucket) {
    key = k;
    value = v;
    next = nextBucket;
}

HashTable::HashTable(int capacity) : firstBucket_(nullptr) {
    capacity_ = capacity;
    arr_ = new Bucket *[capacity_];
    size_ = 0;
    for (int i = 0; i < capacity_; i++) {
        arr_[i] = nullptr; 
    }
}

HashTable::~HashTable() {
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

void HashTable::insert(string key, string value) {
    if (loadFactor() > LF_THRESHOLD) {
        rehash();
    }

    unsigned int hashIndex = hash(key);  
    Bucket* p = arr_[hashIndex];

    if (p == nullptr) {
        arr_[hashIndex] = new Bucket(key, value, nullptr);  
        size_++;

        if (firstBucket_ == nullptr) firstBucket_ = arr_[hashIndex];
    } else {
        bool inserted = false;
        Bucket* b = nullptr;

        while (p != nullptr && !inserted) {
            if (p->key == key) {
                p->value = value; 
                inserted = true;
            } else {
                b = p;
                p = p->next;
            }
        }

        if (!inserted) {
            p = new Bucket(key, value, nullptr);
            b->next = p;
            size_++;
        }
    }
}

string* HashTable::lookup(string symbol, bool isNorth) const {
    unsigned int index = hash(symbol); 
    Bucket* bucket = arr_[index];

    while (bucket != nullptr) {
        if (isNorth && bucket->key == symbol) {
            return new string(bucket->value); 
        } else if (!isNorth && bucket->value == symbol) {
            return new string(bucket->key); 
        }
        bucket = bucket->next;
    }
    return nullptr;
}

unsigned int HashTable::size() const {
    return size_;
}

unsigned int HashTable::hash(string key) const {
    std::hash<string> hasher;
    return hasher(key) % capacity_;
}

float HashTable::loadFactor() const {
    return static_cast<float>(size_) / static_cast<float>(capacity_);
}

void HashTable::rehash() {
    int oldCapacity = capacity_;
    capacity_ *= 2;
    Bucket** oldArr = arr_;
    arr_ = new Bucket*[capacity_];
    for (int i = 0; i < capacity_; ++i) 
    {
        arr_[i] = nullptr;
    }

    for (int i = 0; i < oldCapacity; ++i) 
    {
        Bucket* entry = oldArr[i];
        while (entry != nullptr) {
            Bucket* nextEntry = entry->next;  
            unsigned int newHashIndex = hash(entry->key);
            entry->next = arr_[newHashIndex];
            arr_[newHashIndex] = entry;

            entry = nextEntry;
        }
    }
    delete[] oldArr;
}

void HashTable::display() const {
    for (int i = 0; i < capacity_; ++i) {
        if (arr_[i] != nullptr) {
            std::cout << "Index " << i << ": ";
            Bucket* entry = arr_[i];
            while (entry != nullptr) {
                std::cout << "[North: " << entry->key << ", South: " << entry->value << "] ";
                entry = entry->next;
            }
            std::cout << std::endl;
        }
    }
}

Bucket* HashTable::getFirstBucket() const { 
    return firstBucket_; 
}
