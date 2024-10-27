#include "HashTable.h"
#include <iostream>

#define LF_THRESHOLD .7

Bucket::Bucket(int k, string v, Bucket *n)
{
    key = k;
    value = v;
    next = n;
}

HashTable::HashTable(int c)
{
    capacity_ = c;
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

void HashTable::insert(int k, string v)
{
    if (loadFactor() > LF_THRESHOLD)
        rehash();

    unsigned int i = hash(k);
    Bucket *p = arr_[i];
    if (p == nullptr)
    {
        arr_[i] = new Bucket(k, v);
        size_++;
    }
    else
    {
        bool inserted = false;
        Bucket *b = nullptr;
        while (p != nullptr && !inserted)
        {
            if (p->key == k)
            {
                p->value = v;
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
            p = new Bucket(k, v);
            b->next = p;
            size_++;
        }
    }
}

string *HashTable::lookup(int k)
{
    unsigned int i = hash(k);
    string *r = nullptr;
    Bucket *p = arr_[i];
    bool found = false;
    while (p != nullptr && !found)
    {
        if (p->key == k)
        {
            r = &(p->value);
            found = true;
        }
        else
        {
            p = p->next;
        }
    }
    return r;
}

unsigned int HashTable::size()
{
    return size_;
}

unsigned int HashTable::hash(int k)
{
    return (k % capacity_);
}

float HashTable::loadFactor()
{
    return size_ / capacity_;
}

void HashTable::rehash()
{
    unsigned int oldCapacity = capacity_;
    Bucket **old_arr = arr_;

    capacity_ = capacity_ * 2;
    arr_ = new Bucket *[capacity_];

    for (int i = 0; i < oldCapacity; i++)
    {
        Bucket *p = old_arr[i];
        while (p != nullptr)
        {
            insert(p->key, p->value);
            Bucket *t = p;
            p = p->next;
            delete t;
        }
    }
    delete[] old_arr;
}