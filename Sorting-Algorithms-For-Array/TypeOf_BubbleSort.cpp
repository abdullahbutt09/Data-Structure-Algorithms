#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {45, 56, 5, 3, 89};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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