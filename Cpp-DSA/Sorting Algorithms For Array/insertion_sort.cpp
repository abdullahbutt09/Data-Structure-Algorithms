#include <iostream>
using namespace std;
int main()
{

    srand(time(0));
    int arr[6] = {3, 9, 2, 4, 1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "unsorted array : ";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;

    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    cout << "sorted array : ";
    for (int value : arr)
    {
        cout << value << " ";
    }

    return 0;
}