#include "../include/HashTable.h"
#include <iostream>
#include <functional> 
using namespace std;
#define LF_THRESHOLD .7

Bucket::Bucket(string k, string v, Bucket *nextBucket) {
    key = k;
    value = v;
    next = nextBucket;
}

HashTable::HashTable(int capacity) : firstBucket_(nullptr) {
    if (capacity <= 0) throw invalid_argument("Capacity must be greater than 0.");
    capacity_ = capacity;
    arr_ = new Bucket *[capacity_];
    size_ = 0;
    for (int i = 0; i < capacity_; i++) {
        arr_[i] = nullptr; 
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity_; i++) {
        Bucket *p = arr_[i];
        while (p != nullptr) {
            Bucket *t = p;
            p = p->next;
            delete t;
        }
    }
    delete[] arr_;
}

void HashTable::insert(string key, string value) {
    if (key.empty() || value.empty()) throw invalid_argument("Key and value must be non-empty.");

    if (loadFactor() > LF_THRESHOLD) {
        rehash();
    }

    unsigned int hashIndex = hash(key);  
    Bucket* p = arr_[hashIndex];

    if (p == nullptr) {
        arr_[hashIndex] = new Bucket(key, value, nullptr);  
        if (!arr_[hashIndex]) throw bad_alloc();
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
            if (!p) throw bad_alloc();
            b->next = p;
            size_++;
        }
    }
}

string* HashTable::lookup(string symbol) const {
    if (symbol.empty()) throw invalid_argument("Symbol must be non-empty.");

    unsigned int index = hash(symbol); 
    Bucket* bucket = arr_[index];

    while (bucket != nullptr) {
        if (bucket->key == symbol) {
            return new string(bucket->value); 
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
    if (!arr_) throw bad_alloc();

    for (int i = 0; i < capacity_; ++i) {
        arr_[i] = nullptr;
    }

    for (int i = 0; i < oldCapacity; ++i) {
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

void HashTable::display(ostream& out) const {
    for (int i = 0; i < capacity_; ++i) {
        if (arr_[i] != nullptr) {
            out << "Index " << i << ": ";
            Bucket* entry = arr_[i];
            while (entry != nullptr) {
                out << "[North: " << entry->key << ", South: " << entry->value << "] ";
                entry = entry->next;
            }
            out << endl;
        }
    }
}

Bucket* HashTable::getFirstBucket() const { 
    return firstBucket_; 
}
