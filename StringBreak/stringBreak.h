#ifndef STRINGBREAK_H
#define STRINGBREAK_H
#include <iostream>

/*
## StringBreak class
Dynamic programming algorithm to break a string in several pieces.
*/
using namespace std;

class StringBreak {
private:
    int             n;             // Number of characters in String
    int             m;             // Number breakpoints
    int*            L;             // List of breakpoints in String
    unsigned int    s;             // Least cost for breaking (solution)

public:
    StringBreak(int argc, const char * argv[]);
    ~StringBreak();

    void solve();
    void qsort(int*v, int left, int right);
    void swap(int* i, int* j);
    int cost(int i,int j);

    void print();
};
#endif // STRINGBREAK_H
