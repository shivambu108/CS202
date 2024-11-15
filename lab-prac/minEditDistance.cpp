#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int minEditDistance(const std::string& A, const std::string& B) {
    int m = A.size(), n = B.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[m][n];
}


int main() {
    std::string A = "edit";
    std::string B = "edited";
    std::cout << "Minimum Edit Distance: " << minEditDistance(A, B) << std::endl;
    return 0;
}
