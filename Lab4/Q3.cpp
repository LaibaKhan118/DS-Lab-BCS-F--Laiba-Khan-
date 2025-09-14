/*Implement the Selection Sort algorithm. The program should take an array of integers from
the user, find the smallest element, and exchange it with the element at the first position.
This process should continue until the array is completely sorted. Display the sorted array
to the user.*/
#include <iostream>
using namespace std;

void selection_sort(int *arr, int n) {
    for(int i =0; i<n-1; i++) {
        int min = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "\nBefore sort:" << endl;
    print(arr, n);
    selection_sort(arr, n);
    cout << "\nAfter sort:" << endl;
    print(arr, n);
    
    delete[] arr;
    return 0;
}
