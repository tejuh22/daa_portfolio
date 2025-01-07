#include <iostream>
#include <string>
using namespace std;

// Function to calculate the hash value of a string
int calculateHash(const string &str, int prime, int m) {
    int hash = 0;
    for (int i = 0; i < str.length(); i++) {
        hash = (hash * prime + str[i]) % m;
    }
    return hash;
}

// Rabin-Karp algorithm
void rabinKarpSearch(const string &text, const string &pattern, int prime = 31, int m = 1e9 + 7) {
    int n = text.length();
    int m_len = pattern.length();

    // Base case: if the pattern is longer than the text
    if (m_len > n) {
        cout << "Pattern not found!" << endl;
        return;
    }

    // Calculate the hash for the pattern and the initial substring of the text
    int patternHash = calculateHash(pattern, prime, m);
    int currentHash = calculateHash(text.substr(0, m_len), prime, m);

    int highestPower = 1; // Highest power of prime for hash recalculations
    for (int i = 1; i < m_len; i++) {
        highestPower = (highestPower * prime) % m;
    }

    // Slide through the text
    for (int i = 0; i <= n - m_len; i++) {
        // Check if the current hash matches the pattern's hash
        if (currentHash == patternHash) {
            // Check character by character to avoid hash collisions
            if (text.substr(i, m_len) == pattern) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate the hash for the next substring
        if (i < n - m_len) {
            currentHash = (currentHash - text[i] * highestPower) % m;
            currentHash = (currentHash * prime + text[i + m_len]) % m;

            // Handle negative hash values
            if (currentHash < 0) {
                currentHash += m;
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

    rabinKarpSearch(text, pattern);

    return 0;
}
