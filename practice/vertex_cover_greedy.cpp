#include <iostream>
#include <vector>
#include <set>
using namespace std;

void vertex_cover_greedy(vector<pair<int, int>>& edges, int num_vertices) {
    set<pair<int, int>> vis;
    set<int> vc;

    while (vis.size() < edges.size()) {
        for (auto edge : edges) {
            if (vis.find(edge) == vis.end()) {
                int u = edge.first;
                int v = edge.second;
                vc.insert(u);
                vc.insert(v);
                for (auto e : edges) {
                    if (e.first == u || e.second == u || e.first == v || e.second == v) {
                        vis.insert(e);
                    }
                }
                break;
            }
        }
    }

    cout << "Vertex Cover: ";
    for(int v : vc) { cout << v << " ";}
    cout << endl;
}

int main() {
    vector<pair<int, int>> graph = {{1, 2}, {1, 3}, {1, 4},  {2, 5}, {2, 6}, 
                                    {3, 6}, {3, 7}, {3, 8},  {4, 7}, {4, 9}, 
                                    {5, 8}, {5, 9}, {5, 10}, {6, 8}, {6, 10},
                                    {7, 9}, {7, 10},{8, 9},  {8, 10},{9, 10},};

    int num_vertices = 10;

    vertex_cover_greedy(graph, num_vertices);
    return 0;
}
