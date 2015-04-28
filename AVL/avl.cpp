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
    if (startingNode->getData() == data) return true;
    if (startingNode->getLeft() != NULL) has(data, startingNode->getLeft());
    if (startingNode->getRight() != NULL) has(data, startingNode->getRight());
    return false;
}
void AVL::remove(int data) {

}
Node<int>* AVL::seek(int data, Node<int>* startingNode) {
    if (isEmpty) return NULL;
    if (startingNode->getData() == data) return startingNode;
    has(data, startingNode->getLeft());
    has(data, startingNode->getRight());
    return NULL;
}
void AVL::sweep(Node<int>* a) {
    if (a != NULL) {
        sweep(a->getLeft());
        sweep(a->getRight());
    }
}
int AVL::countNodes(Node<int>* a) {
    if (a != NULL) {
        return countNodes(a->getRight()) + countNodes(a->getLeft()) + 1;
    }
    return 0;
}
bool AVL::isLeaf(Node<int>* a) {
    if(a->getLeft() == NULL && a->getRight() == NULL) return true;
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
        if (getLocalBalance(a->getLeft()) == -1) {
            simpleRightRotation(a);
        } else if (getLocalBalance(a->getLeft()) == 1) {
            doubleRightRotation(a);
        }
    }
    if (localBalance >  1) {
        if (getLocalBalance(a->getRight()) == 1) {
            simpleLeftRotation(a);
        } else if (getLocalBalance(a->getRight()) == -1) {
            doubleLeftRotation(a);
        }
    }
}
int AVL::getLocalBalance(Node<int>* a) {
    return getHeight(a->getRight()) - getHeight(a->getLeft());
}
void AVL::simpleRightRotation(Node<int>* a) {
    Node<int>* P = a;
    Node<int>* Q = a->getRight();
// Step 1
    Q->getRight()->setParent(P);
    P->setLeft(Q->getRight());
// Step 2
    Q->setRight(P);
    Q->setParent(P->getParent); // For Step 3
    P->setParent(Q);
// Step 3
    if (Q->getParent() == NULL){
        root = Q;
    } else if (Q->getParent()->getRight() == P) {
        Q->getParent()->setRight(Q);
    } else (Q->getParent()->getLeft() == P) {
        Q->getParent()->setLeft(Q);
    }
}
void AVL::simpleLeftRotation(Node<int>* a) {
    Node<int>* P = a;
    Node<int>* Q = a->getLeft();
    // Step 1
    Q->getLeft()->setParent(P);
    P->setRight(Q->getLeft());
    // Step 2
    Q->setLeft(P);
    Q->setParent(P->getParent); // For Step 3
    P->setParent(Q);
    // Step 3
    if (Q->getParent() == NULL){
        root = Q;
    } else if (Q->getParent()->getRight() == P) {
        Q->getParent()->setRight(Q);
    } else (Q->getParent()->getLeft() == P) {
        Q->getParent()->setLeft(Q);
    }
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
    if (a->getHeight == -1) a->setHeight(max(getHeight(a->getLeft()), getHeight(a->getRight())) + 1);
    return a->getHeight();
}

// setter functions:
void AVL::setTreeBalance() {
    balance = getLocalBalance(root);
}
void AVL::setTreeHeight() {
    height = getHeight(root);
}

// output
void AVL::print() {

}
