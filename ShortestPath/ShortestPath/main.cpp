//
//  main.cpp
//  ShortestPath
//
//  Created by Alberto Barradas on 2/26/15.
//  Copyright (c) 2015 *. All rights reserved.
//

#include <iostream>

#include "Dijkstra.h"


int main(int argc, const char * argv[]) {
    if (argc != 2) { // Check the value of argc. If not enough parameters have been passed, inform user and exit.
        std::cout << "Usage: ShortestPath <infile>" << std::endl;
        std::cout << "       Bro, do you even Bash?" << std::endl;
        exit(0);
    } else { // if we got enough parameters...

        Dijkstra graph(argc, argv);
        int opc;
        string start, end;
        
        // DEBUG:
        graph.getShortest("Francia","Suiza");
        
//        while (!opc) {
//            // MENU
//            cout << "=============================================" << endl;
//            cout << "What are you expecting to find here? go away!" << endl;
//            cout << "I bet you don't even know what you want:" << endl;
//            cout << "" << endl;
//            cout << "1) Shortest path." << endl;
//            cout << "2) Least hops path." << endl;
//            cout << "3) Add a vertex." << endl;
//            cout << "4) A little surprise." << endl;
//            cout << "5) Print that mofo!" << endl;
//            cout << "6) Get outta here!" << endl;
//            cout << "" << endl;
//            cin >> opc;
//
//            switch (opc) {
//                case 1:
//                {
//                    cout << "So... you want to know the shortest path, dontcha?" << endl;
//                    cout << "Go on: type the name of your starting node: ";
//                    cin >> start;
//                    cout << "You sure you want the shortest path? 'cause you don't seem like you've got what it needs" << endl;
//                    cout << "Alright then, go ahead and type your ending node: ";
//                    cin >> end;
//                    graph.getShortest(start,end);
//                    break;
//                }
//                case 2:
//                {
//                    cout << "Do you even know what a hop is? NO! it is not an easter's movie... looser." << endl;
//                    cout << "Fine! whatever type like... your starting node or something: ";
//                    cin >> start;
//                    cout << "Dude this shit is serious... you sure 'bout this?'" << endl;
//                    cout << "Well, you know what you're doing. Type your ending node: ";
//                    cin >> end;
//                    graph.getShortest(start,end);
//                    break;
//                }
//                case 3:
//                {
//                    cout << "Man! You should have seen your face while googling what a vertex is." << endl;
//                    graph.addVertex();
//                    cout << "" << endl;
//                    cout << "Fine. So now what?" << endl;
//                    opc = 0;
//                    break;
//                }
//                case 4:
//                {
//                    cout << "YOU FELL FOR THAT? Really?! That's like the oldest trick in the book" << endl;
//                    cout << "You must get bullied a lot." << endl;
//                    opc = 0;
//                    break;
//                }
//                case 5:
//                {
//                    cout << "You sure you want to print that (Y:1/N:2)? it could be one big mofo..." << endl;
//                    cin >> opc;
//                    if(opc == 1) graph.print();
//                    opc = 0;
//                    break;
//
//                }
//                case 6:
//                {
//                    cout << "Bah! I knew you didn't have it in'cha, you little whimp" << endl;
//                    cout << "          _     _                 \n__      _| |__ (_)_ __ ___  _ __  \n\\ \\ /\\ / / '_ \\| | '_ ` _ \\| '_ \\ \n \\ V  V /| | | | | | | | | | |_) |\n  \\_/\\_/ |_| |_|_|_| |_| |_| .__/ \n                           |_|         \n" << endl;
//                    return(0);
//                    break;
//
//                }
//                default:
//                {
//                    opc = 0;
//                    break;
//                }
//            }
//        }

        return 0;
    }
}
