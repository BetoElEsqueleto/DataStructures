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

    int getId();
    string getName();
    int getNote1();
    int getNote2();
    int getGrade();

    void setId(int);
    void setName(string);
    void setNote1(int);
    void setNote2(int);
    void setGrade(int);

};

#endif // STUDENT_H
