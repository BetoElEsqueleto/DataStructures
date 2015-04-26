#include "avl.h"

AVL::AVL() {

}
AVL::~AVL() {

}

// These are the basic functions for a BBT
void AVL::insert(T data) {

}
// TODO: change this function
Node<T>* AVL::get(T data) {

}
void AVL::remove(T data) {

}
void AVL::seek(T data) {

}
void AVL::sweep() {

}

// getter functions:
Node<T>* AVL::getRoot() {
    return root;
}
int AVL::getLeft() {

}
int AVL::getRight() {

}
int AVL::getBalance() {

}

// setter functions:
void AVL::setRoot(Node<T>* newRoot) {

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
