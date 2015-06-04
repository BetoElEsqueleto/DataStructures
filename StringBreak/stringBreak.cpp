#include "stringBreak.h"

StringBreak::StringBreak(int argc, const char * argv[]) {
    const char* path;
    path = argv[1];
    m = n = 0;
    L = NULL;


    FILE * fp;
    // Open File
    fp = fopen (path,"r");
    if (fp!=NULL) {
        int dim;

        // Read size of string
        fscanf(fp,"%i",&dim);
        n = dim;
        // Read number of breakpoints
        fscanf(fp,"%i",&dim);
        m = dim;
        // std::cout << n << ", " << m << std::endl;

        L = new int [m];

        unsigned int buffer = 0;
        for (int i = 0; i < m; i++) {
            fscanf(fp,"%i",&buffer);
            L[i] = buffer;
            // std::cout << L[i] << " ";
        }
        std::cout << std::endl;

        // Close file
        fclose (fp);
    }
    // if (path) delete path;
    qsort(L,0,m);
}
StringBreak::~StringBreak() {
    if (L) delete L;
}
void StringBreak::solve() {
    unsigned int q = -1;
    unsigned int *r = new unsigned int [m];
    r[0]=-1;
    for (int j = 0; j < m; j++) {
        q = -1;
        for (int i = 0; i < j; i++) {
            std::cout << q << ", "<< cost(i,j) << ", " << r[j-i] << std::endl;
            q = min(q,cost(i,j) + r[j-i]);
        }
        r[j]=q;
        s += r[j];
    }
}
void StringBreak::qsort(int*v, int left, int right) {
    int i, *last;

    if (right <= left)
        return;
    last = v + left; //choosing the first element as the pivot
    for (i = left; i < right; i++)
        if (*(v + i) < *(v + left))
            swap(++last, v + i); //swapping the numbers < pivot
    swap(v + left, last);
    qsort(v, left, last - v - 1); //sub-array containing numbers < pivot
    qsort(v, last - v + 1, right); //sub-array containing numbers >= pivot
}
void StringBreak::swap(int* i, int* j) {
    int temp;

    temp = *i;
    *i = *j;
    *j = temp;
}
int StringBreak::cost(int i,int j) {
    if(i>j) {
        return L[i]-L[j];
    } else {
        return L[j]-L[i];
    }
}
void StringBreak::print() {
    std::cout << "Minimal cost:" << s << std::endl;
}
