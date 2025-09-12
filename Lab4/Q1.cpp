/*Q1: Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array.*/
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
    

    return 0;
}
