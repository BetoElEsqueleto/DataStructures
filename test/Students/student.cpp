#include "student.h"

Student::Student()
{
}
Student::Student(int id, string name, int note1, int note2, int grade)
{
    this->id = id;
    this->name = name;
    this->note1 = note1;
    this->note2 = note2;
    this->grade = grade;
}
Student::~Student()
{
}
int Student::getId(){ return this->id; }
string Student::getName(){ return name; }
int Student::getNote1(){ return note1; }
int Student::getNote2(){ return note2; }
int Student::getGrade(){ return grade; }

void Student::setId(int id) {this->id = id;}
void Student::setName(string name) { this->name = name; }
void Student::setNote1(int note1) { this->note1 = note1; }
void Student::setNote2(int note2) { this->note2 = note2; }
void Student::setGrade(int grade) { this->grade = grade; }
