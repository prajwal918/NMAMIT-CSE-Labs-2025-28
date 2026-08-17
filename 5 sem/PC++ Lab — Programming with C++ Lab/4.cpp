#include <iostream>
using namespace std;
class Employee
{
char ename[20];
int eno;
int esalary;
public:
void read()
{
cout<<"Enter name"<<endl;
cin>>ename;
cout<<"Enter enumber"<<endl;
cin>>eno;
cout<<"Enter esalary"<<endl;
cin>>esalary;
}
void print()
{
cout<<"Name: "<<ename<<endl;
cout<<"Enumber: "<<eno<<endl;
cout<<"Esalary: "<<esalary<<endl;
}
};
int main()
{
Employee e[10];
int n;
cout<<"Enter number of employees"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"Eneter "<<i+1<<"Employee details"<<endl;
e[i].read();
}
for(int i=0;i<n;i++)
{
cout<<i+1<<"Employee details"<<endl;
e[i].print();
}
return 0;
}
