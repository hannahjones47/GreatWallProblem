#include "../include/SLLDeque.h"
#include <iostream>
using namespace std;

SLLDeque::SLLDeque() : head_(nullptr), tail_(nullptr), size_(0) {}

SLLDeque::~SLLDeque() {
    while (head_) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }
}

void SLLDeque::push_front(const string& text) {
    if (text.empty()) throw invalid_argument("Text must be non-empty.");

    Node* newNode = new Node(text);
    if (!head_) {
        head_ = tail_ = newNode;  
    } else {
        newNode->next = head_;
        head_ = newNode;
    }
    size_++;
}

void SLLDeque::push_back(const string& text) {
    if (text.empty()) throw invalid_argument("Text must be non-empty.");

    Node* newNode = new Node(text);
    if (!tail_) {
        head_ = tail_ = newNode;  
    } else {
        tail_->next = newNode;
        tail_ = newNode;
    }
    size_++;
}

void SLLDeque::display(ostream& out) const {
    Node* current = head_;
    while (current) {
        out << current->data << "\n";
        current = current->next;
    }
}

int SLLDeque::getSize() const {
    return size_;
}

Node* SLLDeque::getHead() const {
    return head_;
}

Node* SLLDeque::getTail() const {
    return tail_;
}