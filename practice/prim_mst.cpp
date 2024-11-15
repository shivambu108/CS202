// Shivambu Dev Pandey
// 23bcs123
// CS202 - DAA
// Lab 3
// 23/08/2024
// Program 1 :  Minimum Spanning Tree - Prim's Algorithm  


#include <bits/stdc++.h>
using namespace std;

#define VERTICES  5

int findMinKey(vector<int>& key, vector<bool>& mstSet) {
    int minKey = INT_MAX, minIndex;

    for(int v = 0; v < VERTICES; v++) {
        if(!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}


void printMST(vector<int>& parent,vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for(int i = 1; i < VERTICES ; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void primMST(vector<vector<int>>& graph) {
    vector<int> parent(VERTICES), key(VERTICES);
    vector<bool> mstSet(VERTICES);

    for(int i = 0; i < VERTICES ; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < VERTICES - 1; count++) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for(int v = 0; v < VERTICES; v++) {
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
