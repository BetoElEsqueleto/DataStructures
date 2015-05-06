#ifndef NODE_H
#define NODE_H

class Node
{
private:
    Node *parent; // next node towards begining
    Node *child; // next node towards goal

    // Coordenates of node
    int x;
    int y;

    // Costs of node
    int g;
    int h;
    int f;
public:
    Node(int a, int b){
        x = a;
        y = b;
        parent = child = NULL;
        g = h = f = 0;
    }
    ~Node(){
        parent = child = NULL;
    }

    void setParent(Node *p){ parent = p; }
    void setChild(Node *c){ child = c; }

    void setG(int c){ g = c; }
    void setH(int c){ h = c; }
    void setF(){ f =  g + h; }

    int getG(){ return g; }
    int getH(){ return h; }
    int getf(){ return F; }
};

#endif // NODE_H
