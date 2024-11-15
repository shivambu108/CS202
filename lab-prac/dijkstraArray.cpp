#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinVertex(vector<int>& dist, vector<bool>& visited, int V) {
    int minDist = INT_MAX;
    int minIndex;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstraArray(vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = findMinVertex(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " Distance from Source " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}};

    int src = 0;
    dijkstraArray(graph, src, V);
    return 0;
}
