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
        cur.x = 0;
        cur.y = 0;

        pt temp;
        trails = 0;
        while (fscanf(fp,"%i",&buffer) != EOF) {
            trails ++;
            // read start x
            temp.x = buffer;
            // get a coma ,
            fgetc(fp);
            // read start y
            fscanf(fp,"%i",&buffer);
            temp.y = buffer;
            // push start
            starts.push_back(temp);
            std::cout << temp.x << "," << temp.y << " ";

            // get a space
            fgetc(fp);
            // read goal x
            fscanf(fp,"%i",&buffer);
            temp.x = buffer;
            // get a coma ,
            fgetc(fp);
            // read goal y
            fscanf(fp,"%i",&buffer);
            temp.y = buffer;
            // push goal
            goals.push_back(temp);
            std::cout << temp.x << "," << temp.y << " " << std::endl;
        }
        std::cout << trails << std::endl;
        // Close file
        fclose (fp);
        calcH();
        for (std::vector<pt>::size_type i = 0; i != goals.size(); i++) {
            // TODO: Call searchPath() for every trail
            searchPath(&mat[starts[i].x][starts[i].y], &mat[goals[i].x][goals[i].y]);
        }

    }
    if (path) delete path;
}
Astar::~Astar() {
    for(int i = m; i > 0; i--)
        if (mat[i]) delete mat[i];
    if (mat) delete mat;
}

void Astar::calcH(pt goal) {
    pt a;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            a.x = j;
            a.y = i;
            mat[i][j].setH(getDist(a, goal));
        }
    }
}
void Astar::searchPath(Node* start, Node* goal) {

}
void Astar::updateVertex() {

}
void Astar::updateCostList(void) {

}
int Astar::getDist(pt a, pt b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}


void Astar::print() {

}
void Astar::printCosts() {

}
