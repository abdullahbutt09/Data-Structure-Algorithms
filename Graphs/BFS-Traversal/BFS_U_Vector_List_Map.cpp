#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>

using namespace std;

void PrepareAdjList(map<int, list<int>> &AdjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
}

void PrintAdjList(map<int, list<int>> &AdjList)
{
    for (auto i : AdjList)
    {
        cout << i.first << " -> ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void bfstraversal(map<int, list<int>> &AdjList, vector<int> &Answer, map<int, bool> &visited, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int FrontNode = q.front();
        q.pop();

        Answer.push_back(FrontNode);

        for (auto i : AdjList[FrontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    map<int, list<int>> AdjList;
    vector<int> Answer;

    map<int, bool> visited;

    PrepareAdjList(AdjList, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfstraversal(AdjList, Answer, visited, i);
        }
    }
    return Answer;
}

int main()
{
    cout << endl;
    map<int, list<int>> AdjList;
    vector<pair<int, int>> Edges;

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;

        Edges.push_back({u, v});
    }

    PrepareAdjList(AdjList, Edges);
    cout << endl;
    cout << "Adjacency List" << endl;
    cout << endl;
    PrintAdjList(AdjList);
    cout << endl;

    vector<int> result = BFS(4 , Edges);

    for(int i : result){
        cout << i << " ";
    }

    cout << endl;
    return 0;
}