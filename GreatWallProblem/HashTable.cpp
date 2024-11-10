#include "HashTable.h"
#include <iostream>
#include <functional> 

#define LF_THRESHOLD .7

Bucket::Bucket(string k, string v, Bucket *n)
{
    key = k;
    value = v;
    next = n;
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

void HashTable::insert(string key, string value)
{
    if (loadFactor() > LF_THRESHOLD)
        rehash();

    unsigned int hashIndex = hash(key);
    Bucket *p = arr_[hashIndex];
    if (p == nullptr)
    {
        arr_[hashIndex] = new Bucket(key, value);
        size_++;

        if (firstBucket_ == nullptr) firstBucket_ = arr_[hashIndex];
    }
    else
    {
        bool inserted = false;
        Bucket *b = nullptr;
        while (p != nullptr && !inserted)
        {
            if (p->key == key)
            {
                p->value = value;
                inserted = true;
            }
            else
            {
                b = p;
                p = p->next;
            }
        }
        if (!inserted)
        {
            p = new Bucket(key, value);
            b->next = p;
            size_++;
        }
    }
}

string *HashTable::lookup(string key) const // returns value of given key
{
    unsigned int hashIndex = hash(key);
    Bucket* entry = arr_[hashIndex];
    while (entry != nullptr) {
        if (entry->key == key) {
            return &(entry->value);
        }
        entry = entry->next;
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
            insert(entry->key, entry->value);
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
            cout << "Key: " << entry->key << ", Value: " << entry->value << endl;
            entry = entry->next;
        }
    }
}

Bucket* HashTable::getFirstBucket() const { 
    return firstBucket_; 
}
