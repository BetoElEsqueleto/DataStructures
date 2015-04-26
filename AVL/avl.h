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

template <class T>
class List {
private:
    Node<T> *root;
    int left;
    int right;
    int balance;
public:
    AVL();
    ~AVL();

    // TODO: this next section has to be modified
    void put(T data);
    void put(Node<T>* newNode);
    Node<T>* get(); // WHAT?
    void remove();
    void seek();
    void sweep();

    // getter functions:
    Node<T>* getRoot(); // { return root; }
    int getLeft();
    int getRight();
    int getBalance();

    // setter functions:
    void setRoot(Node<T>* newRoot);
    void setLeft(int newLeft);
    void setRight(int newRight);
    void setBalance(int newBalance);

    bool isEmpty(); // { return (root==NULL); }
};
#endif
