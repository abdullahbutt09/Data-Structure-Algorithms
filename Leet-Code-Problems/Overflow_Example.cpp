#include <iostream>
using namespace std;
int main()
{
    int x = 2147483647; // max int value
    x += 1;             // this causes overflow

    cout << x;
    return 0;
}