#include "rbt.h"

// TODO: insert, remove

RBT::RBT() {
    // Initializing tree with null values.
    root = NULL;
    balance = 0;
}
RBT::~RBT() {
    while (!isEmpty()) {
        // TODO: delete all
    }
    root = NULL;
}

// These are the basic functions for a BBT
void RBT::insert(int data) {
    // TODO
    if(!has(data, root)){
        // sweep down the tree until finding the right spot
        // insert as son
        // rebalance
    }
}
void RBT::remove(int data) {
    // TODO
    Node<int>* r = seek(data, root);
    if (r) {
        // chek which son is bigger than father
        // that son takes it's place
    }

}
bool RBT::has(int data, Node<int>* startingNode) {
    return seek(data, startingNode) != NULL;
}
Node<int>* RBT::seek(int data, Node<int>* startingNode) {
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
void RBT::sweep(Node<int>* a) {
    if (a != NULL) {
        sweep(a->getLeft());
        sweep(a->getRight());
    }
}
int RBT::countNodes(Node<int>* a) {
    if (a != NULL) {
        return countNodes(a->getRight()) + countNodes(a->getLeft()) + 1;
    }
    return 0;
}
bool RBT::isLeaf(Node<int>* a) {
    if(a->getLeft() == NULL && a->getRight() == NULL) return true;
    return false;
}
bool RBT::isEmpty() {
    return (root==NULL);
}

// getter functions:
Node<int>* RBT::getRoot() {
    return root;
}
int RBT::getHeight(Node<int>* a) {
    if (a->getHeight() == -1) a->setHeight(std::max(getHeight(a->getLeft()), getHeight(a->getRight())) + 1);
    return a->getHeight();
}

// output
void RBT::print(Node<int>* a) {
    if (a != NULL) {
        std::cout << "" << a->getData() << "" << std::endl;
        print(a->getLeft());
        print(a->getRight());
    }
}
