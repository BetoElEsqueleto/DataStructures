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
    size = 0;
//    cerr << path << endl;

    FILE * fp;
    // YES! open a file ;D
    fp = fopen (path,"r");
    if (fp!=NULL) {
        char buffer [255];
        int count = 0;
        while (fscanf(fp,"%s",buffer) != EOF) {
            count ++;
            if(!nodes.has(buffer) && (count%3)){
                // Just push everything to the index of nodes
//                cerr << buffer << std::endl;
                nodes.push(buffer);
            }

        }
        // Now we have the size of the graph, and can make some room in our RAM
        size =  nodes.getSize();

        // Assign first dimension
        g = new int*[size];
        // Assign second dimension
        for(int i = 0; i < size; i++)
            g[i] = new int[size];
        for (int i = 0; i<size; i++) {
            for (int j = 0; j<size; j++) {
                g[i][j] = 0;
            }
        }

        int i = 0 , j = 0;

        rewind(fp);
        count = 0;
        while (fscanf(fp,"%s",buffer) != EOF) {
            count ++;
            switch (count%3) {
                case 1:
//                    cerr << "i node: " << buffer << std::endl;
                    i = nodes.indexOf(buffer);
                    break;
                case 2:
//                    cerr << "j node: " << buffer << std::endl;
                    j = nodes.indexOf(buffer);
                    break;
                case 0:
//                    cerr << "vertex weight: " << buffer << std::endl;
                    g[i][j] = atoi(buffer);
                    break;
                default:
                    break;
            }
        }
        fclose (fp);
    }
//    print();
}

Dijkstra::~Dijkstra() {
    for(int i = 0; i < size; i++)
        delete(g[i]);
    delete g;
}

void Dijkstra::addVertex() {
    string i,j;
    int w;

    cout << "Enter the departure node: ";
    cin >> i;
    cout << endl;
    if (!nodes.has(i)) {
        while (!nodes.has(i)) {
            cout << "ERROR: node not in graph! Check your input file.\nEnter the departure node: ";
            cin >> i;
            cout << endl;
        }
    }

    cout << "Enter the arrival node: ";
    cin >> j;
    cout << endl;
    if (!nodes.has(j)) {
        while (!nodes.has(j)) {
            cout << "ERROR: node not in graph! Check your input file.\nEnter the departure node: ";
            cin >> j;
            cout << endl;
        }
    }

    cout << "Enter cost of the vertex: ";
    cin >> w;
    cout << endl;
    if(g[nodes.indexOf(i)][nodes.indexOf(j)]==0) {
        g[nodes.indexOf(i)][nodes.indexOf(j)] = w;
    } else {
        cout << "Vertex exists already. Use updateVertex()" << endl;
    }

}

void Dijkstra::updateVertex() {
    string i,j;
    int w;

    cout << "Enter the departure node: ";
    cin >> i;
    cout << endl;
    if (!nodes.has(i)) {
        while (!nodes.has(i)) {
            cout << "ERROR: node not in graph! Check your input file.\nEnter the departure node: ";
            cin >> i;
            cout << endl;
        }
    }

    cout << "Enter the arrival node: ";
    cin >> j;
    cout << endl;
    if (!nodes.has(j)) {
        while (!nodes.has(j)) {
            cout << "ERROR: node not in graph! Check your input file.\nEnter the departure node: ";
            cin >> j;
            cout << endl;
        }
    }

    cout << "Enter cost of the vertex: ";
    cin >> w;
    cout << endl;
    g[nodes.indexOf(i)][nodes.indexOf(j)] = w;
}

void Dijkstra::getShortest(string start,string end) {
    tracker aux;
    
    
    // Fill costs with 0 for starting node and
    // INT32_MAX (infinite) for the rest
    string buffer;
    for (int i = 0; i<size; i++) {
        buffer = nodes.at(i);
        aux.index = buffer;
        if (buffer == start) {
            aux.cost = 0;
        } else {
            aux.cost = INT32_MAX;
        }
        costs.push(aux);
//        cout << aux.index << " : " << aux.cost << endl;
    }
    // printCosts();
    
    
}

void Dijkstra::getLeastHops(string start,string end) {

}

void Dijkstra::print() {
    if (size) {
        for (int i = 0; i<size; i++) {
            cout << endl;
            for (int j = 0; j<size; j++) {
                cout << g[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

void Dijkstra::printCosts() {
    for (int i = 0; i<size; i++) {
        
        cout << costs.at(i).index << " : " << costs.at(i).cost << endl;
    }
}

