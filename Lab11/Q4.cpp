#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct pairVal {
    int first;
    int second;
};

void findPairs(vector<int>& arr) {
    unordered_map<int, pairVal> map;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int sum=arr[i]+arr[j];
            if(map.find(sum) != map.end()) {
                pairVal p = map[sum];
                if (p.first != arr[i] && p.first != arr[j] && p.second != arr[i] && p.second != arr[i]) {
                    cout << "(" << p.first << " + " << p.second << ") = (" << arr[i] << " + " << arr[j] << ")" << endl;
                    return;
                }
            }
            else {
                map[sum] = {arr[i], arr[j]};
            }
        }
    }
    cout << "No Pairs Found!" << endl;
};
int main()
{
    vector<int> arr1 = {3, 4, 7, 1, 2, 9, 8};
    vector<int> arr2 = {3, 4, 7, 1, 12, 9};
    vector<int> arr3 = {65, 30, 7, 90, 1, 9, 8};

    cout << "Test 1: ";
    findPairs(arr1);

    cout << "Test 2: ";
    findPairs(arr2);

    cout << "Test 3: ";
    findPairs(arr3);
    return 0;
}
