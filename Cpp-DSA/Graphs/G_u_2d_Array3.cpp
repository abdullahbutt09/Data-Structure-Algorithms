#include <iostream>
using namespace std;

int main()
{
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    // Create a matrix initialized to 0
    int arr[10][10] = {0}; // Assuming max nodes = 10 for simplicity

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (format: u v for an edge between u and v):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        // Populate adjacency matrix
        arr[u][v] = 1;
        arr[v][u] = 1; // Assuming undirected graph
    }

    // Display the adjacency list
    cout << "\nGraph Adjacency List:\n";
    for (int i = 0; i <= nodes; i++) // Start from 1 for 1-indexed nodes
    {
        cout << i << " -> ";
        bool first = true;
        for (int j = 0; j <= nodes; j++)
        {
            if (arr[i][j] == 1)
            {
                if (!first)
                {
                    cout << ", ";
                }
                cout << j;
                first = false;
            }
        }
        cout << endl;
    }

    return 0;
}