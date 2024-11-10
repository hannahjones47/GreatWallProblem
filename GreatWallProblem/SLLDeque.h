// SLLDeque.h
#ifndef SLLDEQUE_H
#define SLLDEQUE_H

#include <string>

struct Node {
    std::string data;
    Node* next;

    Node(const std::string& text) : data(text), next(nullptr) {}
};

class SLLDeque {
public:
    SLLDeque();                   
    ~SLLDeque();                

    void push_front(const std::string& text); 
    void push_back(const std::string& text);  
    void display(std::ostream& out) const;
    int getSize() const;
    Node* getHead() const;
    Node* getTail() const;

private:
    int size;
    Node* head; 
    Node* tail; 
};

#endif // SLLDEQUE_H
