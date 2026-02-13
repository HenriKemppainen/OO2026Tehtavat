#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
#include <iostream>

class Student
{
public:
    Student(string, int);
    void setAge(int);
    void setName(string);
    string getName();
    int getAge();
    void printStudentInfo();
private:
    string Name;
    int Age;
};

#endif // STUDENT_H
