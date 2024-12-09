#include <iostream>
using namespace std;
int main()
{
    int arr[50];
    int used_size = 5;

    arr[0] = 1;
    arr[1] = 14;
    arr[2] = 145; // index 2 element trying to delete
    arr[3] = 1456;
    arr[4] = 14578;
    cout << endl;
    for (int i = 0; i < used_size; i++)
    {
        cout << "Index " << i << " is " << arr[i] << endl;
    }

    // performing deletion
    int index = 2;
    used_size--;
    for (int i = index; i < used_size; i++)
    {
        arr[i] = arr[i + 1];
    }
    cout << endl;
    cout<<"| updated array |"<<endl;
    for (int i = 0; i < used_size; i++)
    {
        cout << "Index " << i << " is " << arr[i] << endl;
    }

    return 0;
}