#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include <cstdio>

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

/*
## Astar class
A* algorithm used to find shortest path in a matrix
*/
class Astar {
private:
    int             height;        // Number of rows = m
    int             width;         // Number of columns = n
    vector<Node>    openList;      // List of nodes that have not been visited
    vector<Node>    closedList;    // List of nodes that have been visited
    Node**          g;             // Matrix

    Node*           current;


public:
    Astar(int argc, const char * argv[]);
    ~Astar();

    void readFile();

    void calcH();
    void updateVertex();
    void getShortest(Node* start, Node* goal);
    void updateCostList(void);

    void print();
    void printCosts();

};
#endif // ASTAR_H
