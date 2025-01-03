#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main()
{
    cout << "Enter Password: ";
    char ch;
    string password;

    while (true)
    {
        ch = _getch();

        if (ch == '\r')
        {
            if (password.length() < 8)
            {
                cout << endl;
                cout << "\nYour password length cannot be " << password.length() << "!" <<endl;
                cout << "Sir your password length should be 8 or more than 8 characters!"<<endl;
                cout << endl;
                cout << "Enter Password : ";
                password.clear();
            }

            else
            {
                cout << endl;
                break;
            }
        }

        else if (ch == '\b')
        {
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }

        else
        {
            password.push_back(ch);
            cout << "*";
        }
    }

    cout << password << endl;
    return 0;
}