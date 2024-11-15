#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

int shortestPathMultistageGraph(vector<vector<int>>& graph, int V) {
    vector<int> cost(V, INF);
    cost[V - 1] = 0;  // Cost of reaching the last vertex from itself is 0

    for (int i = V - 2; i >= 0; i--) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != INF) {
                cost[i] = min(cost[i], graph[i][j] + cost[j]);
            }
        }
    }

    return cost[0];
}

int main() {
    int V = 8;
    vector<vector<int>> graph = {
        {INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF}
    };

    cout << "The shortest path cost from source to destination is: " << shortestPathMultistageGraph(graph, V) << endl;
    return 0;
}
