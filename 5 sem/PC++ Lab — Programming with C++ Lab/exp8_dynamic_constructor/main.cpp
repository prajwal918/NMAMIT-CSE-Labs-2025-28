#include <iostream>
#include <cstring>
using namespace std;

class String
{
    int length;
    char *name;
public:
    String()
    {
    }
    String(char s[])
    {
        length = strlen(s);
        name = new char[length + 1];
        strcpy(name, s);
    }
    void join(String A, String B)
    {
        length = A.length + B.length;
        name = new char[length + 1];
        name = strcpy(name, A.name);
        name = strcat(name, B.name);
    }
    void display()
    {
        cout << "name:" << name << endl;
    }
};

int main()
{
    String S1("Wel");
    String S2("fare");
    cout << "S1" << endl;
    S1.display();
    cout << "S2" << endl;
    S2.display();
    String S3;
    S3.join(S1, S2);
    String S4;
    S4.join(S1, S3);
    cout << "S3" << endl;
    S3.display();
    cout << "S4" << endl;
    S4.display();
    return 0;
}
