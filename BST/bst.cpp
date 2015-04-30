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
        Node<int>* p = findLeaf(data, root);
        if(!p) {
            root = new Node<int>(data, NULL);
        } else {
            Node<int>* n = new Node<int>(data, p);
            if (p->getData() > data) {
                p->setLeft(n);
            } else {
                p->setRight(n);
            }
        }
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

// getter functions:
Node<int>* BST::getRoot() {
    return root;
}
int BST::getHeight(Node<int>* a) {
    if (a->getHeight() == -1) a->setHeight(std::max(getHeight(a->getLeft()), getHeight(a->getRight())) + 1);
    return a->getHeight();
}
int BST::getTreeHeight(Node<int>* a) {
    height = getHeight(root);
    return height;
}

// insert helpers
Node<int>* findLeaf(int data, Node<int>* a) {
    if(!a->getData()) return a;
    if(a->getData() > data) {
        return findLeaf(data, a->getLeft());
    } else {
        return findLeaf(data, a->getRight());
    }
}

// output
void BST::print(Node<int>* a) {
    if (a != NULL) {
        std::cout << "" << a->getData() << "" << std::endl;
        print(a->getLeft());
        print(a->getRight());
    }
}
