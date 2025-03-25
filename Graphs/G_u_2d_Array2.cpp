#include <iostream>
using namespace std;
int main()
{

    int arr[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 0, 1, 0, 0, 0},
                     {0, 1, 0, 1, 0, 0, 0, 0},
                     {0, 0, 1, 0, 1, 1, 0, 0},
                     {0, 1, 0, 1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 1, 1},
                     {0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 1, 0, 0}};

    int rows = sizeof(arr) / sizeof(arr[0]); // Get number of rows
    int cols = sizeof(arr[0]) / sizeof(int); // Get number of columns (or use rows since it's square)

    cout << "\nAdjacent Matrix\n";
    for (int i = 1; i < rows; i++)
    {
        cout << "\t\t\t" << i << " -> ";
        bool visted = true;
        for (int j = 1; j < cols; j++)
        {
            if (arr[i][j] == 1)
            {
                if (!visted)
                {
                    cout << " ,";
                }
                cout << " " << j;
                visted = false;
            }
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}