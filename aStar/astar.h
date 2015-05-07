#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include <cstdio>

#include <algorithm>
#include <set>
#include <vector>

#include "node.h"

/*
## Astar class
A* algorithm used to find shortest path in a matrix
*/
using namespace std;

typedef struct pt_s {
    int x;
    int y;
} pt;

class Astar {
private:
    int             m;             // Number of rows = height
    int             n;             // Number of columns = width
    vector<Node>    openList;      // List of nodes that have not been visited
    vector<Node>    closedList;    // List of nodes that have been visited
    Node**          mat;           // Matrix

    int             trails;        // Number of paths to be searched

    pt              cur;
    vector<pt>      starts;
    vector<pt>      goals;

public:

    Astar(int argc, const char * argv[]);
    ~Astar();

    void calcH(pt goal);
    void searchPath(Node* start, Node* goal);
    void updateVertex();
    void updateCostList(void);

    int getDist(pt a, pt b);

    void print();
    void printCosts();

};
#endif // ASTAR_H
