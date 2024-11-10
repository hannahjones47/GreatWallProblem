#include "SLLDeque.h"
#include <iostream>

SLLDeque::SLLDeque() : head(nullptr), tail(nullptr), size(0) {}

SLLDeque::~SLLDeque() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void SLLDeque::push_front(const std::string& text) {
    Node* newNode = new Node(text);
    if (!head) {
        head = tail = newNode;  
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

void SLLDeque::push_back(const std::string& text) {
    Node* newNode = new Node(text);
    if (!tail) {
        head = tail = newNode;  
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void SLLDeque::display(std::ostream& out) const {
    Node* current = head;
    while (current) {
        out << current->data << "\n";
        current = current->next;
    }
}

int SLLDeque::getSize() const {
    return size;
}

Node* SLLDeque::getHead() const {
    return head;
}