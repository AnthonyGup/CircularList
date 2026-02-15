#ifndef CIRCULAR_LIST_CLIST_H
#define CIRCULAR_LIST_CLIST_H

#include "Node.h"

class CList {
private:
    Node* head;
    // Node* tail;

public:
    CList();
    Node* getTail();
    int getSize();
    bool isEmpty();
    Node* getAt(int position);
    void insertFirst(int value);
    void insertLast(int value);
    void insertAt(int value, int position);
    void deleteFirst();
    void deleteLast();
    void deleteAt(int position);
    void print(int turns);

};

#endif