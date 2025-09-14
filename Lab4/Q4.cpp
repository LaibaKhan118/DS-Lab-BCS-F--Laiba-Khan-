#include <iostream>
using namespace std;

void insertion_sort(int* arr, int n) {
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int binary_search(int* arr, int target, int l, int r) {
    int mid = l + (r-l)/2;
    if(l>r) return -1;

    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) { return binary_search(arr, target, mid+1, r); }
    else {return binary_search(arr, target, l, mid-1); }
}

int main()
{
    int n;
    cout << "Size: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout <<"Enter element " << i << ": ";
        cin >> arr[i];
    }
    
    insertion_sort(arr, n);
    cout << "\nSorted Array:" << endl;
    for(int i = 0 ; i < n; i++) {
        cout << arr[i] << " ";
    }
    int target;
    cout << "\nEnter a number to find: ";
    cin >> target;

    int found = binary_search(arr, target, 0, n);
    if(found >= 0) cout << "Target found at index: " << found << endl;
    else cout << "Target not found" << endl;
    delete[] arr;
    return 0;
}
