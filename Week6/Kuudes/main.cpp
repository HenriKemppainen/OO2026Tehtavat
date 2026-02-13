#include <iostream>
#include "student.h"
#include <vector>
#include <algorithm>

using namespace std;


int main ()
{
    string nimi;
    int ika;
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:

            cout << "Student name?" << endl;
            cin >> nimi;
            cout << "Student age?" << endl;
            cin >> ika;// Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            studentList.emplace_back(nimi, ika);
            break;
        case 1:

            for (auto& entry : studentList)
            {
                entry.printStudentInfo();
                cout << "\n"; // Tulostetaan kaikki
            }
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            break;

        case 2:

            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b) {
                return a.getName() < b.getName(); // Järjestetään nimen mukaan nousevasti (A-Z)
            });

            for (auto& entry : studentList)
            {
                entry.printStudentInfo();
                cout << "\n"; // Tulostetaan kaikki
            }

            break;

        case 3:
            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b) {
                return a.getAge() < b.getAge();
            });

            for (auto& entry : studentList)
            {
                entry.printStudentInfo();
                cout << "\n"; // Tulostetaan kaikki
            }

            break;
        case 4:

            cout << "Student to be found name?" << endl;
            cin >> nimi;
            {
            auto it2 = find_if(studentList.begin(), studentList.end(),[nimi](Student& obj) {
                return obj.getName() == nimi; });

            if (it2 != studentList.end()) {
                std::cout << "Student " << nimi << " found" << endl;
                it2->printStudentInfo();
            } else {
                std::cout << "Student " << nimi << " ei löytynyt.\n";
            }
            }

            break;
        default:
         cout<< "Wrong selection, stopping..."<<endl;
         break;
        }
}while(selection < 5);

return 0;
}
