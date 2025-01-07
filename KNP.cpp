#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPSArray(const string &pattern, vector<int> &lps) {
    int m = pattern.length();
    int length = 0; // length of the previous longest prefix suffix
    lps[0] = 0;     // lps[0] is always 0

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
}

// KMP algorithm for pattern matching
void KMPSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    // Compute the LPS array
    vector<int> lps(m, 0);
    computeLPSArray(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    KMPSearch(text, pattern);

    return 0;
}
