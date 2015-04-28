#include "avl.h"

// TODO: insert, remove, setRoot

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
    if (a != NULL) {
        return countNodes(a->right) + countNodes(a->left) + 1;
    }
    return 0;
}
bool AVL::isLeaf(Node<int>* a) {
    if(a->left == NULL && a->right == NULL) return true;
    return false;
}
bool AVL::isEmpty(); {
    return (root==NULL);
}

// Balance methods
void AVL::setLocalBalance() {
    // Maybe would be better to send it to every node like the height
    balance = getHeight(root->right) - getHeight(root->left);
    // if (balance > 1 || balance < -1) setLocalBalance(root);
    // TODO: Balance must be [-1,0,1]
}

// getter functions:
// TODO: set root if root shifts
Node<int>* AVL::getRoot() {
    return root;
}
int AVL::getBalance() {
    setTreeBalance();
    return balance;
}
int AVL::getHeight(Node<int>* a) {
    if (a->getHeight == -1) a->setHeight(max(getHeight(a->left), getHeight(a->right)) + 1);
    return a->getHeight();
}

// setter functions:
void AVL::setTreeBalance() {
    balance = getHeight(root->right) - getHeight(root->left);
}
void AVL::setTreeHeight() {
    height = getHeight(root);
}
