#ifndef LIST_H
#define LIST_H
#include "Node.h"
/*
## List class
With the actual structure of a doubly linked list.
Contains the following atributes:
1. head    -> Pointer to first or left-most node in list
2. tail    -> Pointer to last or right-most node in list
3. current -> Helper pointer to node being used in methods
4. size    -> Integer value representing the number of nodes in the list structure
*/

template <class T>
class List {
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *current;
    int size;
public:
    List () {
        // Initialize empty list
        size = 0;
        head = tail = current = NULL;
    }
    List (T data) {
        // Initialize list with one object
        size = 1;
        head = new Node<T>(data);
        tail = head;
        head->setPrev(NULL);
        head->setNext(NULL);
    }
    ~List () {
        // If list is not empty, pop it out.
        if(!isEmpty()) {
            while (head!=NULL) {
                pop();
            }
        }
    }

    // For every attribute in list, there is a getter function
    Node<T>* getHead() { return head; }
    Node<T>* getTail() { return tail; }
    Node<T>* getCurrent() { return current; }

    bool isEmpty() { return (head==NULL); }
    int getSize() {
        int len = 0;
        // TODO check if starting at 1 or 0
        Node<T>* aux;
        for(aux=head;aux;aux = aux->getNext()) len++;
        size = len;
        return size;
    }

    // Returns pointer to first node with data
    Node<T>* search(T data) {
        if (isEmpty()) {
            return NULL;
        }
        else {
            for(current=head;current;current = current->getNext()) {
                if(current->getData() == data) {
                    current = NULL;
                    return current;
                }
            }
            return NULL;
        }
    }

    // Inserts data at specified place in list. Index starts at 0
    bool insertAt(T data, int index) {
        if (isEmpty()) {
            return false;
        }
        else {
            current = head; // current = 0
            for(int i=1; i<index ; i++) {
                current = current->getNext();
            }
            Node<T>* aux;
            aux = new Node<T>(data);
            // TODO check for errors in memory asignment
            current->getPrev()->setNext(aux);
            current->setPrev(aux);
            aux->setNext(current);
            aux->setPrev(current->getPrev());
            current = NULL;
            return true;
        }
    }

    void insertBack(T data) {
        Node<T>* newNodeP;
        newNodeP = new Node<T>(data);
        // TODO check for errors in memory asignment
        if (newNodeP == NULL) std::cerr << "Error creating new node"<< std::endl;
        if (isEmpty()) {
            // If inserting first node:
            head = newNodeP;
            tail = newNodeP;
            newNodeP->setPrev(NULL);
            newNodeP->setNext(NULL);
            size=1;
        }
        else {
            // All nodes after the first:
            tail->setNext(newNodeP);
            newNodeP->setPrev(tail);
            newNodeP->setNext(NULL);
            tail = newNodeP;
            size++;
        }
    }
    void insertFront(T data) {
        Node<T>* newNodeP;
        newNodeP = new Node<T>(data);
        // TODO check for errors in memory asignment
        if (head==NULL) {
            // If inserting first node:
            head = newNodeP;
            tail = newNodeP;
            newNodeP->setPrev(NULL);
            newNodeP->setNext(NULL);
            size=1;
        }
        else {
            // All nodes after the first:
            head->setPrev(newNodeP);
            newNodeP->setNext(head);
            newNodeP->setPrev(NULL);
            head = newNodeP;
            size++;
        }
    }

    // Remove node by pointer: Used in pop functions
    void clearSides(Node<T>* dirty) {
        if(dirty->getNext()) dirty->setNext(NULL);
        if(dirty->getPrev()) dirty->setPrev(NULL);
    }

    // To push and pop from front and back
    void push(T data) {
        insertBack(data);
    }
    Node<T>* pop() {
        if (isEmpty()) {
             return NULL;
        }
        else if (getSize() == 1) {
            Node<T>* popped;
            popped = tail;
            clearSides(tail);
            clearSides(popped);
            size--;
            head = tail = NULL;
            return popped;
        }
        else {
            Node<T>* popped;
            popped = tail;
            tail = tail->getPrev();
            tail->setNext(NULL);
            clearSides(popped);
            size--;
            return popped;
        }
    }
    void pushHead(T data) {
        insertFront(data);
    }
    Node<T>* popHead() {
        if (isEmpty()) {
            return NULL;
        } else if (getSize() == 1) {
            Node<T>* popped;
            popped = head;
            clearSides(head);
            clearSides(popped);
            size--;
            head = tail = NULL;
            return popped;
        }
        else {
            Node<T>* popped;
            popped = head;
            head = head->getNext();
            head->setPrev(NULL);
            clearSides(popped);
            size--;
            return popped;
        }
    }

    // Whether list has an element containing data
    bool has(T data) {
        if (isEmpty()) {
            return false;
        }
        else {
            for(current=head;current;current = current->getNext()) {
                if(current->getData() == data) {
                    current = NULL;
                    return true;
                }
            }
            return false;
        }
    }

    // Remove the first element containing data
    bool remove(T data) {
        if (isEmpty()) {
            return false;
        }
        else {
            for(current=head;current;current = current->getNext()) {
                if(current->getData() == data) {
                    current->getPrev()->setNext(current->getNext());
                    current->getNext()->setPrev(current->getPrev());
                    current->setNext(NULL);
                    current->setPrev(NULL);
                    delete current;
                    current = NULL;
                    return true;
                }
            }
            return false;
        }
    }
    
    int indexOf(T data) {
        if (isEmpty()) {
            return -1;
        }
        else {
            int index = 0;
            for(current=head;current;current = current->getNext()) {
                if(current->getData() == data) {
                    return index;
                }
                index++;
            }
            return -1;
        }
    }

    /*
    TODO:
        overload []
    */
};
#endif
