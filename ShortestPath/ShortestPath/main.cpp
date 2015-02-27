//
//  main.cpp
//  ShortestPath
//
//  Created by Alberto Barradas on 2/26/15.
//  Copyright (c) 2015 *. All rights reserved.
//

#include <iostream>

#include "Dijkstra.h"


int main(int argc, const char * argv[]) {
    if (argc != 2) { // Check the value of argc. If not enough parameters have been passed, inform user and exit.
        std::cout << "Usage: ShortestPath <infile>"; // Inform the user of how to use the program
        exit(0);
    } else { // if we got enough parameters...
        Dijkstra graph(argc, argv);
        return 0;
    }
}
