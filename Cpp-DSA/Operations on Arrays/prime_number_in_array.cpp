#include <iostream>
using namespace std;
int main()
{
    srand(time(0));
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " is at index number " << i << endl;
    }

    cout << endl;
    cout << endl;

    bool isprime = true;
    int j = 0;

    if (isprime)
    {
        for (int i = 0; i < size; i++)
        {
            for (j = 2; j < arr[i]; j++)
            {
                if (arr[i] % j == 0)
                {
                    cout << "";
                    break;
                }
            }
            if (arr[i] == j)
            {
                cout << "Prime number in the array is : " << arr[i] << " " << endl;
                isprime = false;
            }
        }
    }
    if (isprime)
    {
        cout << "No prime found in the array!" << endl;
    }
    return 0;
}