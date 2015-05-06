#include "astar.h"

Astar::Astar(int argc, const char * argv[]) {
    const char* path;
    path = argv[1];
    m = n = 0;


    FILE * fp;
    fp = fopen (path,"r");
    if (fp!=NULL) {
        int dim;

        // Read number of rows
        fscanf(fp,"%i",&dim);
        m = dim;
        // Read number of columns
        fscanf(fp,"%i",&dim);
        n = dim;

        unsigned int buffer = 0;

        // Now we have the size of the graph, and can make some room in our RAM
        // Assign rows
        g = new Node*[m];
        // Assign columns
        for(int i = m; i > 0; i--)
            g[i] = new Node[n];
        // for (int i = m; i > 0; i--) {
        //     for (int j = 1; j<=n; j++) {
        //         g[i][j] = 0;
        //     }
        // }

        // while (fscanf(fp,"%i",buffer) != EOF) {
            // count ++;
        for (int i = m; i > 0; i--) {
            for (int j = 1; j<=n; j++) {
                fscanf(fp,"%i",&buffer);
                g[i][j].setG(buffer);
            }
        }
        // }
        // TODO: Read starts and goals
        fclose (fp);
    }
    delete path;
}
Astar::~Astar() {
    for(int i = 1; i <= n; i++)
        delete(g[i]);
    delete g;
}

void Astar::readFile() {

}

void Astar::calcH() {

}
void Astar::updateVertex() {

}
void Astar::getShortest(Node* start, Node* goal) {

}
void Astar::updateCostList(void) {

}

void Astar::print() {

}
void Astar::printCosts() {

}
