// work for both sorted & unsorted array!

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 45, 56, 109, 2, 3, 48, 5, 1009};
    int size = sizeof(arr) / sizeof(int);

    int target = 100;
    int count = 0; // Tell you that how much iterations he do to find the element!
    bool check = false;

    for (int i = 0; i < size; i++)
    {
        count++;
        if (arr[i] == target)
        {
            cout << "Element found at index " << i << endl;
            check = true;
            break;
        }
    }

    if (check)
    {
        cout << endl;
        cout << "Number of iterations done in loop to find the target element " << target << " is " << count << endl;
    }

    else
    {
        cout << endl;
        cout << "Element not found"<<endl;
        cout << "Number of iterations of the loop to find the target element " << target << " is " << count << endl;
    }

    return 0;
}