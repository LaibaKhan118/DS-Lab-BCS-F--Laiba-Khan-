#include <iostream>
using namespace std;
int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    int *arr = new int[size]{};
    int i;
    char c;
    while (true){
        cout << "Enter the index: ";
        cin >> i;
        if (i < 0 || i > size) {
            cout << "The index must be between 0 and " << size << endl;
            continue;
        }
        cout << "Enter the value: ";
        cin >> arr[i];
        cout << "do you want to enter another value (y/n)? ";
        cin >> c;
        if (c == 'N' || c == 'n'){
            break;
        }
    }
    cout << "The final Array: " << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }
    delete[] arr;
    return 0;
}
