#include <iostream>
using namespace std;
int main()
{
    int number = 97;

    bool found = true;

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            found = false;
            break;
        }
    }

    if (found)
    {
        cout << "Number is prime";
    }
    else
    {
        cout << "not prime bro!";
    }

    // checking prime number in the array!

    return 0;
}