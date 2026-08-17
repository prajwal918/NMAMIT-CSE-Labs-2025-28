#include <iostream>
using namespace std;
class COMPLEX
{
private:int r, i;
public: void read();
void disp();
friend COMPLEX ADD(int x, COMPLEX c);
friend COMPLEX ADD(COMPLEX c1,COMPLEX c2);
};
void COMPLEX::read()
{
cin>>r>>i;
}
void COMPLEX::disp()
{
cout<<r<<"+"<<i<<"i";
}
COMPLEX ADD(int x, COMPLEX c)
{
COMPLEX t;
t.r=x+c.r;
t.i=c.i;
return t;
}
COMPLEX ADD(COMPLEX c1,COMPLEX c2)
{
COMPLEX t;
t.r=c1.r+c2.r;
t.i=c1.i+c2.i;
return t;
}
int main()
{
COMPLEX c1,c2,c3,c4;
int a;
cout<<"Enter 1st Complex no :";
c1.read();
cout<<"Enter 2nd Complex no :";
c2.read();
cout<<"Enter the value of a:";
cin>>a;
c3=ADD(a,c2);
c4=ADD(c1,c2);
cout<<"\n1st Complex no :";
c1.disp();
cout<<"\n2nd Complex no :";
c2.disp();
cout<<"\n\nADD(a,c2) :";
c3.disp();
cout<<"\nADD(c1,c2) :";
c4.disp();
return 0;
}
