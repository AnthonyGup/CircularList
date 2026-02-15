#ifndef CIRCULAR_LIST_NODE_H
#define CIRCULAR_LIST_NODE_H

class Node {
private:
    int value;
    Node* next;

public:
    Node();
    void setValue(int value);
    void setNext(Node* next);
    int getValue();
    Node* getNext();
};

#endif