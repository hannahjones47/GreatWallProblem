// SLLDeque.h
#ifndef SLLDEQUE_H
#define SLLDEQUE_H

#include <string>

class SLLDeque {
public:
    SLLDeque();                   
    ~SLLDeque();                

    void push_front(const std::string& text); 
    void push_back(const std::string& text);  
    void display(std::ostream& out) const;

private:
    struct Node {
        std::string data;
        Node* next;

        Node(const std::string& text) : data(text), next(nullptr) {}
    };

    Node* head; 
    Node* tail; 
};

#endif // SLLDEQUE_H
