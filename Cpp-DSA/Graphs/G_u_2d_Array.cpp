#include <iostream>
using namespace std;

int main()
{
    int arr[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}};

    int rows = sizeof(arr) / sizeof(arr[0]); // Get number of rows
    int cols = sizeof(arr[0]) / sizeof(int); // Get number of columns (or use rows since it's square)

    cout << "Graph Edges\n";
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 1) // Only print edges
            {
                cout << i << " -> " << j << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
