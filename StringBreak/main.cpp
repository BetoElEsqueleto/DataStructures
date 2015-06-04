#include "stringBreak.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) { // Check the value of argc. If not enough parameters have been passed, inform user and exit.
        cout << "Usage: sb <infile>" << endl;
        cout << "       Bro, do you even Bash?" << endl;
        exit(0);
    } else { // if we got enough parameters...

        StringBreak app(argc, argv);
        app.solve();
        app.print();

        return 0;
    }
}
