#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int res = 0;
        int actual_num = x;

        for (; x > 0; x /= 10)
        {
            if (res > (INT_MAX - x) / 10)
            {
                return false; // Overflow would occur
            }
            res = x % 10 + res * 10;
        }

        if (res == actual_num)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s1;
    cout << s1.isPalindrome(85778);
}