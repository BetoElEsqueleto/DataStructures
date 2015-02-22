#ifndef NODE_H
#define NODE_H
/*
## Node class
Atomic element of two basic data structures: lists and binary trees.
Contains the following atributes:
1. next      -> Next node in list
2. prev      -> Previous node in list
3. parent    -> Parent node in binary tree
4. firstSon  -> Left side son node in binary tree
5. secondSon -> Right side son node in binary tree
*/

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
            // Initializing node with null values.
            data = content;
            next = prev = parent = firstSon = secondSon = NULL;
        }
        virtual ~node();
        
        // Returning the actual content of the node.
        T data() { return data; }

        // For every elemet of the node structure
        // there is a method to set and get it.
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
