#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include <cstdio>

#include <algorithm>
// #include <set>
// #include <vector>
#include <list>

#include "node.h"

/*
## Astar class
A* algorithm used to find shortest path in a matrix
*/
using namespace std;

// typedef struct pt_s {
//     int x;
//     int y;
// } pt;

class Astar {
private:
    int             m;             // Number of rows = height
    int             n;             // Number of columns = width
    // list<Node*>      openList;      // List of nodes that have not been visited
    // list<Node*>      closedList;    // List of nodes that have been visited
    list<pt>      openList;      // List of nodes that have not been visited
    list<pt>      closedList;    // List of nodes that have been visited
    Node**          mat;           // Matrix

    int             trails;        // Number of paths to be searched

    pt              cur;
    list<pt>      starts;
    list<pt>      goals;

public:

    class pt {
    public:
        int x;
        int y;
        bool operator ==(const pt& p) { return (x==p.x&&y==p.y); }
    }

    Astar(int argc, const char * argv[]);
    ~Astar();

    void calcH(pt goal);
    void searchPath(pt start, pt goal);
    void updateVertex();
    void updateCostList(void);

    int getDist(pt a, pt b);
    pt min_element(list<pt>* l);

    void print();
    void printCosts();

};
#endif // ASTAR_H
