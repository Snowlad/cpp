#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student {
private:
    string Name;
    int Age;

public:
    // Konstruktori
    Student(string n, int a) {
        Name = n;
        Age = a;
    }

    // Setterit
    void setAge(int a) {
        Age = a;
    }

    void setName(string n) {
        Name = n;
    }

    // Getterit
    string getName() const {
        return Name;
    }

    int getAge() const {
        return Age;
    }

    //Tulostus
    void printStudentInfo() const {
        cout << "Student " << Name << " Age " << Age << endl;
    }
};

int main ()
{
    int selection = 0;
    vector<Student> studentList;
    string nameInput;
    int ageInput;

    do
    {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cout << "> ";
        cin >> selection;

        switch(selection)
        {
        case 0:
            // Kysy uuden opiskelijan nimi ja ikä
            cout << "Student name ?" << endl;
            cin >> nameInput;
            cout << "Student age ?" << endl;
            cin >> ageInput;
            studentList.emplace_back(nameInput, ageInput);
            break;

        case 1:
            // Tulosta kaikki
            for(const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 2:
            // Järjestetään nimen mukaan
            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
            // Tulostus
            for(const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 3:
            // Järjestä
            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getAge() < b.getAge(); // Pienimmästä suurimpaan
            });

            // Tulostus
            cout << "Sorted by Age" << endl;
            for(const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 4:
            // Kysy käyttäjältä opiskelijan nimi
            cout << "Student name ?" << endl;
            cin >> nameInput;
            // onko jo?
            {
                auto it = find_if(studentList.begin(), studentList.end(), [&nameInput](const Student& s) {
                    return s.getName() == nameInput;
                });

                if (it != studentList.end()) {
                    cout << "Student found:" << endl;
                    it->printStudentInfo();
                } else {
                    cout << "Student not found." << endl;
                }
            }
            break;

        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }

    }while(selection < 5);

return 0;
}
