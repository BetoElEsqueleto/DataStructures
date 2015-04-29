//
//  main.cpp
//  AVLTree
//
//  Created by Alberto Barradas on 4/29/15.
//  Copyright (c) 2015 *. All rights reserved.
//
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "avl.h"


int main(int argc, char const *argv[]) {
    AVL myTree;
    
    srand((unsigned int)time(NULL));
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
