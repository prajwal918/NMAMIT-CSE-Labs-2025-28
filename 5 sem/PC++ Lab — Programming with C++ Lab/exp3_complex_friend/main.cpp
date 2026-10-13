#include <iostream>
using namespace std;

class Complex {
private:
    int r, i;
public:
    void read();
    void display();
    friend Complex ADD(int x, Complex c);
    friend Complex ADD(Complex c1, Complex c2);
};

void Complex::read() {
    cout << "Enter Real number:";
    cin >> r;
    cout << "Enter Imaginary number:";
    cin >> i;
}

void Complex::display() {
    cout << r << "+" << i << "i";
}

Complex ADD(int x, Complex c) {
    Complex t;
    t.r = x + c.r;
    t.i = c.i;
    return t;
}

Complex ADD(Complex c1, Complex c2) {
    Complex t;
    t.r = c1.r + c2.r;
    t.i = c1.i + c2.i;
    return t;
}

int main() {
    Complex c1, c2, c3, c4;
    int a;
    cout << "Enter 1st complex number:";
    c1.read();
    cout << "Enter 2nd complex number:";
    c2.read();
    cout << "Enter value of a:";
    cin >> a;
    c3 = ADD(a, c2);
    c4 = ADD(c1, c2);
    cout << "1st Complex number:";
    c1.display();
    cout << "2nd Complex number:";
    c2.display();
    cout << "ADD(a,c2):";
    c3.display();
    cout << "ADD(c1,c2):";
    c4.display();
    return 0;
}
