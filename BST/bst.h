#ifndef BST_H
#define BST_H
#include "Node.h"
#include <iostream>
/*
## BST class
Binary Search Tree
Contains the following atributes:
1. root    -> Pointer to root node.
2. leftWeight    -> Height of left side sub-tree.
3. rightWeight   -> Height of right side sub-tree.
4. balance -> Difference between left and right side height.
*/
using namespace bst;
class BST {
private:
    Node<int> *root;
    int balance;
    int height;
public:
    BST();
    ~BST();

    // These are the basic functions for a BBT
    void       insert(int data);
    void       remove(int data);
    bool       has(int data, Node<int>* startingNode);
    Node<int>* seek(int data, Node<int>* startingNode);
    void       sweep(Node<int>* a);
    int        countNodes(Node<int>* a);
    bool       isLeaf(Node<int>* a);
    bool       isEmpty();

    // getter functions:
    Node<int>* getRoot();
    int        getTreeBalance();
    int        getHeight(Node<int>* a);

    // setter functions:
    void       setTreeBalance();
    void       setTreeHeight();

    // output
    void       print(Node<int>* a);
};
#endif // BST_H
