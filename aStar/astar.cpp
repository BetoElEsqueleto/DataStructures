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
        std::list<pt>::const_iterator iter = starts.begin();
        for (std::list<pt>::const_iterator it = goals.begin(); it != goals.end(); it++) {
            // Could recalculate path
            calcH(*it);
            searchPath(*iter, *it);
            iter++;
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
    	// Get the node off the open list with the lowest f and call it currentNode
        current = min_element(&openList);
        openList.remove(current);

    	// if currentNode is the same state as node_goal we have found the solution; break from the while loop
        if (current == goal) break; // Solution Found
    	//     Generate each state nextNode that can come after currentNode
        list<pt> nextNodes;
        pt nextNode;
        // Movements can be up, down left and right.
        // UP
        nextNode.x = current.x;
        nextNode.y = current.y+1;
        if(nextNode.x > 0 && nextNode.x < n && nextNode.y > 0 && nextNode.y < M && mat[nextNode.y][nextNode.x] != 4294967295) nextNodes.push_back(nextNode);
        // DOWN
        nextNode.x = current.x;
        nextNode.y = current.y-1;
        if(nextNode.x > 0 && nextNode.x < n && nextNode.y > 0 && nextNode.y < M && mat[nextNode.y][nextNode.x] != 4294967295) nextNodes.push_back(nextNode);
        // LEFT
        nextNode.x = current.x-1;
        nextNode.y = current.y;
        if(nextNode.x > 0 && nextNode.x < n && nextNode.y > 0 && nextNode.y < M && mat[nextNode.y][nextNode.x] != 4294967295) nextNodes.push_back(nextNode);
        // RIGHT
        nextNode.x = current.x+1;
        nextNode.y = current.y;
        if(nextNode.x > 0 && nextNode.x < n && nextNode.y > 0 && nextNode.y < M && mat[nextNode.y][nextNode.x] != 4294967295) nextNodes.push_back(nextNode);

        //     for each nextNode of currentNode
        for (std::list<pt>::const_iterator it = nextNodes.begin(); it != nextNodes.end(); it++) {
            //         Set the cost of nextNode to be the cost of currentNode plus the cost to get to nextNode from currentNode
            mat[*it->y][*it->x]->setG(mat[current->y][current->x]->getG() + mat[*it->y][*it->x]->getG());
        	//         find nextNode on the OPEN list
        	//         if nextNode is on the OPEN list but the existing one is as good or better then discard this successor and continue
        	//         if nextNode is on the CLOSED list but the existing one is as good or better then discard this successor and continue
        	//         Remove occurences of nextNode from OPEN and CLOSED
        	//         Set the parent of nextNode to currentNode
        	//         Set h to be the estimated distance to node_goal (Using the heuristic function)
        	//          Add nextNode to the OPEN list
        }

    	//     Add currentNode to the CLOSED list
        closedList.push_back(current);
    }
}
void Astar::updateVertex() {

}
void Astar::updateCostList(void) {

}
int Astar::getDist(pt a, pt b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
pt Astar::min_element(list<pt>* l) {
  if (l->first()==l->last()) return l->last();
  pt smallest = l->first();
  for (std::list<pt>::const_iterator it = goals.begin(); it != goals.end(); it++) {
      if(*it<smallest) smallest = *it;
  }
  return smallest;
}

void Astar::print() {

}
void Astar::printCosts() {

}
