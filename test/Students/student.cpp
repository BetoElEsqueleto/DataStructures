#include "student.h"

Student::Student()
{
}
Student::Student(int id, QString name, double first, double second, double final)
{
    this->id = id;
    this->name = name;
    note1 = first;
    note2 = second;
    grade = final;
}
Student::~Student()
{
}
int Student::getId(){ return this->id; }
QString Student::getName(){ return name; }
double Student::getNote1(){ return note1; }
double Student::getNote2(){ return note2; }
double Student::getGrade(){ return grade; }

void Student::setId(int id) {this->id = id;}
void Student::setName(QString name) { this->name = name; }
void Student::setNote1(double first) { note1 = first; }
void Student::setNote2(double second) { note2 = second; }
void Student::setGrade(double final) { grade = final; }
