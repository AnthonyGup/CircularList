#include "Node.h"

Node::Node() {
    this->next = nullptr;
    this->value = 0;
}

void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setValue(int value) {
    this->value = value;
}

int Node::getValue() {
    return this->value;
}

Node* Node::getNext() {
    return this->next;
}