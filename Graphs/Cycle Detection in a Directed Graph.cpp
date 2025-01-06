#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool DFSUtil(int node, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor] && DFSUtil(neighbor, visited, recStack))
                return true;
            if (recStack[neighbor])
                return true;
        }

        recStack[node] = false;
        return false;
    }

    bool hasCycle()
    {
        vector<bool> visited(V, false), recStack(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && DFSUtil(i, visited, recStack))
                return true;
        }
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); // Cycle

    cout << (g.hasCycle() ? "Cycle detected" : "No cycle") << endl;
    return 0;
}
