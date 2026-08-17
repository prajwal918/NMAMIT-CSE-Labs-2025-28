#include <iostream>
using namespace std;
class Complex
{
int real;
float imag;
public:
void read(int r,float i)
{
real=r;
imag=i;
}
void display()
{
cout<<real<<"+i"<<imag<<endl;
}
Complex operator+(Complex c)
{
Complex temp;
temp.real=real+c.real;
temp.imag=imag+c.imag;
return temp;
}
Complex operator-(Complex c)
{
Complex temp;
temp.real=real-c.real;
temp.imag=imag-c.imag;
return temp;
}
};
int main()
{
Complex c1,c2,c3,c4;
c1.read(1,1.4);
c2.read(3,2.2);
cout<<"C1: "<<endl;
c1.display();
cout<<"C2: "<<endl;
c2.display();
c3=c1+c2;
cout<<"C3:"<<endl;
c3.display();
c4=c2-c1;
cout<<"C4: "<<endl;
c4.display();
return 0;
}
