#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "\nGiven Array: " << endl;
    for(auto elem:arr) {
        cout << elem << endl;
    }
    
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    map<int, int> rankMap;
    int rank = 0;
    for (int i = 0; i < n; i++)
    {
        if(rankMap.find(sorted[i]) == rankMap.end()) {
            rankMap[sorted[i]] = rank++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = rankMap[arr[i]];
    }
    
    cout<< "\nRanks:" << endl;
    for(auto elem:arr) {
        cout << elem << endl;
    }

    return 0;
}