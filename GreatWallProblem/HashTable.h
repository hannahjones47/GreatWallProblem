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
    void insert(int, string);
    string* lookup(int);
    void remove(int); 
    HashTable(int = 10);
    HashTable(const HashTable &);
    unsigned int size();
    ~HashTable();
    HashTable & operator=(const HashTable&);

  private:
    unsigned int capacity;
    unsigned int size_;
    Bucket** arr;
    unsigned int hash(int);
    float loadFactor();
    void rehash();
    Bucket *deepCopy(Bucket*);
    void copy(const HashTable &);
};