#ifndef LIST_H
#define LIST_H
#include "node.h"
/*
## AVL clas
Adelson-Velskii & Landis Tree
Contains the following atributes:
1. root    -> Pointer to root node.
2. leftWeight    -> Height of left side sub-tree.
3. rightWeight   -> Height of right side sub-tree.
4. balance -> Difference between left and right side height.
*/

class List {
private:
    Node<int> *root;
    int balance;
    int height;
public:
    AVL();
    ~AVL();

    // These are the basic functions for a BBT
    void       insert(int data);
    bool       has(int data, Node<int>* startingNode);
    void       remove(int data);
    Node<int>* seek(int data, Node<int>* startingNode);
    void       sweep();
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
    void       setLocalBalance(Node<int>* a);

};
#endif
