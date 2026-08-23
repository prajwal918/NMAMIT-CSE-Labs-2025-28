#include <iostream>
using namespace std;

class Time
{
    private:
        int hour;
        int min;
    public:
        void read()
        {
            cout << "Enter hours:";
            cin >> hour;
            cout << "Enter minutes:";
            cin >> min;
        }
        void display()
        {
            cout << "\nThe Time is :" << hour << " hours and " << min << " minutes" << endl;
        }
        void compute(Time t1, Time t2)
        {
            int h = (t1.min + t2.min) / 60;
            min = (t1.min + t2.min) % 60;
            hour = t1.hour + t2.hour + h;
        }
};

int main()
{
    Time A, B, C;
    cout << "\n A" << endl;
    A.read();
    cout << "\n B" << endl;
    B.read();
    cout << "\n A" << endl;
    A.display();
    cout << "\n B" << endl;
    B.display();
    C.compute(A, B);
    cout << "\n C" << endl;
    C.display();
    return 0;
}
