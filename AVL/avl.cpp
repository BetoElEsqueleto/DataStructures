#include "avl.h"

// TODO: insert, remove, setRoot, setBalance

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
    if (a != NULL) {
        sweep(a->left);
        sweep(a->right);
    }
}
int AVL::countNodes(Node<int>* a) {
    if (a == NULL) {
        return countNodes(a->right) + countNodes(a->left) + 1;
    }
}
bool AVL::isLeaf(Node<int>* a) {
    if(a->left == NULL && a->right == NULL) return true;
    return false;
}

// getter functions:
// TODO: set root if root shifts
Node<int>* AVL::getRoot() {
    return root;
}
int AVL::getBalance() {
    // setBalance();
    return balance;
}
int AVL::getHeight(Node<int>* a) {
    return max(getHeight(a->left), getHeight(a->right)) + 1;
}

// setter functions:
void AVL::setBalance() {
    balance = getHeight(root->right) - getHeight(root->left);
}
void AVL::setTreeHeight() {
    height = getHeight(root);
}

bool AVL::isEmpty(); {
    return (root==NULL);
}
// BALANCE must be [-1,0,1]
