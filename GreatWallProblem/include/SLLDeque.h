#ifndef SLLDEQUE_H
#define SLLDEQUE_H
#include <string>
using namespace std;

struct Node {
  string data;
  Node* next;
  Node(const string& text) : data(text), next(nullptr) {}
};

// This class is adapted from the DLQueue implementation created in-class, found in the SOFT37002 module repository.
// Available at: https://olympus.ntu.ac.uk/CMP3RODRIN/ASE-DA/tree/main/S3-4_LinkedLists/DLQueue [Accessed 17 November 2024]
// Original author: Module Leader (Nuno Rodrigues Amálio)
// Key modifications: changed to singly linked list deque, replaced integer data with strings, removed bidirectional pointers, 
//                    added push_front/push_back, display and accessors for head/tail to suit the Great Wall Problem.
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
