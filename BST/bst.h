#ifndef BST_H
#define BST_H
#include "Node.h"
#include <iostream>
/*
## BST class
Binary Search Tree
Contains the following atributes:
1. root    -> Pointer to root node.
1. height  -> Height of the root node = Tree depth: longest path from the root to a leaf.

*/
using namespace bst;
class BST {
private:
    Node<int> *root;
    int height;
public:
    BST();
    ~BST();

    // These are the basic functions for a BBT
    void       insert(int data);
    void       remove(Node<int>* r);
    bool       has(int data, Node<int>* startingNode);
    Node<int>* seek(int data, Node<int>* startingNode);
    void       sweep(Node<int>* a);
    int        countNodes(Node<int>* a);
    bool       isLeaf(Node<int>* a);
    bool       isEmpty();

    // getter functions:
    Node<int>* getRoot();
    int        getHeight(Node<int>* a);
    int        getTreeHeight(Node<int>* a)

    // output
    void       print(Node<int>* a);
};
#endif // BST_H
