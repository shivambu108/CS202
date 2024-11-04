#include <bits/stdc++.h>
using namespace std;

void shortestPathMultistageGraph(const vector<vector<int>>& adjMat, int stages) {
    int n = adjMat.size();
    vector<int> cost(n, INT_MAX), path(n, -1);          
    cost[n - 1] = 0;                  

    for(int i = n - 2; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(adjMat[i][j] != INT_MAX) {  
                int newCost = adjMat[i][j] + cost[j];
                if(newCost < cost[i]) {
                    cost[i] = newCost;  
                    path[i] = j;        
                }
            }
        }
    }

    cout << "Minimum cost to reach end: " << cost[0] << endl;
    cout << "Path: ";
    int node = 0;
    while(node != -1) {
        cout << node << " ";
        node = path[node];
    }
    cout << endl;
}

int main() {
    int stages = 6;
    int n = 11; 
    vector<vector<int>> adjMat(n, vector<int>(n, INT_MAX));

    adjMat[0][1] = 2; adjMat[0][2] = 3; adjMat[0][3] = 5;
    adjMat[1][4] = 8; adjMat[1][5] = 2; adjMat[1][6] = 6;
    adjMat[2][4] = 4; adjMat[2][5] = 5; adjMat[2][6] = 3;
    adjMat[3][4] = 4; adjMat[3][5] = 2; adjMat[3][6] = 4;
    adjMat[4][7] = 3; adjMat[4][8] = 2; adjMat[4][9] = 4;
    adjMat[5][7] = 4; adjMat[5][8] = 3; adjMat[5][9] = 2;
    adjMat[6][7] = 7; adjMat[6][8] = 4; adjMat[6][9] = 2;
    adjMat[7][10]= 5; adjMat[8][10]= 6; adjMat[9][10]= 3;

    shortestPathMultistageGraph(adjMat, stages);
    return 0;
}