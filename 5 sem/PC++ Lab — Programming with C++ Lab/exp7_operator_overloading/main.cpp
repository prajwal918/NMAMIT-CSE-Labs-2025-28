#include <iostream>
using namespace std;

class Complex
{
    int real;
    float imag;
public:
    void read(int r, float i)
    {
        real = r;
        imag = i;
    }
    Complex operator + (Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    Complex operator - (Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
    void display()
    {
        cout << "Real: " << real << endl;
        cout << "Imaginary:" << imag << endl;
        cout << real << "+" << imag << "i" << endl;
    }
};

int main()
{
    Complex c1, c2, c3, c4;
    c1.read(4, 5.5);
    c2.read(3, 1.5);
    cout << "C1" << endl;
    c1.display();
    cout << "C2" << endl;
    c2.display();
    c3 = c1 + c2;
    c4 = c1 - c2;
    cout << "C3 = C1 + C2" << endl;
    c3.display();
    cout << "C4 = C1 - C2" << endl;
    c4.display();
    return 0;
}
