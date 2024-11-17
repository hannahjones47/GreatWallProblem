#ifndef SLLDEQUE_H
#define SLLDEQUE_H
#include <string>
using namespace std;

struct Node {
  string data;
  Node* next;
  Node(const string& text) : data(text), next(nullptr) {}
};

class SLLDeque {
  public:
    SLLDeque();                   
    ~SLLDeque();                
    void push_front(const string& text); 
    void push_back(const string& text);  
    void display(ostream& out) const;
    int getSize() const;
    Node* getHead() const;
    Node* getTail() const;

  private:
    int size_;
    Node* head_; 
    Node* tail_; 
};

#endif // SLLDEQUE_H
