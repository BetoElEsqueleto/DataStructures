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
                    // cerr << "i node: " << buffer << std::endl;
                    i = nodes.indexOf(buffer);
                    break;
                case 2:
                    // cerr << "j node: " << buffer << std::endl;
                    j = nodes.indexOf(buffer);
                    break;
                case 0:
                    // cerr << "vertex weight: " << buffer << std::endl;
                    g[i][j] = atoi(buffer);
                    break;
                default:
                    break;
            }
        }
        fclose (fp);
    }
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

    // Verify start and end node exist


    // Fill costs with 0 for starting node and
    // INT32_MAX (infinite) for the rest
    string buffer;
    tracker aux;
    for (int i = 0; i<size; i++) {
        buffer = nodes.at(i);
        aux.index = buffer;
        notVisited.push(buffer);
        cerr << "INFO: pushed  " << buffer << " to notVisited" << endl;
        if (buffer == start) {
            aux.cost = 0;
        } else {
            aux.cost = INT32_MAX;
        }
        costs.push(aux);
    }

    // We start the algorithm in the first node
    current = start;
    // Update costs for first node
    updateCostList();
    // first hop
    hop();
    printCosts();


//    // Remove start from visited
//    notVisited.remove(start);
//
//    // GET current node
//    tracker min, firstAux;
//    min.cost = INT32_MAX;
//    for (int i = 0; i < size; i++) {
//        firstAux.index = nodes.at(i);
//        firstAux.cost = g[nodes.indexOf(start)][i];
//        if (firstAux.cost < min.cost && firstAux.cost!=0) {
//            min.index = firstAux.index;
//            min.cost = firstAux.cost;
//        }
//    }
//
//    string currentNode = min.index;
    
    
    int count =0;
    // Update costs until all network is revised, or there is no more nodes to go to.
    // TODO: come on... this loop can be better... try some other conditions...
    do {
        // Just keep moving if we're at a node
        if (!current.empty()) {
            updateCostList();
            hop();
        }
        
//        printCosts();
        count++;

//    } while (currentNode != end && count < size);
    } while (count < size);

    int mincost = costs.at(nodes.indexOf(end)).cost;

    cout << "MINIMAL COST: " << mincost << endl;

}

void Dijkstra::getLeastHops(string start,string end) {

}

void Dijkstra::updateCostList(void) {
    List<tracker> newCostList;
    tracker newTracker;
    int costOld = INT32_MAX;
    int costNew = 0;
    // Generate new costs list to replace current cost list
    for (int i = 0; i < size; i++) {
        costOld = costs.at(i).cost;
        // NEW COST: it must be the actual new cost of the node, plus the cost of the current node!!
        costNew = g[nodes.indexOf(current)][i];
        costNew += costs.at(nodes.indexOf(current)).cost;
        if (costNew < costOld && costNew != 0) {
            newTracker.cost = costNew;
            newTracker.index = costs.at(i).index;
            newCostList.push(newTracker);
        } else {
            newTracker.cost = costs.at(i).cost;
            newTracker.index = costs.at(i).index;
            newCostList.push(newTracker);
        }
    }

    // Replace old cost list with new one
    tracker aux;
    costs.empty();
    for (int i = 0; i < size; i++) {
        costs.push(newCostList.popHead()->getData());
    }

}

void Dijkstra::hop() {
    // Select the next node
    if (notVisited.remove(current) ) cerr << "FATAL! NODE NOT REMOVED" << endl;
    for (int i = 0; i < size; i++) {
        string aux = costs.at(i).index;
        cout << aux << endl;
        cout << notVisited.has(aux) << endl;
        if ( notVisited.has(aux) ) {
            cout << "Index of current: " << nodes.indexOf(current) << endl;
            
            cout << costs.at(i).cost << " " << costs.at(nodes.indexOf(current)).cost << endl;
            
            // current = smallest from notVisited.
            if ( costs.at(i).cost < costs.at(nodes.indexOf(current)).cost && costs.at(nodes.indexOf(current)).cost != 0)
            current = costs.at(i).index;
        }
    }

    if ( !notVisited.has(current) ) {
        string s;
        current = s;
    }
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
    cout << endl;
    for (int i = 0; i<size; i++) {
        cout << costs.at(i).index << " : " << costs.at(i).cost << endl;
        // cout << costs.at(i).index << " : " << costs.at(i).cost;
    }
//    cout << endl;
}
