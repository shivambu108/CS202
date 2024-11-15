#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ALPHABET_SIZE 256  // Assuming ASCII

// Function to create the bad character table
std::vector<int> createBadCharacterTable(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> badChar(ALPHABET_SIZE, -1);

    for (int i = 0; i < m; i++) {
        badChar[pattern[i]] = i;  // Record the last occurrence of each character
    }

    return badChar;
}

// Boyer-Moore search function
void BoyerMooreSearch(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();

    std::vector<int> badChar = createBadCharacterTable(pattern);

    int shift = 0;  // Shift of the pattern over the text

    while (shift <= (n - m)) {
        int j = m - 1;

        // Keep reducing j while characters of pattern and text match
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            std::cout << "Pattern found at index " << shift << std::endl;

            // Shift pattern to align with next character in text after pattern
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            // Shift pattern so that bad character in text aligns with last occurrence in pattern
            shift += std::max(1, j - badChar[text[shift + j]]);
        }
    }
}

// Main function to test the Boyer-Moore algorithm
int main() {
    std::string text = "abxabcabcaby";
    std::string pattern = "abcaby";
    BoyerMooreSearch(text, pattern);
    return 0;
}
