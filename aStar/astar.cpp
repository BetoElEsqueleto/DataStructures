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
        // Call searchPath() for every trail
        for (std::vector<pt>::size_type i = 0; i != goals.size(); i++) {
            // Could recalculate path
            calcH(goals[i]);
            searchPath(starts[i], goals[i]);
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
void Astar::searchPath(pt start, pt goal) {
    // TODO: actually inplement A*
    pt current;
    // StartNode to openList
    openList.push_back(start);
    // While there are items in the openList
    while (!openList.empty()) {
    	// Get the node off the open list with the lowest f and call it node_current
    	// if node_current is the same state as node_goal we have found the solution; break from the while loop
    	//     Generate each state node_successor that can come after node_current
    	//     for each node_successor of node_current
    	//     {
    	//         Set the cost of node_successor to be the cost of node_current plus the cost to get to node_successor from node_current
    	//         find node_successor on the OPEN list
    	//         if node_successor is on the OPEN list but the existing one is as good or better then discard this successor and continue
    	//         if node_successor is on the CLOSED list but the existing one is as good or better then discard this successor and continue
    	//         Remove occurences of node_successor from OPEN and CLOSED
    	//         Set the parent of node_successor to node_current
    	//         Set h to be the estimated distance to node_goal (Using the heuristic function)
    	//          Add node_successor to the OPEN list
    	//     }
    	//     Add node_current to the CLOSED list
    }
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
