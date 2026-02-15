#include "CircularList.h"
#include <iostream>

using namespace std;

CList::CList() {
    //TODO: something
    this->head = nullptr;
}

bool CList::isEmpty() {
    return this->head == nullptr;
}

int CList::getSize() {
    if (this->isEmpty()) return 0;

    int size = 1;
    Node* currentNode = this->head;

    while (currentNode->getNext() != this->head) {
        currentNode = currentNode->getNext();
        size++;
    }

    return size;
}

Node *CList::getTail() {
    if (this->isEmpty()) return nullptr;

    Node* currentNode = this->head;

    while (currentNode->getNext() != this->head) {
        currentNode = currentNode->getNext();
    }

    return currentNode;
}

void CList::insertFirst(int value) {

    Node* newNode = new Node();
    newNode->setValue(value);

    if (this->isEmpty()) {
        this->head = newNode;
        this->head->setNext(this->head);
        cout << "[INSERT FIRST] Valor " << value << " insertado al inicio" << endl;
        return;
    }

    Node* tail = this->getTail();

    newNode->setNext(this->head);
    this->head = newNode;
    tail->setNext(newNode);
    cout << "[INSERT FIRST] Valor " << value << " insertado al inicio" << endl;
}

void CList::insertAt(int value, int position) {
    if (this->isEmpty() || position == 0 || position == 1) {
        this->insertFirst(value);
        return;
    }

    // if (this->getSize() < position) {
    //     this->insertLast(value);
    //     return;
    // }

    Node* prevNode = this->getAt(position - 1);

    Node* newNode = new Node();
    newNode->setValue(value);
    newNode->setNext(prevNode->getNext());
    prevNode->setNext(newNode);
    cout << "[INSERT AT] Valor " << value << " insertado en posicion " << position << endl;
}

void CList::insertLast(int value) {
    if (this->isEmpty()) {
        this->insertFirst(value);
        return;
    }

    Node* tail = this->getTail();

    if (tail == nullptr) {
        cout << "[INSERT LAST] Error: tail no encontrado" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->setValue(value);
    tail->setNext(newNode);
    newNode->setNext(this->head);
    cout << "[INSERT LAST] Valor " << value << " insertado al final" << endl;
}

void CList::deleteAt(int position) {
    //Si esta vacio no se hace naa'
    if (this->isEmpty()) {
        cout << "[DELETE AT] Error: lista vacia" << endl;
        return;
    }

    if (position == 1 || position == 0) {
        this->deleteFirst();
        return;
    }

    //Si la posicion es mayor al tamaño de la lista, no se hace nada
    if (position > this->getSize()) {
        cout << "[DELETE AT] Error: posicion " << position << " fuera de rango" << endl;
        return;
    }
    //Se obtiene el nodo anterior al que se quiere eliminar y el nodo a eliminar
    Node* prevNode = this->getAt(position - 1);
    Node* nodeToDelete = prevNode->getNext();
    int deletedValue = nodeToDelete->getValue();
    // Se enlaza el nodo anterior con el siguiente al "nodo a eliminar" y se elimina el "nodo a eliminar"
    prevNode->setNext(nodeToDelete->getNext());
    delete nodeToDelete;
    cout << "[DELETE AT] Valor " << deletedValue << " eliminado en posicion " << position << endl;
}

void CList::deleteFirst() {
    //Se evalua si esta vacio
    if (this->isEmpty()) {
        cout << "[DELETE FIRST] Error: lista vacia" << endl;
        return;
    }

    int deletedValue = this->head->getValue();
    
    // Si solo hay un nodo
    if (this->head->getNext() == this->head) {
        delete this->head;
        this->head = nullptr;
        cout << "[DELETE FIRST] Valor " << deletedValue << " eliminado del inicio" << endl;
        return;
    }

    // Para cuando hay mas
    Node* tail = this->getTail();
    Node* nodeToDelete = this->head;
    
    this->head = this->head->getNext();
    tail->setNext(this->head);
    
    delete nodeToDelete;
    cout << "[DELETE FIRST] Valor " << deletedValue << " eliminado del inicio" << endl;
}

void CList::deleteLast() {
    if (this->isEmpty()) {
        cout << "[DELETE LAST] Error: lista vacia" << endl;
        return;
    }

    // Si solo hay un nodo
    if (this->head->getNext() == this->head) {
        int deletedValue = this->head->getValue();
        delete this->head;
        this->head = nullptr;
        cout << "[DELETE LAST] Valor " << deletedValue << " eliminado del final" << endl;
        return;
    }

    // Si hay más de un nodo
    Node* tail = this->getTail();
    int deletedValue = tail->getValue();
    Node* secondToLast = this->getAt(this->getSize() - 1); // Se obtiene el penultimo nodo
    
    secondToLast->setNext(this->head);
    
    delete tail;
    cout << "[DELETE LAST] Valor " << deletedValue << " eliminado del final" << endl;
}

Node *CList::getAt(int position) {
    if (this->isEmpty()) return nullptr;

    if (this->getSize() < position) return nullptr;

    Node* currentNode = this->head;
    int currentPosition = 1;

    while (currentPosition < position) {
        currentPosition++;
        currentNode = currentNode->getNext();
    }

    return currentNode;
}

void CList::print(int turns) {
    if (this->isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }

    Node* currentNode = this->head;
    int currentTurn = 0;

    while (currentTurn < turns) {
        cout << currentNode->getValue() << " -> ";

        if (currentNode->getNext() == this->head) {
            currentTurn++;
            cout << " <- ";
        }

        currentNode = currentNode->getNext();
    }

    cout << endl;
}