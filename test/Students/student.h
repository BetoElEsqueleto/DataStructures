#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "list.h"

using namespace std;

class Student
{
private:
    int id;
    string name;
    int note1;
    int note2;
    int grade;
public:
    Student(int id, string name, int note1, int note2, int grade);
    ~Student();
    
    int id();
    string name();
    int note1();
    int note2();
    int grade();

    void id(int);
    void name(string);
    void note1(int);
    void note2(int);
    void grade(int);

};

#endif // STUDENT_H
