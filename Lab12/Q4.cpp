#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildLPS(const string &pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMPsearch(const string &text, const string &pattern, vector<int> &lpsOut) {
    int n = text.size();
    int m = pattern.size();
    vector<int> result;
    if (m == 0 || n == 0 || m > n) return result;
    lpsOut = buildLPS(pattern);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            result.push_back(i - j);
            j = lpsOut[j - 1];
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lpsOut[j - 1];
            else
                i++;
        }
    }
    return result;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);
    vector<int> lps;
    vector<int> matches = KMPsearch(text, pattern, lps);
    cout << "Pattern found at positions: [";
    for (size_t i = 0; i < matches.size(); i++) {
        cout << matches[i];
        if (i + 1 < matches.size()) cout << ", ";
    }
    cout << "]\n";
    cout << "LPS Array: [";
    for (size_t i = 0; i < lps.size(); i++) {
        cout << lps[i];
        if (i + 1 < lps.size()) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
