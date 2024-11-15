#include <iostream>
#include <vector>
#include <set>

using namespace std;

void vertexCover(int V, const vector<pair<int, int>>& edges) {
    set<int> vertex_cover;
    vector<bool> visited(V, false);

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        // If neither of the vertices are visited, add both to the cover
        if (!visited[u] && !visited[v]) {
            visited[u] = true;
            visited[v] = true;
            vertex_cover.insert(u);
            vertex_cover.insert(v);
        }
    }

    // Print the vertex cover
    cout << "Approximate Vertex Cover: ";
    for (int v : vertex_cover) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    vertexCover(V, edges);
    return 0;
}
