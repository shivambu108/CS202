#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int findParent(int v, vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end());

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;
    for (Edge e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            mst.push_back(e);
            unionSets(e.u, e.v, parent, rank);
        }
    }

    // Print MST
    for (Edge e : mst)
        cout << e.u << " - " << e.v << " \t" << e.weight << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    kruskalMST(edges, V);
    return 0;
}
