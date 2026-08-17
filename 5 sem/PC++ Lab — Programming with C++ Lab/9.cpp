#include <iostream>
using namespace std;
class shape
{
public:
double x;
double y;
void get_data();
virtual void display_area()=0;
};
void shape::get_data()
{
cout<<"Enter the values: ";
cin>>x>>y;
}
class triangle:public shape
{
public:
void display_area();
};
void triangle::display_area()
{
cout<<"The area of the triangle is: "<<"\n";
cout<<0.5*x*y<<"\n";
}
class rectangle:public shape
{
public:
void display_area();
};
void rectangle::display_area()
{
cout<<"The area of the rectangle is: "<<"\n";
cout<<x*y<<"\n";
}
int main()
{
int ch;
char c;
triangle tr;
rectangle re;
shape *sptr;
do
{
ch=0;
cout<<"Enter 1 r area of triangle, 2 for area of rectangle: "; cin>>ch;
switch(ch)
{
case 1:
sptr=&tr;
sptr->get_data();
sptr->display_area();
break;
case 2:
sptr=&re;
sptr->get_data();
sptr->display_area();
break;
default:
cout<<"Choice mismatch"<<"\n";
break;
}
cout<<"Do you want to continue: ";
cin>>c;
}while(c=='Y'||c=='y');
return 0;
}
