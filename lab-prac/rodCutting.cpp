#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(const vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i],  dp[i - j] + price[j - 1]);
        }
    }
    return dp[n];
}

int main() {
    vector<int> price = { 0, 5, 8, 9, 10, 17, 17, 20 };
    int n = price.size();
    cout << "Maximum profit: " << rodCutting(price, n) << endl;
    return 0;
}
