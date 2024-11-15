#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void primMST(vector<vector<pii>>& adj, int V) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto& [weight, v] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print MST
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << key[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);
    
    adj[0].push_back({2, 1});
    adj[0].push_back({6, 3});
    adj[1].push_back({2, 0});
    adj[1].push_back({3, 2});
    adj[1].push_back({8, 3});
    adj[1].push_back({5, 4});
    adj[2].push_back({3, 1});
    adj[2].push_back({7, 4});
    adj[3].push_back({6, 0});
    adj[3].push_back({8, 1});
    adj[3].push_back({9, 4});
    adj[4].push_back({5, 1});
    adj[4].push_back({7, 2});
    adj[4].push_back({9, 3});

    primMST(adj, V);
    return 0;
}
