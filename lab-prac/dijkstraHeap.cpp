#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstraHeap(vector<vector<pii>>& adj, int src, int V) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& [weight, v] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " Distance from Source " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);
    
    adj[0].push_back({10, 1});
    adj[0].push_back({5, 4});
    adj[1].push_back({1, 2});
    adj[1].push_back({2, 4});
    adj[2].push_back({4, 3});
    adj[3].push_back({6, 0});
    adj[3].push_back({2, 4});
    adj[4].push_back({3, 1});
    adj[4].push_back({9, 2});

    int src = 0;
    dijkstraHeap(adj, src, V);
    return 0;
}
