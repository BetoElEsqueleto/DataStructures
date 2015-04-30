#ifndef NODE_H
#define NODE_H
#include <iostream>
#define RED 1
#define BLACK 0
/*
## Node class for AVL, RBT, and BST trees
BST: basic binary search tree
AVL: requires node balance and node height
RBT: requires color of the node

These nodes contain the following atributes:
1. left      -> Pointer to Left side son.
2. right     -> Pointer to Right side son.
3. parent    -> Pointer to Parent node in binary tree.
4. data      -> Data saved in tree.
5. height    -> Longest path from the node to a leaf.
6. balance   -> Diference between the right and left weights of the childs' height.
7. color     -> Color for the RBT nodes.
*/
namespace bstn {
    template <class T>
    class Node {
        private:
            T data;
            Node<T>* left;
            Node<T>* right;
            Node<T>* parent;
            int height;

        public:
            Node(T content, Node<T>* init) {
                // Initializing node with null values.
                data = content;
                left = right = NULL;
                parent = init;
                height = -1;
            }
            ~Node() {
                parent = left = right = NULL;
            }

            // Returning the actual content of the node.
            T        getData() { return data; }

            // For every elemet of the node structure
            // there is a method to set and get it.
            Node<T>* getLeft() { return left; }
            Node<T>* getRight() { return right; }
            Node<T>* getParent() { return parent; }

            void     setLeft(Node<T>* ptr) { left = ptr; }
            void     setRight(Node<T>* ptr) { right = ptr; }
            void     setParent(Node<T>* ptr) { parent = ptr; }


    };
}
namespace avln {
    template <class T>
    class Node {
        private:
            T data;
            Node<T>* left;
            Node<T>* right;
            Node<T>* parent;
            int height;
            int balance;

        public:
            Node(T content, Node<T>* init) {
                // Initializing node with null values.
                data = content;
                left = right = NULL;
                parent = init;
                height = -1;
                balance = 0;
            }
            ~Node() {
                parent = left = right = NULL;
            }

            // Returning the actual content of the node.
            T        getData() { return data; }

            // For every elemet of the node structure
            // there is a method to set and get it.
            Node<T>* getLeft() { return left; }
            Node<T>* getRight() { return right; }
            Node<T>* getParent() { return parent; }
            int      getHeight() { return height; }
            int      getBalance() { return balance; }

            void     setLeft(Node<T>* ptr) { left = ptr; }
            void     setRight(Node<T>* ptr) { right = ptr; }
            void     setParent(Node<T>* ptr) { parent = ptr; }
            void     setHeight(int h) { height = h; }
            void     setBalance(int b) { balance = b; }

    };
}
namespace rbtn {
    template <class T>
    class Node {
        private:
            T data;
            Node<T>* left;
            Node<T>* right;
            Node<T>* parent;
            int height;
            int color;

        public:
            Node(T content, Node<T>* init) {
                // Initializing node with null values.
                data = content;
                left = right = NULL;
                parent = init;
                height = -1;
                color = BLACK;
            }
            ~Node() {
                parent = left = right = NULL;
            }

            // Returning the actual content of the node.
            T        getData() { return data; }

            // For every elemet of the node structure
            // there is a method to set and get it.
            Node<T>* getLeft() { return left; }
            Node<T>* getRight() { return right; }
            Node<T>* getParent() { return parent; }
            int      getHeight() { return height; }
            int      getColor() { return color; }

            void     setLeft(Node<T>* ptr) { left = ptr; }
            void     setRight(Node<T>* ptr) { right = ptr; }
            void     setParent(Node<T>* ptr) { parent = ptr; }
            void     setHeight(int h) { height = h; }
            void     setColor(int c) { color = c; }

    };
}
#endif // NODE_H
