#include "astar.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) { // Check the value of argc. If not enough parameters have been passed, inform user and exit.
        std::cout << "Usage: Astar <infile>" << std::endl;
        std::cout << "       Bro, do you even Bash?" << std::endl;
        exit(0);
    } else { // if we got enough parameters...

        Astar graph(argc, argv);

        return 0;
    }
}
