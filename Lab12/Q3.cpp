#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> badChar(const string &pattern)
{
    const int ALPHABET =256;
    vector<int> bad_char(ALPHABET, -1);

    for (int i=0; i<(int)pattern.size(); i++)
        bad_char[(unsigned char)pattern[i]] = i;

    return bad_char;
}

vector<int> suffixTable(const string &pattern)
{
    int m =pattern.size();
    vector<int> suffix(m, -1);
    suffix[m-1]=m;

    int g = m-1, f=0;

    for (int i=m-2; i>=0; i--)
    {
        if (i>g && suffix[i+m-1-f] < i-g)
        {
            suffix[i]=suffix[i+m-1-f];
        }
        else
        {
            g =min(g, i);
            f =i;
            while (g>=0 && pattern[g]==pattern[g+m-1-f])
                g--;
            suffix[i] = f-g;
        }
    }
    return suffix;
}

vector<int> buildGoodSuffix(const string &pattern)
{
    int m =pattern.size();
    vector<int> suffix =suffixTable(pattern);
    vector<int> goodSuffix(m, m);

    for (int i = m-1; i>=0; i--)
    {
        if (suffix[i] == i+1)
        {
            for (int j=0; j < m-1-i; j++)
            {
                if (goodSuffix[j] == m)
                    goodSuffix[j] = m-1-i;
            }
        }
    }
    for (int i=0; i <= m-2; i++)
        goodSuffix[m-1-suffix[i]] =m-1-i;
    return goodSuffix;
}

vector<int> boyerMooreSearch(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> results;
    if (m==0 || n==0 || m>n)
        return results;
    vector<int> bad_char = badChar(pattern);
    vector<int> goodSuffix = buildGoodSuffix(pattern);
    int shift = 0;
    while (shift <= n-m)
    {
        int j = m-1;
        while (j>=0 && pattern[j]==text[shift+j])
            j--;

        if (j<0){
            results.push_back(shift);
            shift += goodSuffix[0];
        }
        else{
            int bcShift = j-bad_char[(unsigned char)text[shift+j]];
            int gsShift = goodSuffix[j];
            shift += max(1, max(bcShift, gsShift));
        }
    }
    return results;
}
int main()
{
    string dna, pattern;
    cout << "Enter DNA sequence: ";
    getline(cin, dna);
    cout << "Enter pattern: ";
    getline(cin, pattern);
    vector<int> result = boyerMooreSearch(dna, pattern);
    cout << "Pattern found at positions: [";
    for (int i=0; i<result.size(); i++)
    {
        cout << result[i];
        if (i+1 < result.size())
            cout << ", ";
    }
    cout << "]"<<endl;
    return 0;
}
