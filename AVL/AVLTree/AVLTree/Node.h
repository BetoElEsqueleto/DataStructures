#ifndef NODE_H
#define NODE_H
#include <iostream>
/*
 ## Node class for AVL trees
 Contains the following atributes:
 1. left      -> Pointer to Left side son.
 2. right     -> Pointer to Right side son.
 3. parent    -> Pointer to Parent node in binary tree.
 4. data      -> Data saved in tree.
 */
template <class T>
class Node {
private:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    int height;
    
public:
    Node(T content, Node<T>* init) {
        // Initializing node with null values.
        data = content;
        left = right = NULL;
        parent = init;
        height = -1;
    }
    ~Node() {
        parent = left = right = NULL;
    }
    
    // Returning the actual content of the node.
    T        getData() { return data; }
    
    // For every elemet of the node structure
    // there is a method to set and get it.
    Node<T>* getLeft() { return left; }
    Node<T>* getRight() { return right; }
    Node<T>* getParent() { return parent; }
    int      getHeight() { return height; }
    
    void     setLeft(Node<T>* ptr) { left = ptr; }
    void     setRight(Node<T>* ptr) { right = ptr; }
    void     setParent(Node<T>* ptr) { parent = ptr; }
    void     setHeight(int h) { height = h; }
    
};
#endif // NODE_H
