#include "student.h"

Student::Student(string nimi,int ika)
{
    setName(nimi);
    setAge(ika);
}

int Student::getAge()
{
    return Age;
}

string Student::getName()
{
    return Name;
}

void Student::setAge(int ika){
    Age = ika;
}

void Student::setName(string nimi){
    Name = nimi;
}

void Student::printStudentInfo(){
    cout << "Student " << getName() << " Age " << getAge() << endl;
}
