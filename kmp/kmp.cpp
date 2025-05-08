#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the next array
vector<int> computeNextArray(const string &pattern) {
    int m = pattern.size();
    vector<int> next(m, 0);
    int j = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        // 优化：如果当前字符和前缀字符相同，跳过重复比较
        if (i + 1 < m && pattern[i + 1] == pattern[j]) {
            next[i] = next[j - 1];
        } else {
            next[i] = j;
        }
    }

    return next;
}

// KMP algorithm for pattern matching
void KMP(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> next = computeNextArray(pattern);

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - m + 1 << endl;
            j = next[j - 1];
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    KMP(text, pattern);

    return 0;
}

