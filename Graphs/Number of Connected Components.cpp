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

    void DFSUtil(int node, vector<bool> &visited)
    {
        visited[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

    int countConnectedComponents()
    {
        vector<bool> visited(V, false);
        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                count++;
                DFSUtil(i, visited);
            }
        }
        return count;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout << "Connected Components: " << g.countConnectedComponents() << endl;
    return 0;
}
