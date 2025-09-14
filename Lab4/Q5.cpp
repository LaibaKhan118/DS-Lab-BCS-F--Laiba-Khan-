/*Implement the Interpolation Search algorithm. The program should take a sorted array
with uniformly distributed values and a target value from the user. The algorithm should
estimate the position of the target and check if the estimated position holds the correct
value. If the element is found, print its index; otherwise, indicate that it's not present.*/
#include <iostream>
using namespace std;

int interpolation_search(int *arr, int x, int n) {
    int l = 0;
    int h = n-1;
    while(x>=arr[l] && x<=arr[h] && l<=h) {
        if(l == h) {
            if(arr[l] == x) return l;
            return -1;
        }

        int pos = l + (h-l) * (x-arr[l]) / (arr[h]-arr[l]);
        if(arr[pos] == x) {return pos;}
        else if(x > arr[pos]) {l = pos+1;}
        else {h=pos-1;}
    }
    return -1;
}

int main()
{
    int n;
    cout << "Size: ";
    cin >>n;
    int *arr = new int[n];
    for (int i =0; i <n; i++)
    {
        cout <<"Enter element "<< i << ": ";
        cin >> arr[i];
    }
    int target;
    cout << "\nEnter a number to find: ";
    cin >> target;

    int found = interpolation_search(arr, target, n);
    if(found != -1) {
        cout << "Target found at index: " << found << endl;
    }
    else {
        cout <<"Target Not Found" << endl;
    }
    return 0;
}
