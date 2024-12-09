#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(int);

    int low, count = 0;
    int high = size - 1;
    int element = 9;

    while (low <= high)
    {
        count++;
        int mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            cout << "Element found at index " << mid << endl;
            break;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }

    cout << "Number of iterations " << count << endl;

    return 0;
}

// work for only sorted array!