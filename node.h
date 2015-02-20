#ifndef NODE_H
#define NODE_H

template <class T>
class node {
    private:
        T data;
        node<T>* next;
        node<T>* prev;
        node<T>* parent;
        node<T>* firstSon;
        node<T>* secondSon;
    public:
        node(T content) {
            data = content;
            next = prev = parent = firstSon = secondSon = NULL;
        }
        virtual ~node();
        T data() { return data; }
        node<T>* next() { return next; }
        node<T>* prev() { return prev; }
        node<T>* parent() { return parent; }
        node<T>* firstSon() { return firstSon; }
        node<T>* secondSon() { return secondSon; }
        void next(node<T>* ptr) { next = ptr; }
        void prev(node<T>* ptr) { prev = ptr; }
        void parent(node<T>* ptr) { parent = ptr; }
        void firstSon(node<T>* ptr) { firstSon = ptr; }
        void secondSon(node<T>* ptr) { secondSon = ptr; }
};
#endif // NODE_H
