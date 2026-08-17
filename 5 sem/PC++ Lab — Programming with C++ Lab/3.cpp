#include <iostream>
using namespace std;
class Time
{
int hours;
int minutes;
public:
void read(int h,int m)
{
hours=h;
minutes=m;
}
void put()
{
cout<<"hours: "<<hours<<endl;
cout<<"minutes: "<<minutes<<endl;
}
void compute(Time t1,Time t2)
{
int h=(t1.minutes+t2.minutes)/60;
minutes=(t1.minutes+t2.minutes)%60;
hours=t1.hours+t2.hours+h;
}
};
int main()
{
Time A,B,C;
A.read(4,40);
B.read(4,40);
cout<<"A: "<<endl;
A.put();
cout<<"B: "<<endl;
B.put();
C.compute(A,B);
cout<<"C: "<<endl;
C.put();
return 0;
}
