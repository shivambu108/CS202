#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>& arr) {
    vector<int> tail;  
    
    for (int num : arr) {
        auto pos = lower_bound(tail.begin(), tail.end(), num);  
        if(pos == tail.end()) tail.push_back(num); 
        else *pos = num;
    }
    return tail.size();
}

int main() {
    vector<int> arr = {3, 10, 2, 1, 20, 4, 6, 5, 30, 7};
    int result = lis(arr);
    cout << "Length of LIS: " << result << endl;
    return 0;
}
