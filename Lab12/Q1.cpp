#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct searchResult {
    vector<int> positions;
    int comparisons;
};

searchResult patternMatching(const string& text, const string& pattern) {
    searchResult result;
    result.comparisons=0;
    int n=text.size();
    int m=pattern.size();
    if(n==0||m==0||m>n) { return result; }
    for (int i = 0;i<n-m;i++){
        int j=0;
        while(j<m){
            result.comparisons++;
            if(text[i+j]!=pattern[j]){
                break;
            }
            j++;
        }
        if(j==m){
            result.positions.push_back(i);
        }
    }
    return result;
}

int main()
{
    string text, pattern;
    cout <<"Enter the Text: ";
    getline(cin, text);
    cout <<"Enter the Pattern: ";
    getline(cin, pattern);
    searchResult result = patternMatching(text, pattern);
    cout<<"Positions: [";
    for(int i=0; i<result.positions.size(); i++) {
        cout<<result.positions[i];
        if(i+1<result.positions.size()) { cout<<", "; }
    }
    cout<<"]"<<endl;
    cout <<"Comparisons: "<< result.comparisons << endl;
    return 0;
}
