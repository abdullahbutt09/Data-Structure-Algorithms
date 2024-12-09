#include <iostream>
using namespace std;
int main()
{

    int store = 1;
    for (int i = 1; i <= 10; i++)
    {
        cout << store << " ";
        store = store * 2;
    }
    return 0;
}