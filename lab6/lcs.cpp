// Shivambu Dev Pandey
// 23bcs123
// CS202 - DAA
// Lab 6
// 04/10/2024
// Program 1 :  Longest Common Subsequence 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    string s1 = "ABCBDAB";
    string s2 = "BDCAB";

    cout << "Length of Longest Common Subsequence: " << LCS(s1, s2) << endl;
    return 0;
}
