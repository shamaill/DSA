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
        adj[v].push_back(u); // Undirected graph
    }

    bool DFSUtil(int node, vector<bool> &visited, int parent)
    {
        visited[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (DFSUtil(neighbor, visited, node))
                    return true;
            }
            else if (neighbor != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool hasCycle()
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && DFSUtil(i, visited, -1))
                return true;
        }
        return false;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0); // Cycle
    g.addEdge(3, 4);

    cout << (g.hasCycle() ? "Cycle detected" : "No cycle") << endl;
    return 0;
}
