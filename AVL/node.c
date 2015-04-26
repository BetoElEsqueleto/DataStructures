#include "node.h"

Node::Node(T content, Node<T>* init) {
    // Initializing node with null values.
    data = content;
    left = right = NULL;
    parent = init;
}

Node::~Node() {
    parent = left = right = NULL;
}

T Node::getDate() { return data; }

Node<T>* Node::getLeft() { return left; }
Node<T>* Node::getRight() { return right; }
Node<T>* Node::getParent() { return parent; }

void Node::setLeft(Node<T>* ptr) { left = ptr; }
void Node::setRight(Node<T>* ptr) { right = ptr; }
void Node::setParent(Node<T>* ptr) { parent = ptr; }
