#include <string>
using namespace std;

struct Bucket {
    int key;
    string value;
    Bucket *next;

    Bucket(int, string, Bucket* = nullptr);
};

class HashTable {
  public:
    HashTable(int = 10);
    ~HashTable();
    void insert(int, string);
    string* lookup(int);
    unsigned int size();

  private:
    unsigned int capacity_;
    unsigned int size_;
    Bucket** arr_;
    unsigned int hash(int);
    float loadFactor();
    void rehash();
};