#include "student.h"

Student::Student(int id, string name, int note1, int note2, int grade)
{
    self.id = id;
    self.name = name;
    self.note1 = note1;
    self.note2 = note2;
    self.grade = grade;
}

int id(){ return id; }
string name(){ return name; }
int note1(){ return note1; }
int note2(){ return note2; }
int grade(){ return grade; }

void id(int id) {self.id = id;}
void name(string name) { self.name = name; }
void note1(int note1) { self.note1 = note1; }
void note2(int note2) { self.note2 = note2; }
void grade(int grade) { self.grade = grade; }
