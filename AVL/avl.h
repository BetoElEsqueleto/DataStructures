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

    // TODO: this next section has to be modified
    // These are the basic functions for a BBT
    void insert(int data);
    bool has(int data, Node<int>* startingNode);
    void remove(int data);
    Node<int>* seek(int data, Node<int>* startingNode);
    void sweep();
    int countNodes(Node<int>* a);
    bool isLeaf(Node<int>* a);

    // getter functions:
    Node<int>* getRoot();
    int getBalance();
    int getHeight();

    // setter functions:
    void setBalance(int newBalance);
    void setTreeHeight();

    bool isEmpty();
};
#endif
