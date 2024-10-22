#include <iostream>
using namespace std;
int main()
{
    int count1 = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            count1++;
        }
    }

    // answer should be n^4 coz due to 4 loops!
    // value is 2 so 2^2 = 4

    cout << count1 << endl;

    int count2 = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                ++count2;
            }
        }
    }

    cout << count2 << endl;

    // answer should be n^4 coz due to 4 loops!
    // value is 3 so 3^3 = 27

    return 0;
}