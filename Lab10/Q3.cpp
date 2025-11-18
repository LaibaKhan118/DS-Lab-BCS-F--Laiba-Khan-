#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int kthLargestHeap(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num:arr)
    {
        minHeap.push(num);
        if(minHeap.size()>k)
        {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main()
{
    vector<int> arr1={1, 23, 12, 9, 30, 2, 50};
    int k1= 3;

    vector<int> arr2 ={12, 3, 5, 7, 19};
    int k2=2;

    cout<< "Test 1 - Array: [1, 23, 12, 9, 30, 2, 50], K = 3"<<endl;
    cout<< "The 3rd Largest element: " << kthLargestHeap(arr1, k1)<<endl;

    cout <<"\nTest 2 - Array: [12, 3, 5, 7, 19], K = 2"<< endl;
    cout<<"The 2nd Largest element: " << kthLargestHeap(arr2, k2)<<endl;

    return 0;
}
