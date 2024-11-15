#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Function to create the LPS (Longest Prefix Suffix) array
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);  // Initialize LPS array with zeros
    int length = 0;              // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP search function
void KMPSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // Preprocess the pattern to create the LPS array
    vector<int> lps = computeLPSArray(pattern);

    int i = 0;  // Index for text
    int j = 0;  // Index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  // Reset j based on the LPS array
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) { j = lps[j - 1];} 
            else { i++; }
        }
    }
}

// Main function to test the KMP algorithm
int main() {
    string text = "abxabcabcaby";
    string pattern = "abcaby";
    KMPSearch(text, pattern);
    return 0;
}
