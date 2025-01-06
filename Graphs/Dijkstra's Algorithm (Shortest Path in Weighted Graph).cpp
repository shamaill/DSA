#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

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
        adj[v].push_back({u, weight}); // Undirected graph
    }

    void dijkstra(int src)
    {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto &[v, weight] : adj[u])
            {
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << "Node " << i << " -> Distance: " << dist[i] << endl;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 4, 7);

    g.dijkstra(0);
    return 0;
}
