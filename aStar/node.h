#ifndef NODE_H
#define NODE_H

class Node
{
private:
    Node *parent; // next node towards begining
    Node *child; // next node towards goal

    // Costs of node
    unsigned long long int g;
    unsigned long long int h;
    unsigned long long int f;
public:
    Node(){
        parent = child = NULL;
        g = h = f = 0;
    }
    ~Node(){
        parent = child = NULL;
    }

    void setParent(Node *p){ parent = p; }
    void setChild(Node *c){ child = c; }

    void setG(unsigned long long int c){ g = c; }
    void setH(unsigned long long int c){ h = c; }
    void setF(){ f =  g + h; }

    unsigned long long int getG(){ return g; }
    unsigned long long int getH(){ return h; }
    unsigned long long int getf(){ return f; }
};

#endif // NODE_H
