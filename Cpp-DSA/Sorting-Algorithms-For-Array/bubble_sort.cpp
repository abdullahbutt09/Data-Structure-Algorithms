#include <iostream>
using namespace std;
int main()
{
    srand(time(0));
    int arr[10];
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }

    cout << "unsorted array : ";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap(arr[j + 1], arr[j]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "sorted array : ";
    for (int value : arr)
    {
        cout << value << " ";
    }

    return 0;
}