#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int lisR(vector<int> &nums, int i, int prev) {
    if(i == nums.size()) return 0; 

    int no = lisR(nums, i + 1, prev);

    int yes = 0;
    if(prev == -1 || nums[i] > nums[prev]) {
        yes = 1 + lisR(nums, i + 1, i);
    }

    return max(yes, no); 
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "Length of Longest Increasing Subsequence: " << lisR(nums, 0, -1) << endl;
    return 0;
}

