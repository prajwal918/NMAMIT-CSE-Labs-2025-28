#include <iostream>
using namespace std;

class Time
{
private:
    int hour, minutes;
public:
    void read()
    {
        cout << "Enter hours:";
        cin >> hour;
        cout << "Enter minutes:";
        cin >> minutes;
    }
    void display()
    {
        cout << "\nThe Time is: " << hour << " hours and " << minutes
             << " minutes" << endl;
    }
    void compute(Time t1, Time t2)
    {
        int h = (t1.minutes + t2.minutes) / 60;
        minutes = (t1.minutes + t2.minutes) % 60;
        hour = t1.hour + t2.hour + h;
    }
};

int main()
{
    Time A, B, C;
    cout << "\nA" << endl;
    A.read();
    cout << "\nB" << endl;
    B.read();
    cout << "\nA" << endl;
    A.display();
    cout << "\nB" << endl;
    B.display();
    C.compute(A, B);
    cout << "\nC" << endl;
    C.display();
    return 0;
}
