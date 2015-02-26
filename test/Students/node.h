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
class Node {
    private:
        T data;
        Node<T>* next;
        Node<T>* prev;
        Node<T>* parent;
        Node<T>* firstSon;
        Node<T>* secondSon;

    public:
        Node(T content) {
            // Initializing node with null values.
            data = content;
            next = prev = parent = firstSon = secondSon = NULL;
        }
        virtual ~Node();

        // Returning the actual content of the node.
        T getData() { return data; }

        // For every elemet of the node structure
        // there is a method to set and get it.
        Node<T>* getNext() { return next; }
        Node<T>* getPrev() { return prev; }
        Node<T>* getParent() { return parent; }
        Node<T>* getFirstSon() { return firstSon; }
        Node<T>* getSecondSon() { return secondSon; }
        void setNext(Node<T>* ptr) { next = ptr; }
        void setPrev(Node<T>* ptr) { prev = ptr; }
        void setParent(Node<T>* ptr) { parent = ptr; }
        void setFirstSon(Node<T>* ptr) { firstSon = ptr; }
        void setSecondSon(Node<T>* ptr) { secondSon = ptr; }
};
#endif // NODE_H
