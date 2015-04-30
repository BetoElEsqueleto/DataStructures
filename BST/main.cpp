#include <stdlib.h>     /* srand, rand */
#include <time.h>
// #include "avl.h"
#include "rbt.h"
#include "Node.h"


int main(int argc, char const *argv[]) {
    // AVL myTree;
    RBT myTree;

    srand(time(NULL));
    int s = 0;
    for (size_t i = 0; i < 20; i++) {
        s = rand()%1000;
        myTree.insert(s);
        std::cout << "Inserting: " << s << std::endl;
    }
    std::cout << "Printing: " << std::endl;
    myTree.print(myTree.getRoot());
    return 0;
}
