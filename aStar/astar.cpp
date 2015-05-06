#include "astar.h"

Astar(int argc, const char * argv[]) {
    const char* path;
    path = argv[1];
    m = n = 0;


    FILE * fp;
    fp = fopen (path,"r");
    if (fp!=NULL) {
        int buffer [255];
        int count = 0;

        // Read number of rows
        fscanf(fp,"%i",buffer);
        m = buffer;
        // Read number of columns
        fscanf(fp,"%i",buffer);
        n = buffer;

        // Now we have the size of the graph, and can make some room in our RAM
        // Assign rows
        g = new Node*[m];
        // Assign columns
        for(int i = m; i > 0; i--)
            g[i] = new Node[n];
        for (int i = m; i > 0; i--) {
            for (int j = 1; j<=n; j++) {
                g[i][j] = 0;
            }
        }

        // while (fscanf(fp,"%i",buffer) != EOF) {
            // count ++;
        for (int i = m; i > 0; i--) {
            for (int j = 1; j<=n; j++) {
                fscanf(fp,"%i",buffer)
                g[i][j] = buffer;
            }
        }
        // }
        // TODO: Read starts and goals
        fclose (fp);
    }
    delete path;
}
~Astar() {
    for(int i = 1; i <= n; i++)
        delete(g[i]);
    delete g;
}

void readFile() {

}

void calcH() {

}
void updateVertex() {

}
void getShortest(Node* start, Node* goal) {

}
void updateCostList(void) {

}

void print() {

}
void printCosts() {

}
