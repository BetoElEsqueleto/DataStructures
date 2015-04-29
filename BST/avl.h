#ifndef AVL_H
#define AVL_H
#include "Node.h"
#include <iostream>
/*
## AVL class
Adelson-Velskii & Landis Tree
Contains the following atributes:
1. root    -> Pointer to root node.
2. leftWeight    -> Height of left side sub-tree.
3. rightWeight   -> Height of right side sub-tree.
4. balance -> Difference between left and right side height.
*/
using namespace bst;
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
    void       remove(int data);
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

    // output
    void       print(Node<int>* a);
};
#endif // AVL_H
