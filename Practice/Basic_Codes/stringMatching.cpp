#include <iostream>
#include <vector>
#include <string>
using namespace std;

void naiveSearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        if (j == m) cout << "Found at index: " << i << "\n";
    }
}

void rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int d = 256;
    int q = 101;
    int h = 1;
    int p = 0, t = 0;

    for (int i = 0; i < m - 1; i++) h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j = 0;
            while (j < m && pattern[j] == text[i + j]) j++;
            if (j == m) cout << "Found at index: " << i << "\n";
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + 1]) % q;
            if (t < 0) t += q;
        }
    }
}

void badCharTable(string pattern, vector<int>& badChar) {
    for (int i = 0; i < 256; i++) badChar[i] = -1;
    for (int i = 0; i < pattern.size(); i++)
        badChar[(unsigned char)pattern[i]] = i;
}

void boyerMoore(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> badChar(256);
    badCharTable(pattern, badChar);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) j--;

        if (j < 0) {
            cout << "Found at index: " << s << "\n";
            s += (s + m < n) ? m - badChar[(unsigned char)text[s + m]] : 1;
        } else {
            s += max(1, j - badChar[(unsigned char)text[s + j]]);
        }
    }
}

void computeLPS(string pattern, int m, vector<int>& lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
}

void kmpSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m);
    computeLPS(pattern, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) { i++; j++; }
        if (j == m) {
            cout << "Found at index: " << i - j << "\n";
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main()
{
    
    return 0;
}