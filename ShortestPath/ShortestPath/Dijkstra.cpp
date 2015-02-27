//
//  Dijkstra.cpp
//  ShortestPath
//
//  Created by Alberto Barradas on 2/26/15.
//  Copyright (c) 2015 *. All rights reserved.
//

#include "Dijkstra.h"

Dijkstra::Dijkstra(int argc, const char * argv[]) {
    const char* path;
    path = argv[1];
//    cerr << path << endl;
    FILE * fp;
    
    fp = fopen (path,"r");
    if (fp!=NULL) {
        char buffer [255];
        int count = 0;
        while (fscanf(fp,"%s",buffer) != EOF) {
            count ++;
            if(!index.has(buffer) && (count%3)){
                cerr << buffer << std::endl;
                index.push(buffer);
            }

        }
        fclose (fp);
    }
    
//    ifstream fp(path);
//    if(fp.is_open()) {
//        string buffer;
//        fscanf(fp, "%s", buffer);
//        while( getline(fp,buffer) ) {
//            
//            cerr << buffer << std::endl;
//            }
//        fp.close();
//    } else {
//        cerr << "Unable to open file" << endl;
//    }
    
    
    // Read File 1:
    // get graph size
    // Read file 2:
    // fill graph matrix
}

Dijkstra::~Dijkstra() {

}

void Dijkstra::addNode() {

}

void Dijkstra::getDistance() {

}

void Dijkstra::leastHops() {

}
