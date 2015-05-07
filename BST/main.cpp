#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "avl.h"
// #include "rbt.h"
// #include "bst.h"
#include "Node.h"


int main(int argc, char const *argv[]) {
    AVL myAVL;
    // RBT myRBT;
    // BST myBST;

    std::cout << "AVL TREE:" << std::endl;
    srand(time(NULL));
    int s = 0;
    for (size_t i = 0; i < 20; i++) {
        s = rand()%1000;
        myAVL.insert(s);
        std::cout << "Inserting: " << s << std::endl;
    }
    std::cout << "Printing: " << std::endl;
    myAVL.print(myAVL.getRoot());

    // std::cout << " " << std::endl;
    // std::cout << "RB TREE:" << std::endl;
    // myRBT.insert(41);
    // myRBT.insert(38);
    // myRBT.insert(31);
    // myRBT.insert(12);
    // myRBT.insert(19);
    // myRBT.insert(8);

    // myRBT.remove(8);
    // myRBT.remove(12);
    // myRBT.remove(19);
    // myRBT.remove(31);
    // myRBT.remove(38);
    // myRBT.remove(41);
    // std::cout << "Printing: " << std::endl;
    // myRBT.print(myRBT.getRoot());

    return 0;
}
