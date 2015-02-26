#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <QString>

#include "list.h"

using namespace std;

class Student
{
private:
    int id;
    QString name;
    double note1;
    double note2;
    double grade;
public:
    Student();
    Student(int id, QString name, double first, double second, double final);
    ~Student();

    int getId();
    QString getName();
    double getNote1();
    double getNote2();
    double getGrade();

    void setId(int);
    void setName(QString);
    void setNote1(double first);
    void setNote2(double second);
    void setGrade(double final);

};

#endif // STUDENT_H
