#include <iostream>
#include <vector>
using namespace std; 

int coinCombinations(int amount, const vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // There is 1 way to make the amount 0: use no coins.

    for (const int& coin : coins) {
        for (int x = coin; x <= amount; x++) {
            dp[x] += dp[x - coin];
        }
    }
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Number of ways to make amount " << amount << " is " << coinCombinations(amount, coins) << endl;
    return 0;
}
