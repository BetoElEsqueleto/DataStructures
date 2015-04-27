#ifndef LIST_H
#define LIST_H
#include "node.h"
/*
## AVL clas
Adelson-Velskii & Landis Tree
Contains the following atributes:
1. root    -> Pointer to root node.
2. left    -> Height of left side sub-tree.
3. right   -> Height of right side sub-tree.
4. balance -> Difference between left and right side height.
*/

class List {
private:
    Node<int> *root;
    int left;
    int right;
    int balance;
public:
    AVL();
    ~AVL();

    // TODO: this next section has to be modified
    // These are the basic functions for a BBT
    void insert(int data);
    Node<int>* get(int data); // WHAT?
    void remove(int data);
    void seek(int data);
    void sweep();

    // getter functions:
    Node<int>* getRoot();
    int getLeft();
    int getRight();
    int getBalance();

    // setter functions:
    void setRoot(Node<int>* newRoot);
    void setLeft(int newLeft);
    void setRight(int newRight);
    void setBalance(int newBalance);

    bool isEmpty();
};
#endif
