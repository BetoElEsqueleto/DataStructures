#include "bst.h"

// TODO: insert, remove

BST::BST() {
    // Initializing tree with null values.
    root = NULL;
    height = 0;
}
BST::~BST() {
    while (!isEmpty()) {
        remove(root);
    }
    root = NULL;
}

// These are the basic functions for a BBT
void BST::insert(int data) {
    if(!has(data, root)){
        // sweep down the tree until finding the right spot
        // insert as son
        // rebalance
    }
}
void BST::remove(Node<int>* r) {
    if (r) {
        // chek which son is bigger than father
        // that son takes it's place
    }

}
bool BST::has(int data, Node<int>* startingNode) {
    return seek(data, startingNode) != NULL;
}
Node<int>* BST::seek(int data, Node<int>* startingNode) {
    if (isEmpty()) return NULL;
    if (startingNode->getData() == data) return startingNode;
    if (data < startingNode->getData()) {
        if (startingNode->getLeft()) seek(data, startingNode->getLeft());
    }
    else {
        if (startingNode->getRight()) seek(data, startingNode->getRight());
    }
    return NULL;
}
void BST::sweep(Node<int>* a) {
    if (a != NULL) {
        sweep(a->getLeft());
        sweep(a->getRight());
    }
}
int BST::countNodes(Node<int>* a) {
    if (a != NULL) {
        return countNodes(a->getRight()) + countNodes(a->getLeft()) + 1;
    }
    return 0;
}
bool BST::isLeaf(Node<int>* a) {
    if(a->getLeft() == NULL && a->getRight() == NULL) return true;
    return false;
}
bool BST::isEmpty() {
    return (root==NULL);
}

// Balance methods
void BST::setLocalBalance(Node<int>* a) {
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
int BST::getLocalBalance(Node<int>* a) {
    return getHeight(a->getRight()) - getHeight(a->getLeft());
}
void BST::simpleRightRotation(Node<int>* a) {
    Node<int>* P = a;
    Node<int>* Q = a->getRight();
// Step 1
    Q->getRight()->setParent(P);
    P->setLeft(Q->getRight());
// Step 2
    Q->setRight(P);
    Q->setParent(P->getParent()); // For Step 3
    P->setParent(Q);
// Step 3
    if (Q->getParent() == NULL){
        root = Q;
    } else if (Q->getParent()->getRight() == P) {
        Q->getParent()->setRight(Q);
    } else {
        Q->getParent()->setLeft(Q);
    }
}
void BST::simpleLeftRotation(Node<int>* a) {
    Node<int>* P = a;
    Node<int>* Q = a->getLeft();
    // Step 1
    Q->getLeft()->setParent(P);
    P->setRight(Q->getLeft());
    // Step 2
    Q->setLeft(P);
    Q->setParent(P->getParent()); // For Step 3
    P->setParent(Q);
    // Step 3
    if (Q->getParent() == NULL){
        root = Q;
    } else if (Q->getParent()->getRight() == P) {
        Q->getParent()->setRight(Q);
    } else {
        Q->getParent()->setLeft(Q);
    }
}
void BST::doubleRightRotation(Node<int>* a) {

}
void BST::doubleLeftRotation(Node<int>* a) {

}

// getter functions:
Node<int>* BST::getRoot() {
    return root;
}
int BST::getTreeBalance() {
    return balance;
}
int BST::getHeight(Node<int>* a) {
    if (a->getHeight() == -1) a->setHeight(std::max(getHeight(a->getLeft()), getHeight(a->getRight())) + 1);
    return a->getHeight();
}

// setter functions:
void BST::setTreeBalance() {
    balance = getLocalBalance(root);
}
void BST::setTreeHeight() {
    height = getHeight(root);
}

// output
void BST::print(Node<int>* a) {
    if (a != NULL) {
        std::cout << "" << a->getData() << "" << std::endl;
        print(a->getLeft());
        print(a->getRight());
    }
}
