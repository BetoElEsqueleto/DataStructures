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

using namespace std;
class Dijkstra {
private:
    int          size; // number of nodes in graph
    string*      index; // node index
    int**        g; // graph matrix

public:
         Dijkstra(int argc, const char * argv[]);
         ~Dijkstra();
    void addNode();
    void getDistance();
    void leastHops();
};

#endif
