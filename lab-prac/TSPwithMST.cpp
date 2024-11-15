#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findMinVertex(vector<int>& weight, vector<bool>& visited, int V) {
    int minVertex = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void primsMST(const vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1);
    vector<int> weight(V, INT_MAX);
    vector<bool> visited(V, false);
    weight[0] = 0;

    for (int i = 0; i < V - 1; i++) {
        int minVertex = findMinVertex(weight, visited, V);
        visited[minVertex] = true;

        for (int j = 0; j < V; j++) {
            if (graph[minVertex][j] && !visited[j] && graph[minVertex][j] < weight[j]) {
                weight[j] = graph[minVertex][j];
                parent[j] = minVertex;
            }
        }
    }

    cout << "MST using Prim's Algorithm:" << endl;
    for (int i = 1; i < V; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primsMST(graph, V);
    return 0;
}
