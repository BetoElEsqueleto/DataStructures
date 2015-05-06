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
        mat = new Node*[m];
        // Assign columns
        for(int i = m; i > 0; i--)
            mat[i] = new Node[n];

        for (int i = m; i > 0; i--) {
            for (int j = 1; j<=n; j++) {
                fscanf(fp,"%i",&buffer);
                mat[i][j].setG(buffer);
                std::cout << mat[i][j].getG() << " ";
            }
            std::cout << std::endl;
        }
        // TODO: Read starts and goals
        fclose (fp);
        // TODO: Call searchPath() for every trail
    }
    // delete path;
}
Astar::~Astar() {
    // for (int i = m; i > 0; i--) {
    //     delete mat[i];
    // }
    // delete mat;
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
