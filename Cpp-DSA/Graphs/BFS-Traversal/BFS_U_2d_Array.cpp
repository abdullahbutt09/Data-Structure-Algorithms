#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Adjacency matrix for the graph
    int arr[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}};

    cout << "BFS Traversal:\n";

    queue<int> q;
    int visited[5] = {0}; // Initialize all nodes as not visited
    int startNode = 0;    // Starting node for BFS

    cout << startNode << " ";
    visited[startNode] = 1; // Mark the start node as visited
    q.push(startNode);      // Add the start node to the queue

    while (!q.empty())
    {
        int node = q.front(); // Get the front element
        q.pop();              // Remove it from the queue

        for (int j = 0; j < 5; j++) // Traverse all neighbors
        {
            if (arr[node][j] == 1 && visited[j] == 0) // If there's an edge and the node isn't visited
            {
                cout << j << " ";  // Print the node
                visited[j] = 1;    // Mark it as visited
                q.push(j);         // Add it to the queue
            }
        }
    }

    return 0;
}