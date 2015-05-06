#include "astar.h"

Astar(int argc, const char * argv[]) {
    const char* path;
    path = argv[1];
    size = 0;

    FILE * fp;
    // TODO: read correct values
    fp = fopen (path,"r");
    if (fp!=NULL) {
        // TODO: only read int
        char buffer [255];
        int count = 0;
        // TODO: Read number of rows
        // TODO: Read number of columns
        while (fscanf(fp,"%s",buffer) != EOF) {
            count ++;
            if(!nodes.has(buffer) && (count%3)){
                // Just push everything to the index of nodes
                nodes.push(buffer);
            }

        }
        // Now we have the size of the graph, and can make some room in our RAM
        size =  nodes.getSize();

        // Assign rows
        g = new Node*[m];
        // Assign columns
        for(int i = m; i > 0; i--)
            g[i] = new Node[n];
        for (int i = m; i > 0; i--) {
            for (int j = 0; j<n; j++) {
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
    delete path;
}
~Astar() {

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
