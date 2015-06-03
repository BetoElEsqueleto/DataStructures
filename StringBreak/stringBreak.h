#ifndef STRINGBREAK_H
#define STRINGBREAK_H
#include <iostream>

/*
## StringBreak class
Dynamic programming algorithm to break a string in several pieces
*/
using namespace std;

class StringBreak {
private:
    int             n;             // Number of characters in String
    int             m;             // Number breakpoints
    int*            L;             // List of breakpoints in String

public:
    StringBreak(int argc, const char * argv[]);
    ~StringBreak();

    void qsort();
    void buttomUp();
    void swap();
    // let rŒ0::n􏰀 be a new array rŒ0􏰀D0
    // forjD1ton
    // q D 􏰐1
    // for i D 1 to j
    // q D max.q;pŒi􏰀CrŒj 􏰐i􏰀/ rŒj􏰀 D q
    // return rŒn􏰀

    void print();
};
#endif // STRINGBREAK_H
