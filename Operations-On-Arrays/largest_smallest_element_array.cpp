#include <iostream>
using namespace std;
int main()
{
    int arr[] = {100, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int temp1 = arr[0];
    int temp2 = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > temp1)
        {
            temp1 = arr[i];
        }
        if (arr[i] < temp2)
        {
            temp2 = arr[i];
        }
    }

    cout << "Largest value in the array is : " << temp1 << endl;
    cout << "smallest value in the array is : " << temp2 << endl;
    return 0;
}