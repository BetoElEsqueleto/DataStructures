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
    if (!nodes.has(start) || !nodes.has(end)) {
        cerr << "ERROR: The nodes you gave don't exist. Check your input file" << endl;
    } else {
        // Fill costs with 0 for starting node and
        // INT32_MAX (infinite) for the rest
        string buffer;
        tracker aux;
        this->start = start;
        for (int i = 0; i<size; i++) {
            buffer = nodes.at(i);
            aux.index = " ";
            notVisited.push(buffer);
            // cerr << "INFO: pushed  " << buffer << " to notVisited" << endl;
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

        int minCost = costs.at(nodes.indexOf(end)).cost;
        if (minCost == INT32_MAX) {
            cout << "Unfortunatelly there is no route to get to that node" << endl;
        } else {
            cout << "The shortest route is: " << endl;

            // Make a list for the route, since it'll come out from back to front
            List<string> route;
            int routeSize = 2;
            route.push(end);
            string backtracker = end;
            while (costs.at(nodes.indexOf(backtracker)).index != start) {
                route.push(costs.at(nodes.indexOf(backtracker)).index);
                backtracker = costs.at(nodes.indexOf(backtracker)).index;
                routeSize++;
            }
            route.push(start);
            for( int i =0 ; i< routeSize ; i++){
                cout << route.pop()->getData() << ", ";
            }
            cout << endl;

            cout << "And the minimal cost is: " << minCost << endl;
        }

    }
}

void Dijkstra::getLeastHops(string start, string end) {

    // Verify start and end node exist
    if (!nodes.has(start) || !nodes.has(end)) {
        cerr << "ERROR: The nodes you gave don't exist. Check your input file" << endl;
    } else {
        // Fill costs with 0 for starting node and
        // INT32_MAX (infinite) for the rest
        string buffer;
        tracker aux;
        this->start = start;
        for (int i = 0; i<size; i++) {
            buffer = nodes.at(i);
            aux.index = " ";
            notVisited.push(buffer);
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
        updateHopsList();
        // first hop
        hop();
        printCosts();

        int count =0;
        // Update costs until all network is revised, or there is no more nodes to go to.
        // TODO: come on... this loop can be better... try some other conditions...
        do {
            // Just keep moving if we're at a node
            if (!current.empty()) {
                updateHopsList();
                hop();
            }

            //        printCosts();
            count++;

            //    } while (currentNode != end && count < size);
        } while (count < size);

        int minCost = costs.at(nodes.indexOf(end)).cost;
        if (minCost == INT32_MAX) {
            cout << "Unfortunatelly there is no route to get to that node" << endl;
        } else {
            cout << "The shortest route is: " << endl;

            // Make a list for the route, since it'll come out from back to front
            List<string> route;
            int routeSize = 2;
            route.push(end);
            string backtracker = end;
            while (costs.at(nodes.indexOf(backtracker)).index != start) {
                route.push(costs.at(nodes.indexOf(backtracker)).index);
                backtracker = costs.at(nodes.indexOf(backtracker)).index;
                routeSize++;
            }
            route.push(start);
            for( int i =0 ; i< routeSize ; i++){
                cout << route.pop()->getData() << ", ";
            }
            cout << endl;

            cout << "And the minimal hops are: " << minCost << endl;
        }

    }
}

void Dijkstra::updateHopsList() {
    List<tracker> newHopsList;
    tracker newTracker;
    int costOld = INT32_MAX;
    int hopNew = 0;
    // Generate new costs list to replace current cost list
    for (int i = 0; i < size; i++) {
        costOld = costs.at(i).cost;
        // NEW COST: it must be the actual new cost of the node, plus the cost of the current node!!
        if (g[nodes.indexOf(current)][i]) {
            hopNew = 1;
        }
        if(hopNew != 0) hopNew += costs.at(nodes.indexOf(current)).cost;

        if (hopNew < costOld && hopNew != 0) { // if new cost is less than the old one and not zero
            newTracker.cost = hopNew;
            newTracker.index = current;
            newHopsList.push(newTracker);
        } else if(hopNew == INT32_MAX) {        // if new cost = infinite
            newTracker.cost = costs.at(i).cost;
            newTracker.index = "";
        } else {                                 // if ne cost is bigger, or zero, take the old one
            newTracker.cost = costs.at(i).cost;
            newTracker.index = costs.at(i).index;
            newHopsList.push(newTracker);
        }
    }

    // Replace old cost list with new one
    tracker aux;
    costs.empty();
    for (int i = 0; i < size; i++) {
        costs.push(newHopsList.popHead()->getData());
    }


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
        if(costNew != 0) costNew += costs.at(nodes.indexOf(current)).cost;

        if (costNew < costOld && costNew != 0) { // if new cost is less than the old one and not zero
            newTracker.cost = costNew;
            newTracker.index = current;
            newCostList.push(newTracker);
        } else if(costNew == INT32_MAX) {        // if new cost = infinite
            newTracker.cost = costs.at(i).cost;
            newTracker.index = "";
        } else {                                 // if ne cost is bigger, or zero, take the old one
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
    notVisited.remove(current);
    for (int i = 0; i < size; i++) {
        string aux = nodes.at(i);
        if (aux == start) continue;

        if ( notVisited.has(aux) ) {

            // If the node has been visited, change current to a random son of it.
            if (!notVisited.has(current)) {
                for (int i = 0; i < size ; i++) {
                    int aux = g[nodes.indexOf(current)][i];
                    if (aux!=0 && notVisited.has(nodes.at(i))) {
                        current = nodes.at(i);
                        break;
                    }
                }
            }

            // current = smallest from notVisited.
            bool first  = costs.at(i).cost != 0;
            bool second = notVisited.has(current);
            if (first && second){
                for (int j = 0 ; j < size; j++) {
                    bool third = costs.at(i).cost < costs.at(j).cost;
                    bool fourth = costs.at(i).cost != 0;
                    if (third && fourth) {
                        current = nodes.at(i);
                    }
                }

            }
        }
    }
//    printCosts();
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
        cout << nodes.at(i) << " ";
    }
    cout << endl;
    for (int i = 0; i<size; i++) {

        if (costs.at(i).cost == INT32_MAX) {
            cout << "Inf\t";
        } else {
            cout << costs.at(i).cost << "\t\t";
        }
    }
    cout << endl;
    for (int i = 0; i<size; i++) {
        cout << costs.at(i).index << " ";
    }
    cout << endl;
}
