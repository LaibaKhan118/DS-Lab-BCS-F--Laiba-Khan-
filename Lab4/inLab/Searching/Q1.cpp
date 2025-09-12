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
    
    int num, index = -1;
    cout << "Enter number to find: ";
    cin >> num;
    
    for(int i = 0; i < size; i++) {
        if(num==arr[i]) {
            index = i;
            break;
        }
    }
    
    if (index >= 0) {
        cout << "Number is at index: " << index << endl;
    }
    else {
        cout << "number not found." << endl;
    }
    
    delete[] arr;
    return 0;
}
