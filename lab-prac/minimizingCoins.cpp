#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int minimizingCoins(int amount, const std::vector<int>& coins) {
    std::vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // No coins are needed to make 0.

    for (int x = 1; x <= amount; x++) {
        for (const int& coin : coins) {
            if (x - coin >= 0 && dp[x - coin] != INT_MAX) {
                dp[x] = std::min(dp[x], dp[x - coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    std::vector<int> coins = {1, 3, 4};
    int amount = 6;
    std::cout << "Minimum number of coins to make amount " << amount << " is " << minimizingCoins(amount, coins) << std::endl;
    return 0;
}
