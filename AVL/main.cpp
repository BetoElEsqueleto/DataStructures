#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "avl.h"

int main(int argc, char const *argv[]) {
    AVL myTree;

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
