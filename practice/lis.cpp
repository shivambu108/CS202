// Shivambu Dev Pandey
// 23bcs123
// CS202 - DAA
// Lab 6
// 04/10/2024
// Program 1 :  Longest Increasing Subsequence 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1); 
    int lis = 1;

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lis = max(lis, dp[i]);
    }
    return lis;
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "Length of Longest Increasing Subsequence: " << LIS(nums) << endl;
    return 0;
}
