#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(const vector<int>& nums, int target) {
    int n = nums.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;

    if (subsetSum(nums, target)) {
        cout << "Subset with the given sum found." << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }
    return 0;
}
