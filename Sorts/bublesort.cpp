#include <iostream>
#include  <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> a (12,23,56,79,12,56,23,75,98,23,65);
    bubblesort(a);
    return 0;
}

void bubblesort(a) {
    int c;
    for(std::vector<int>::size_type i = 0; i < a.size()-1; i++) {
        for(std::vector<int>::size_type j = a.size(); j > i + 1; j--) {
            if (a[j] < a[i]) {
                c = a[j-1];
                a[j-1] = a[j];
                a[j] = c;
            }
        }
    }
}
