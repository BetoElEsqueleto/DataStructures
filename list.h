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
    list () { head = tail = NULL; }
    virtual ~list () {  if(!isEmpty()) deleteList(); }

    node<T>* head() { return head; }
    node<T>* tail() { return tail; }
    node<T>* current() { return current; }

    bool isEmpty() { return (head==NULL) }
    int size() {
        int len = 0;
        node<T>* aux;
        for(aux=head;aux;aux = aux->next()) len++;
        size = len;
        return size;
    }
    /* TODO:
        head -> inserts front  -- return node<T>*?
        tail -> inserts back
        push -> use insert back
        pop -> remove back, return back data

        frontPop
        frontPush -> head
    */
    void head(T data) {
        node<T>* newNodeP;
        newNodeP = new node<T>(data);
        // if inserting first node:
        if (head==NULL) {

        }
        else {
            /* code */
        }
    }
    void tail(T data) {
        node<T>* newNodeP;
        newNodeP = new node<T>(data);
        // if inserting first node:
        if (head==NULL) {

        }
        else {
            /* code */
        }
    }

};
#endif
