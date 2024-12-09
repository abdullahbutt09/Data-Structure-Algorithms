#include <iostream>
using namespace std;

class Array
{

public:
    struct HeapMemory
    {
        int total_size;
        int used_size;
        int *ptr;
    };

    void CreateArray(struct HeapMemory *arr, int t_size, int u_size)
    {
        arr->total_size = t_size;
        arr->used_size = u_size;
        arr->ptr = new int[t_size];
    }
    void SetValForArray(struct HeapMemory *arr)
    {
        int value = 0;
        cout << "Total size -> " << arr->total_size << endl;
        cout << "Enter array values for size " << arr->used_size << endl;
        if (arr->used_size < 0)
        {
            cout << "Size less then zero not valid!" << endl;
        }
        for (int i = 0; i < arr->used_size; i++)
        {
            cin >> value;
            arr->ptr[i] = value;
        }
    }
    void DisplayArray(struct HeapMemory *arr)
    {
        for (int i = 0; i < arr->used_size; i++)
        {
            cout << "Value For index " << i << " is " << arr->ptr[i] << endl;
            cout << "Address For index " << i << " is " << &arr->ptr[i] << endl;
        }
    }
};

int main()
{
    Array myarr;
    Array ::HeapMemory heap;

    myarr.CreateArray(&heap, 30, 5);
    myarr.SetValForArray(&heap);
    myarr.DisplayArray(&heap);

    return 0;
}