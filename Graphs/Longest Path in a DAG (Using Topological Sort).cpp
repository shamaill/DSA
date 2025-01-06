#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
    }

    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack)
    {
        visited[v] = true;
        for (auto &[neighbor, weight] : adj[v])
            if (!visited[neighbor])
                topologicalSortUtil(neighbor, visited, Stack);
        Stack.push(v);
    }

    void longestPath(int src)
    {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);

        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        while (!Stack.empty())
        {
            int u = Stack.top();
            Stack.pop();

            if (dist[u] != INT_MIN)
            {
                for (auto &[v, weight] : adj[u])
                    if (dist[u] + weight > dist[v])
                        dist[v] = dist[u] + weight;
            }
        }

        cout << "Longest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << "Node " << i << " -> Distance: " << (dist[i] == INT_MIN ? "INF" : to_string(dist[i])) << endl;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.longestPath(1);
    return 0;
}
