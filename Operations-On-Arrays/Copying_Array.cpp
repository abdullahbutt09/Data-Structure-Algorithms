#include <iostream>
using namespace std;
int main()
{
    int size = 5;
    int arr[size] = {1, 2, 3, 7, 8};
    int arr2[size] = {0};

    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << " ";
    }
    

    return 0;
}