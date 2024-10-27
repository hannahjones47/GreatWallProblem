 #include "HashTable.h"
 #include <iostream>

#define LF_THRESHOLD .7

unsigned int HashTable::hash(int k) {
    return (k % capacity);
}

Bucket::Bucket(int k, string v, Bucket *n) {
    key   = k;
    value = v;
    next  = n;
}

Bucket *HashTable::deepCopy(Bucket *b) {

    if (b == nullptr)
        return nullptr;
    
    Bucket *n = deepCopy(b->next);
    Bucket *p = new Bucket(b->key, b->value, n);

    return p;
}

HashTable::HashTable(int c) {
    capacity = c;
    arr = new Bucket*[capacity];
    size_ = 0;
}

void HashTable::copy(const HashTable &d) {
    capacity = d.capacity;
    arr = new Bucket*[capacity];
    size_ = 0;
        
    for (int i = 0; i < capacity; i++) 
        arr[i] = deepCopy(d.arr[i]);
}
HashTable &HashTable::operator=(const HashTable &d) {
    
    if (this != &d) {
        this->~HashTable();
        copy(d);
    }

    return *this;
}

HashTable::HashTable(const HashTable &d) {
    copy(d);
}

HashTable::~HashTable() {

   for (int i = 0; i < capacity; i++) {
        Bucket* p = arr[i];
        while (p != nullptr) {
            Bucket *t = p;
            p = p->next;
            delete t; 
        }
   }

    delete [] arr;
}

void HashTable::insert(int k, string v) {

    if (loadFactor() > LF_THRESHOLD)
        rehash();

    unsigned int i = hash(k);
    Bucket *p = arr[i];
    if (p == nullptr) {
        arr[i] = new Bucket(k, v);
        size_++;
    }
    else {
        bool inserted = false;
        Bucket *b = nullptr;
        while (p != nullptr && !inserted) {
            if ( p->key == k) {
                p->value = v;
                inserted = true;
            }
            else {
                b = p;
                p = p->next;
            }
        }
        if (!inserted) {
            p = new Bucket(k, v);
            b->next = p;
            size_++; 
        }
    }
}

string* HashTable::lookup(int k) {

    unsigned int i = hash(k);

    string *r = nullptr;
    Bucket* p = arr[i];
    bool found = false;
    while(p!= nullptr && !found) {
        if (p->key == k) {
            r = &(p->value);
            found = true;
        }
        else {
            p = p->next;
        }
    }
    return r;
}

void HashTable::remove(int k) {

    int i = hash(k);

    Bucket *p = arr[i];
    Bucket *b = nullptr;
    bool removed = false;
    while (p!= nullptr && !removed) {
        if (p->key == k) {
            if (b != nullptr) {
                b->next = p->next;
            }
            else 
                arr[i] = p->next;
            delete p;
            removed = true;
            size_--;
        }
        else {
            b = p;
            p=p->next;
        }
    }
}

void HashTable::rehash() {
    unsigned int oldCapacity = capacity;
    Bucket **old_arr = arr;

    capacity = capacity*2;
    arr = new Bucket*[capacity];

    for (int i = 0; i < oldCapacity; i++) {
        Bucket *p = old_arr[i];
        while (p!= nullptr) {
            insert(p->key, p->value);
            Bucket *t = p;
            p = p->next;
            delete t;
        }
    }
    delete[] old_arr;
}

unsigned int HashTable::size() {
    return size_;
}

float HashTable::loadFactor() {
    return size_/capacity;
}