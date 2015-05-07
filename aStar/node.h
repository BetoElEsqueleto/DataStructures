#ifndef NODE_H
#define NODE_H

class Node
{
private:
    Node *parent; // next node towards begining
    Node *child; // next node towards goal

    // Costs of node
    unsigned int g;
    unsigned int h;
    unsigned int s; // cummulative or current value for algorithm
    unsigned int f;
public:
    Node(){
        parent = child = NULL;
        g = h = f = -1;
    }
    ~Node(){
        parent = child = NULL;
    }

    void setParent(Node *p){ parent = p; }
    void setChild(Node *c){ child = c; }

    void setG(unsigned int c){ g = c; }
    void setH(unsigned int c){ h = c; }
    void setH(unsigned int c){ s = c; }
    void setF(){ f =  g + h; }

    unsigned long long int getG(){ return g; }
    unsigned long long int getH(){ return h; }
    unsigned long long int getf(){ return f; }
    unsigned long long int getf(){ return s; }
};

#endif // NODE_H
