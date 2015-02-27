//
//  Dijkstra.h
//  ShortestPath
//
//  Created by Alberto Barradas on 2/26/15.
//  Copyright (c) 2015 *. All rights reserved.
//

#ifndef ShortestPath_Dijkstra_h
#define ShortestPath_Dijkstra_h
#include <iostream>
#include <cstdio>

#include "List.h"

using namespace std;

typedef struct {
    int cost;
    int index;
}tracker;

class Dijkstra {
private:
    int          size;  // number of nodes in graph
    List<string> index; // node index
    int**        g;     // graph matrix
    tracker      t;
    tracker**    costMatrix;

public:
         Dijkstra(int argc, const char * argv[]);
         ~Dijkstra();
    void addVertex();
    void updateVertex();
    void getShortest(string start,string end);
    void getLeastHops(string start,string end);
    void print();
};

#endif
