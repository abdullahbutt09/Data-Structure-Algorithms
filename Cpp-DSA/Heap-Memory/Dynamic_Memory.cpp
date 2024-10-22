#include <iostream>
using namespace std;
int main()
{
    int *val = new int[10];

    cout << "Enter Value to store in heap Memory : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> val[i];
    }

    // Output values
    for (int i = 0; i < 5; i++)
    {
        cout << val[i] << " ";
    }

    // Clean up memory
    delete[] val;
    return 0;
}