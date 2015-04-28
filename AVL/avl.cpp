#include "avl.h"

// TODO: insert, remove, setRoot, generalBalance
// rotations simple and double

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
void AVL::setLocalBalance(Node<int>* a) {
    // Maybe would be better to send it to every node like the height
    int localBalance = getLocalBalance(a);
    // TODO: missing conditionals for double rotations
    if (localBalance < -1){
        if (getLocalBalance(a->left) == -1) {
            simpleRightRotation(a);
        } else if (getLocalBalance(a->left) == 1) {
            doubleRightRotation(a);
        }
    }
    if (localBalance >  1) {
        if (getLocalBalance(a->right) == 1) {
            simpleLeftRotation(a);
        } else if (getLocalBalance(a->right) == -1) {
            doubleLeftRotation(a);
        }
    }
}
int AVL::getLocalBalance(Node<int>* a) {
    return getHeight(a->right) - getHeight(a->left);
}
void AVL::simpleRightRotation(Node<int>* a) {

}
void AVL::simpleLeftRotation(Node<int>* a) {

}
void AVL::doubleRightRotation(Node<int>* a) {

}
void AVL::doubleLeftRotation(Node<int>* a) {

}

// getter functions:
Node<int>* AVL::getRoot() {
    return root;
}
int AVL::getTreeBalance() {
    return setTreeBalance();
}
int AVL::getHeight(Node<int>* a) {
    if (a->getHeight == -1) a->setHeight(max(getHeight(a->left), getHeight(a->right)) + 1);
    return a->getHeight();
}

// setter functions:
void AVL::setTreeBalance() {
    balance = getLocalBalance(root);
}
void AVL::setTreeHeight() {
    height = getHeight(root);
}
