#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int arr[50];
    int size = sizeof(arr) / sizeof(arr[0]);
    int using_size = 6;

    srand(time(0));
    for (int i = 0; i < using_size; i++)
    {
        arr[i] = rand() % 50;
    }

    for (int i = 0; i < using_size; i++)
    {
        cout << "Element on index " << i << " is " << arr[i] << endl;
    }

    int index, number = 0;
    cout << "Enter the index you want to insert element : ";
    cin >> index;

    while (index > 50)
    {
        cout << "array size is " << size << " so kindly enter a lower index below " << index << endl;
        cin >> index;
    }

    cout << "Enter a number you want to insert at index " << index << " : ";
    cin >> number;

    ++using_size;

    for (int i = using_size; i >= index; i--)
    {
        arr[i] = arr[i - 1];
    }
    

    arr[index] = number;

    cout << "Updated array!" << endl;
    for (int i = 0; i < using_size; i++)
    {
        cout << "Element on index " << i << " is " << arr[i] << endl;
    }

    return 0;
}