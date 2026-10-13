#include <iostream>
using namespace std;

class Employee
{
private:
    int eno;
    string ename;
    double salary;
public:
    void readdata()
    {
        cout << "Enter employee number:";
        cin >> eno;
        cout << "Enter employee name:";
        cin >> ename;
        cout << "Enter employee salary:";
        cin >> salary;
    }
    void displaydata()
    {
        cout << "Employee number:" << eno << endl;
        cout << "Employee name:" << ename << endl;
        cout << "Employee salary:" << salary << endl;
    }
};

int main()
{
    int n;
    Employee e[10];
    cout << "Enter the number of employees:" << endl;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        e[i].readdata();
        cout << endl;
    }
    for(int i=0; i<n; i++)
    {
        e[i].displaydata();
        cout << endl;
    }
    return 0;
}
