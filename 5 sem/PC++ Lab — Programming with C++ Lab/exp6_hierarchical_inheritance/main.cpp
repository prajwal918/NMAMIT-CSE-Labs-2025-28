#include <iostream>

using namespace std;

class Student
{
protected: char name[20];
    int age, usn;
public:
    void getStudent()
    {
        cout << "Enter name, age, usn\n";
        cin >> name >> age >> usn;
    }
};

class Medical: public Student
{
    int year;
public:
    void getMedical()
    {
        cout << "Year:";
        cin >> year;
    }
    void display()
    {
        cout << "\n Medical Student details:\n";
        cout << " Age:" << age;
        cout << "\nName:" << name;
        cout << "\nUSN:" << usn;
        cout << "\nYear:" << year;
    }
};

class Engineering: public Student
{
    int sem;
    char branch[3];
public:
    void getEngineering()
    {
        cout << "Enter sem, branch:\n";
        cin >> sem >> branch;
    }
    void display()
    {
        cout << "\n Engineering Student details:\n";
        cout << "Name:" << name;
        cout << "\nAge:" << age;
        cout << "\nUSN:" << usn;
        cout << "\nSem:" << sem;
        cout << "\nBranch:" << branch;
    }
};

int main()
{
    Medical m1;
    Engineering e1;
    cout << "Enter Medical Student details:\n";
    m1.getStudent();
    m1.getMedical();
    cout << "Enter Engineering Student details:\n";
    e1.getStudent();
    e1.getEngineering();
    m1.display();
    e1.display();
    return 0;
}
