// Shivambu Dev Pandey
// 23bcs123
// CS202 - DAA
// Lab 5
// 23/08/2024
// Program 1 :  Dijkstra's Algorithm


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; //(distance, node)

void dijkstra(int src, vector<vector<pii>>& adj, int n) {
    vector<int> dist(n, INT_MAX); 
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()) {
        int d = pq.top().first;  
        int u = pq.top().second; 
        pq.pop();
        
        if(d>dist[u]) continue;
        
        for(auto& edge : adj[u]) {
            int v = edge.second; 
            int weight = edge.first; 

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout<<"Shortest distances from source node "<<src<<":\n";
    for(int i = 0; i<n; ++i) {
        cout<<"Node "<<i<<": "<<dist[i]<<"\n";
    }
}

int main() {
    int n, e;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>e;

    vector<vector<pii>> adj(n);  
    
    cout<<"Enter the edges in the format (u v w) where u -> v with weight w:\n";
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); 
    }
    
    int src;
    cout<<"Enter the source node: ";
    cin>>src;

    dijkstra(src, adj, n);

    return 0;
}
