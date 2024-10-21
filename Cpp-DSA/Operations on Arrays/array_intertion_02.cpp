#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void display(int arr[], int);
int insert(int arr[], int used_size, int capacity, int element, int index);

int main()
{
    int arr[50] = {1, 256, 67, 34, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int used_size = 5;
    int element = 1122;
    int index = 2;

    bool check = insert(arr, used_size, size, element, index);

    if (check)
    {
        cout << "you can insert elements!" << endl;
        cout << "insertion element successful!" << endl;
        used_size++;
        display(arr, used_size);
    }
    else
    {
        cout << "you cannot insert elements!";
    }

    return 0;
}

void display(int arr[], int used_size)
{
    for (int i = 0; i < used_size; i++)
    {
        cout << arr[i] << endl;
    }
}

int insert(int arr[], int used_size, int capacity, int element, int index)
{
    if (used_size >= capacity)
    {
        return 0;
    }

    for (int i = used_size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;

    return 1;
}