#ifndef AVL_H
#define AVL_H
#include "Node.h"
#include <iostream>
/*
## AVL class
Adelson-Velskii & Landis Tree
Contains the following atributes:
1. root    -> Pointer to root node.
2. balance -> Difference between left and right side height.
3. height  -> Height of the root node = Tree depth: longest path from the root to a leaf.
*/
using namespace avln;
class AVL {
private:
    Node<int> *root;
    int balance;
    int height;
public:
    AVL();
    ~AVL();

    // These are the basic functions for a BBT
    void       insert(int data);
    void       remove(Node<int>* r);
    bool       has(int data, Node<int>* startingNode);
    Node<int>* seek(int data, Node<int>* startingNode);
    void       sweep(Node<int>* a);
    int        countNodes(Node<int>* a);
    bool       isLeaf(Node<int>* a);
    bool       isEmpty();


    // Balance methods
    void       setLocalBalance(Node<int>* a);
    int        getLocalBalance(Node<int>* a);
    void       simpleRightRotation(Node<int>* a);
    void       simpleLeftRotation(Node<int>* a);
    void       doubleRightRotation(Node<int>* a);
    void       doubleLeftRotation(Node<int>* a);

    // getter functions:
    Node<int>* getRoot();
    int        getTreeBalance();
    int        getHeight(Node<int>* a);

    // setter functions:
    void       setTreeBalance();
    void       setTreeHeight();

    // insert helpers
    Node<int>* findLeaf(int data, Node<int>* a);


    // output
    void       print(Node<int>* a);
};
#endif // AVL_H
