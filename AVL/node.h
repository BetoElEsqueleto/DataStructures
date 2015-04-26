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

    public:
        Node(T content, Node<T>* init);
        ~Node();

        // Returning the actual content of the node.
        T getData();

        // For every elemet of the node structure
        // there is a method to set and get it.
        Node<T>* getNext();
        Node<T>* getPrev();
        Node<T>* getParent();
        Node<T>* getFirstSon();
        Node<T>* getSecondSon();
        void setNext(Node<T>* ptr);
        void setPrev(Node<T>* ptr);
        void setParent(Node<T>* ptr);
        void setFirstSon(Node<T>* ptr);
        void setSecondSon(Node<T>* ptr);
};
#endif // NODE_H
