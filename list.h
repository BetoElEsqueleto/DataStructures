#ifndef LIST_H
#define LIST_H
#include <node.h>

template <class T>
class list {
private:
    node<T> *head;
    node<T> *tail;
    node<T> *current;
    int size;
public:
    list () {
        size = 0;
        head = tail = NULL;
    }
    virtual ~list () {
        if(!isEmpty()) {
            while (head!=NULL) {
                pop();
            }
        }
    }

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
        // if inserting first node:
            head = newNodeP;
            tail = newNodeP;
            newNodeP->prev(NULL);
            newNodeP->next(NULL);
            size=1;
        }
        else {
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
        // if inserting first node:
            head = newNodeP;
            tail = newNodeP;
            newNodeP->prev(NULL);
            newNodeP->next(NULL);
            size=1;
        }
        else {
            head->prev(newNodeP);
            newNodeP->next(head);
            newNodeP->prev(NULL);
            head = newNodeP;
            size++;
        }
    }
    void push(T data) {
        insertBack(T data);
    }
    node<T>* pop() {
        if (isEmpty()) {
            return NULL;
        }
        else {
            node<T>* popped;
            popped = tail;
            tail = tail->prev();
            tail->next(NULL);
            popped->prev(NULL);
            return popped;
        }
    }
    void pushHead(T data) {
        insertFront(T data);
    }
    node<T>* popHead() {
        if (isEmpty()) {
            return NULL;
        }
        else {
            node<T>* popped;
            popped = head;
            head = head->next();
            head->prev(NULL);
            popped->next(NULL);
            return popped;
        }
    }
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
    bool remove(T data) {
        if (isEmpty()) {
            return false;
        }
        else {
            node<T>* cur;
            for(cur=head;cur;cur = cur->next()) {
                if(cur->data == data) {
                    cur->prev->next = cur=>next;
                    cur->next->prev = cir->prev;
                    cur->next = cur->prev = NULL;
                    delete cur;
                    return true;
                }
            }
            return false;
        }
    }

};
#endif
