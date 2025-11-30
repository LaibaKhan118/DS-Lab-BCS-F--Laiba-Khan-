#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> patternMatching(const string &text, const string &pattern, vector<int>& collisionIndices) {
    const int base =256;
    const int mod =10;
    int n =text.size();
    int m =pattern.size();
    vector<int> matches;
    if (m ==0||n ==0||m> n)
        return matches;
    int h =1;
    for (int i=0; i<m-1; i++)
        h=(h*base)%mod;
    int pHash =0;
    int tHash =0;
    for (int i=0; i<m; i++) {
        pHash =(base*pHash+pattern[i])%mod;
        tHash =(base*tHash+text[i])%mod;
    }
    for (int i=0; i<=n-m; i++) {
        if (pHash ==tHash) {
            bool match=true;
            for (int j=0; j<m; j++) {
                if (text[i+j]!=pattern[j]) {
                    match =false;
                    collisionIndices.push_back(i);
                    break;
                }
            }
            if (match) {
                matches.push_back(i);
            }
        }
        if (i<n-m) {
            tHash=(base*(tHash-text[i]*h)+text[i+1+m-1])%mod;
            if (tHash<0)
                tHash+=mod;
        }
    }
    return matches;
}

int main()
{
    string text, pattern;
    cout <<"Enter the text: ";
    getline(cin, text);
    cout <<"Enter the pattern: ";
    getline(cin, pattern);
    vector<int>collisionIndices;
    vector<int>positions =patternMatching(text, pattern, collisionIndices);
    cout <<"\nPattern found at positions: [";
    for (int i=0; i<positions.size(); i++) {
        cout<<positions[i];
        if (i+1<positions.size()) cout << ", ";
    }
    cout << "]\n";
    if (!collisionIndices.empty()) {
        cout <<"\nFalse-positive hash matches (collisions detected): [";
        for (int i=0; i<collisionIndices.size(); i++) {
            cout<<collisionIndices[i];
            if (i+1<collisionIndices.size()) cout << ", ";
        }
        cout <<"]\n";
    } else {
        cout<<"\nNo hash collisions encountered.\n";
    }
    return 0;
}
