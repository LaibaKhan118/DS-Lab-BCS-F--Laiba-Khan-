#include <iostream>
using namespace std;

// =============== Linear Search
//------ Iteratively
int linearSearchIterative(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i; // Found
    }
    return -1; // Not found
}

//------ Recursively
int linearSearchRecursive(int arr[], int n, int key, int index = 0)
{
    if (index >= n)
        return -1; // Not found
    if (arr[index] == key)
        return index;
    return linearSearchRecursive(arr, n, key, index + 1);
}


// =============== Binary Search
//------ Iteratively
int binarySearchIterative(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

//------ Recursively
int binarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

// =============== Inerpolation Search
//------ Iteratively
int interpolationSearchIterative(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == key)
                return low;
            return -1;
        }
        int pos = low + ((double)(key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key)
            return pos;
        else if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

//------ Recursively
int interpolationSearchRecursive(int arr[], int low, int high, int key)
{
    if (low > high || key < arr[low] || key > arr[high])
        return -1;

    if (low == high)
    {
        if (arr[low] == key)
            return low;
        return -1;
    }

    int pos = low + ((double)(key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

    if (arr[pos] == key)
        return pos;
    else if (arr[pos] < key)
        return interpolationSearchRecursive(arr, pos + 1, high, key);
    else
        return interpolationSearchRecursive(arr, low, pos - 1, key);
}

