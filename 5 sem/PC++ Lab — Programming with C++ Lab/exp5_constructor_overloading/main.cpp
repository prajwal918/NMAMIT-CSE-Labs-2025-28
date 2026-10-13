#include <iostream>
using namespace std;

class Sample
{
    int i;
    char c;
    double d;
public: Sample()
    {
        i = 0;
        c = '\0';
        d = 0.0;
    }
    Sample(int x, char y, double z)
    {
        i = x;
        c = y;
        d = z;
    }
    Sample(Sample &s)
    {
        i = s.i;
        c = s.c;
        d = s.d;
    }
    Sample(int x, double z, char y='s')
    {
        i = x;
        c = y;
        d = z;
    }
    void display()
    {
        cout << "Integer:" << i << endl;
        cout << "Character:" << c << endl;
        cout << "Float:" << d << endl;
    }
};

int main()
{
    Sample S1;
    cout << "S1";
    S1.display();
    Sample S2(10, 'a', 4.5);
    cout << "S2";
    S2.display();
    Sample S3(30, 4.5);
    cout << "S3";
    S3.display();
    Sample S4(S2);
    cout << "S4";
    S4.display();
    return 0;
}
