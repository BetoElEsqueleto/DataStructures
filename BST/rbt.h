#ifndef RBT_H
#define RBT_H
#include "Node.h"
#include <iostream>
/*
## RBT class
Red-Black Trees
Contains the following atributes:
1. root    -> Pointer to root node.
2. height  -> Height of the root node = Tree depth: longest path from the root to a leaf.

*/
using namespace rbtn;
class RBT {
private:
    Node<int> *root;
    int height;
public:
    RBT();
    ~RBT();

    // These are the basic functions for a BST
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
    int        getTreeHeight(Node<int>* a);


    // output
    void       print(Node<int>* a);
};
#endif // RBT_H
