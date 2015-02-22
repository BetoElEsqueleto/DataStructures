#ifndef LIST_H
#define LIST_H
#include <node.h>
/*
## List class
With the actual structure of a doubly linked list.
Contains the following atributes:
1. head    -> Pointer to first or left-most node in list
2. tail    -> Pointer to last or right-most node in list
3. current -> Helper pointer to node being used in methods // TODO: currently unactive
4. size    -> Integer value representing the number of nodes in the list structure
*/

template <class T>
class list {
private:
    node<T> *head;
    node<T> *tail;
    node<T> *current;
    int size;
public:
    list () {
        // Initialize empty list
        size = 0;
        head = tail = current = NULL;
    }
    list (T data) {
        // Initialize list with one object
        size = 1;
        head = new node<T>(data);
        tail = head;
        newNodeP->prev(NULL);
        newNodeP->next(NULL);
    }
    virtual ~list () {
        // If list is not empty, pop it out.
        if(!isEmpty()) {
            while (head!=NULL) {
                pop();
            }
        }
    }

    // For every attribute in list, there is a getter function
    node<T>* head() { return head; }
    node<T>* tail() { return tail; }
    node<T>* current() { return current; }

    bool isEmpty() { return (head==NULL) }
    int size() {
        int len = 0;
        // TODO check if starting at 1 or 0
        node<T>* aux;
        for(aux=head;aux;aux = aux->next()) len++;
        size = len;
        return size;
    }
    /* TODO:
        search position
        overload []
        node<T>* find(T data);
    */
    void insertBack(T data) {
        node<T>* newNodeP;
        newNodeP = new node<T>(data);
        // TODO check for errors in memory asignment
        if (isEmpty()) {
            // If inserting first node:
            head = newNodeP;
            tail = newNodeP;
            newNodeP->prev(NULL);
            newNodeP->next(NULL);
            size=1;
        }
        else {
            // All nodes after the first:
            tail->next(newNodeP);
            newNodeP->prev(tail);
            newNodeP->next(NULL);
            tail = newNodeP;
            size++;
        }
    }
    void insertFront(T data) {
        node<T>* newNodeP;
        newNodeP = new node<T>(data);
        // TODO check for errors in memory asignment
        if (head==NULL) {
            // If inserting first node:
            head = newNodeP;
            tail = newNodeP;
            newNodeP->prev(NULL);
            newNodeP->next(NULL);
            size=1;
        }
        else {
            // All nodes after the first:
            head->prev(newNodeP);
            newNodeP->next(head);
            newNodeP->prev(NULL);
            head = newNodeP;
            size++;
        }
    }

    // Remove node by pointer: Used in pop functions
    bool removeNode(node<T>* unwanted) {
        unwanted->prev()->next(unwanted->next);
        unwanted->next()->prev(unwanted->prev);
        unwanted->next(NULL);
        unwanted->prev(NULL);
        delete cur;
    }

    // To push and pop from front and back
    void push(T data) {
        insertBack(T data);
    }
    data<T> pop() {
        if (isEmpty()) {
            return NULL;
        }
        else {
            data<T> popped;
            node<T>* unwanted;
            unwanted = tail;
            popped = unwanted->data();
            tail = tail->prev();
            tail->next(NULL);
            removeNode(unwanted);
            return popped;
        }
    }
    void pushHead(T data) {
        insertFront(T data);
    }
    data<T> popHead() {
        if (isEmpty()) {
            return NULL;
        }
        else {
            data<T> popped;
            node<T>* unwanted;
            popped = unwanted->data();
            unwanted = head;
            head = head->next();
            head->prev(NULL);
            removeNode(unwanted);
            return popped;
        }
    }

    // Whether list has an element containing data
    bool has(T data) {
        if (isEmpty()) {
            return false;
        }
        else {
            node<T>* cur;
            for(cur=head;cur;cur = cur->next()) {
                if(cur->data == data) return true;
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
            node<T>* cur;
            for(cur=head;cur;cur = cur->next()) {
                if(cur->data == data) {
                    cur->prev()->next(cur->next);
                    cur->next()->prev(cur->prev);
                    cur->next(NULL);
                    cur->prev(NULL);
                    delete cur;
                    return true;
                }
            }
            return false;
        }
    }

};
#endif
