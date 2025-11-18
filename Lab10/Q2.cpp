#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i)+1; }
int right(int i) { return (2*i)+2; }

bool isBinaryMaxHeap(const vector<int> &arr)
{
    int n = arr.size();
    for (int i=0; i<= (n-2)/2; i++)
    {
        int leftChild = left(i);
        int rightChild = right(i);
        if (leftChild<n && arr[leftChild]>arr[i]){ return false; }
        if (rightChild < n && arr[rightChild] > arr[i]){ return false; }
    }
    return true;
}
bool isBinaryMinHeap(const vector<int> &arr)
{
    int n = arr.size();
    for (int i=0; i<= (n-2)/2; i++)
    {
        int leftChild =left(i);
        int rightChild =right(i);
        if (leftChild<n && arr[leftChild]<arr[i]){ return false; }
        if (rightChild<n && arr[rightChild]<arr[i]){ return false; }
    }
    return true;
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest=i;
    int  leftChild=left(i);
    int  rightChild=right(i);
    if ( leftChild<n && arr[ leftChild]>arr[largest])
    {
        largest=leftChild;
    }
    if ( rightChild<n && arr[rightChild]>arr[largest])
    {
        largest =rightChild;
    }
    if (largest!= i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n =arr.size();
    for (int i =n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i =n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(const vector<int> &arr)
{
    for (int num:arr)
    {
        cout<<num<<" ";
    }
    cout <<endl;
}
int main()
{
    vector<int> maxHeap ={8,7,6, 5, 4};
    cout <<"Array: ";
    printArray(maxHeap);
    cout<<"Is Max Heap: " <<(isBinaryMaxHeap(maxHeap)? "Yes":"No")<<endl;
    cout << "Is Min Heap: "<< (isBinaryMinHeap(maxHeap)?"Yes":"No")<<endl;

    heapSort(maxHeap);
    cout<< "Sorted array: ";
    printArray(maxHeap);
    cout<<endl;

    return 0;
}
