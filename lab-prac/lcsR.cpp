#include <iostream>
#include <string>
using namespace std;

int lcsR(string &s1, string &s2, int i, int j) {
    if(i == 0 || j == 0) return 0; 
    if(s1[i - 1] == s2[j - 1])
        return 1 + lcsR(s1, s2, i - 1, j - 1); 
    else
        return max(lcsR(s1, s2, i - 1, j), lcsR(s1, s2, i, j - 1)); 
}

int main() {
    string s1 = "ABCBDAB";
    string s2 = "BDCAB";
    int n = s1.size(), m = s2.size();
    cout << "Length of Longest Common Subsequence: " << lcsR(s1, s2, n, m) << endl;
    return 0;
}

