#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    private:
        int accno;
        string name;
        float balance;
        int amt;
    public:
        void read()
        {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter account number: ";
            cin >> accno;
            cout << "Enter balance: ";
            cin >> balance;
        }
        void put_balance()
        {
            cout << "Current balance: " << balance << endl;
        }
        void deposit()
        {
            cout << "\nEnter amount to be deposited: ";
            cin >> amt;
            balance = balance + amt;
            put_balance();
        }
        void withdraw()
        {
            cout << "\nEnter amount to be withdrawn: ";
            cin >> amt;
            if (amt > balance)
            {
                cout << "Insufficient balance\n";
            }
            else
            {
                balance = balance - amt;
                put_balance();
            }
        }
        void display()
        {
            cout << "\nAccount Details:" << endl;
            cout << "Name of the depositor: " << name << endl;
            cout << "Account Number: " << accno << endl;
            cout << "Balance: " << balance << endl;
        }
};

int main()
{
    BankAccount b;
    b.read();
    b.display();
    b.deposit();
    b.withdraw();
    return 0;
}
