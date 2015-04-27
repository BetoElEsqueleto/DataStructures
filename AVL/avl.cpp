#include "avl.h"

AVL::AVL() {
    // Initializing tree with null values.
    root = NULL;
    left = right = 0;
    balance = 0;
}
AVL::~AVL() {
    while (!isEmpty()) {
        remove();
    }
    root = NULL;
}

// These are the basic functions for a BBT
void AVL::insert(int data) {

}
// TODO: change this function
Node<int>* AVL::get(int data) {

}
void AVL::remove(int data) {

}
void AVL::seek(int data) {

}
void AVL::sweep() {

}

// getter functions:
Node<int>* AVL::getRoot() {
    return root;
}
int AVL::getLeft() {

}
int AVL::getRight() {

}
int AVL::getBalance() {

}

// setter functions:
void AVL::setRoot(Node<int>* newRoot) {

}
void AVL::setLeft(int newLeft) {

}
void AVL::setRight(int newRight) {

}
void AVL::setBalance(int newBalance) {

}

bool AVL::isEmpty(); {
    return (root==NULL);
}
