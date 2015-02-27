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
            if(!index.has(buffer) && (count%3)){
                // Just push everything to the index of nodes
//                cerr << buffer << std::endl;
                index.push(buffer);
            }

        }
        // Now we have the size of the graph, and can make some room in our RAM
        size =  index.getSize();

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
                    i = index.indexOf(buffer);
                    break;
                case 2:
//                    cerr << "j node: " << buffer << std::endl;
                    j = index.indexOf(buffer);
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
    if (!index.has(i)) {
        while (!index.has(i)) {
            cout << "ERROR: node not in graph! Check your input file.\nEnter the departure node: ";
            cin >> i;
            cout << endl;
        }
    }

    cout << "Enter the arrival node: ";
    cin >> j;
    cout << endl;
    if (!index.has(j)) {
        while (!index.has(j)) {
            cout << "ERROR: node not in graph! Check your input file.\nEnter the departure node: ";
            cin >> j;
            cout << endl;
        }
    }

    cout << "Enter cost of the vertex: ";
    cin >> w;
    cout << endl;
    if(g[index.indexOf(i)][index.indexOf(j)]==0) {
        g[index.indexOf(i)][index.indexOf(j)] = w;
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
    if (!index.has(i)) {
        while (!index.has(i)) {
            cout << "ERROR: node not in graph! Check your input file.\nEnter the departure node: ";
            cin >> i;
            cout << endl;
        }
    }

    cout << "Enter the arrival node: ";
    cin >> j;
    cout << endl;
    if (!index.has(j)) {
        while (!index.has(j)) {
            cout << "ERROR: node not in graph! Check your input file.\nEnter the departure node: ";
            cin >> j;
            cout << endl;
        }
    }

    cout << "Enter cost of the vertex: ";
    cin >> w;
    cout << endl;
    g[index.indexOf(i)][index.indexOf(j)] = w;
}

void Dijkstra::getShortest(string start,string end) {
    // Let's do some magic! right after my nap.

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
