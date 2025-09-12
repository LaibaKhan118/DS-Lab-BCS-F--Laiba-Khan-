#include <iostream>
using namespace std;
int main() {
    int CEO = 0;
    int CTO = 1;
    int CFO = 2;
    int VP = 3;
    int MGR = 4;
    int EMP = 5;
    
    int n = 8;
    int arr[n] = {EMP,CFO,MGR,EMP,VP,CTO,MGR,CEO};
    
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    cout << "Sorted Array:" << endl;
    for(int i=0; i < n; i++) {
        string val = (arr[i]==0) ? "CEO" : (arr[i]==1)? "CTO" : (arr[i]==2) ? "CFO" : (arr[i]==3) ? "VP" : (arr[i]==4) ? "MGR": "EMP";
        cout << val << endl;
    }
    
    return 0;
}
