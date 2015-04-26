#ifndef NODE_H
#define NODE_H
/*
## Node class for AVL trees
Contains the following atributes:
1. left      -> Next node in list
2. right      -> Previous node in list
3. parent    -> Parent node in binary tree
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
