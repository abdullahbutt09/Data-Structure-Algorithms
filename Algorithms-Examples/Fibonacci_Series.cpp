#include <iostream>
using namespace std;
int main()
{

    // 1 variable value print karega
    // 1 variable new value store karega!

    int First_Number = 0;
    int Second_Number = 1;
    int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << First_Number <<" ";
        temp = Second_Number;
        Second_Number = Second_Number + First_Number;
        First_Number = temp;
    }

    /*
    1st iteration.
    temp = b | temp = 1;
    b = b+a; === b = 0+1 = 1
    a = temp; a = 1;

    -> 0 output

    2nd iteration.
    temp = b | temp = 1;
    b = b+a; === b = 1+1 = 2
    a = temp; a = 1;

    -> 1 output

    3rd iteration.
    temp = b | temp = 2;
    b = b+a; === b = 1+1 = 2
    a = temp; a = 2;

    -> 1 output

    4th iteration.
    temp = b | temp = 2;
    b = b+a; === b = 2+1 = 3
    a = temp; a = 2;

    -> 2 output 

    5th iteration.
    temp = b | temp = 3;
    b = b+a; === b = 3+2 = 5
    a = temp; a = 3;

    -> 3 output 

    6th iteration.
    temp = b | temp = 5;
    b = b+a; === b = 5+3 = 8
    a = temp; a = 5;

    -> 5 output 

    */

    return 0;
}