#include <iostream>
using namespace std;

class Solution
{
public:
    int sumOfMultiples(int n)
    {
        int storesum = 0;

        for (int i = 0; i <= n; i++)
        {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
            {
                storesum += i;
            }
        }

        return storesum;
    }
};

int main()
{
    int nthterm = 10;
    Solution s1;
    cout << s1.sumOfMultiples(nthterm);

    return 0;
}