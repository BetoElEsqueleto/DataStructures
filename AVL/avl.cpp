#include "avl.h"

AVL::AVL() {
    // Initializing tree with null values.
    root = NULL;
    leftWeight = rightWeight = 0;
    balance = 0;
}
AVL::~AVL() {
    while (!isEmpty()) {
        // TODO: delete all
    }
    root = NULL;
}

// These are the basic functions for a BBT
void AVL::insert(int data) {

}
bool AVL::has(int data, Node<int>* startingNode) {
    if (isEmpty) return false;
    if (startingNode->data == data) return true;
    if (startingNode->left != NULL) has(data, startingNode->left);
    if (startingNode->right != NULL) has(data, startingNode->right);
    return false;
}
void AVL::remove(int data) {

}
Node<int>* AVL::seek(int data, Node<int>* startingNode) {
    if (isEmpty) return NULL;
    if (startingNode->data == data) return startingNode;
    has(data, startingNode->left);
    has(data, startingNode->right);
    return NULL;
}
void AVL::sweep(Node<int>* a) {
    if (a == NULL) return;
    sweep(a->left);
    sweep(a->right);
}

// getter functions:
Node<int>* AVL::getRoot() {
    return root;
}
int AVL::getLeftWeight() {

}
int AVL::getRightWeight() {

}
int AVL::getBalance() {

}

// setter functions:
void AVL::setRoot(Node<int>* newRoot) {

}
void AVL::setLeftWeight(int newLeftWeight) {

}
void AVL::setRightWeight(int newRightWeight) {

}
void AVL::setBalance(int newBalance) {

}

bool AVL::isEmpty(); {
    return (root==NULL);
}


// height = max(leftWeight, rightWeight)+1;
