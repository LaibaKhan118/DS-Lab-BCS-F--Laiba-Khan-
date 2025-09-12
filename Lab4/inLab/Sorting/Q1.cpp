#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int *arr = new int[size]{};
    for(int i=0; i < size; i++) {
        cout << "Enter element: " << i+1 << ": ";
        cin >> arr[i];
    }
    
    for(int i = 0; i < size; i++) {
        for(int j= 0; j < size-i-1; j++) {
            if(arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    cout << "Sorted Array:" << endl;
    for(int i=0; i < size; i++) {
        cout << arr[i] << endl;
    }
    
    delete[] arr;
    return 0;
}
