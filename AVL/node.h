#ifndef NODE_H
#define NODE_H
/*
## Node class for AVL trees
Contains the following atributes:
1. left      -> Pointer to Left side son.
2. right     -> Pointer to Right side son.
3. parent    -> Pointer to Parent node in binary tree.
4. data      -> Data saved in tree.
*/
template <class T>
class Node {
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
        Node<T>* parent;
        int height;

    public:
        Node(T content, Node<T>* init);
        ~Node();

        // Returning the actual content of the node.
        T getData();

        // For every elemet of the node structure
        // there is a method to set and get it.
        Node<T>* getLeft();
        Node<T>* getRight();
        Node<T>* getParent();
        int getHeight();

        void setLeft(Node<T>* ptr);
        void setRight(Node<T>* ptr);
        void setParent(Node<T>* ptr);
        void setHeight(int h);
};
#endif // NODE_H


Node::Node(T content, Node<T>* init) {
    // Initializing node with null values.
    data = content;
    left = right = NULL;
    parent = init;
    height = -1;
}

Node::~Node() {
    parent = left = right = NULL;
}

T        Node::getData() { return data; }

Node<T>* Node::getLeft() { return left; }
Node<T>* Node::getRight() { return right; }
Node<T>* Node::getParent() { return parent; }
int      Node::getHeight() { return height }


void     Node::setLeft(Node<T>* ptr) { left = ptr; }
void     Node::setRight(Node<T>* ptr) { right = ptr; }
void     Node::setParent(Node<T>* ptr) { parent = ptr; }
void     Node::setHeight(int h) { height = h }
