#include <iostream>
using namespace std;

class Solution
{
public:
    void findTwoSum(int arr[], int size, int target)
    {
        int index1, index2;
        for (index1 = 0; index1 < size; index1++)
        {
            for (index2 = index1 + 1; index2 < size; index2++)
            {
                if (arr[index1] + arr[index2] == target)
                {
                    cout << "Indices: " << index1 << " and " << index2 << endl;
                    return;
                }
            }
        }
        cout << "No two sum solution found." << endl;
    }
};

int main()
{
    Solution solution;
    int arr[5] = {1, 2, 3, 4, 5};
    int target = 9;

    solution.findTwoSum(arr, 5, target);

    return 0;
}
