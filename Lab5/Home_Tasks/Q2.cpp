#include <iostream>
using namespace std;

void printNumbers(int n);
void functionA(int n);
void functionB(int n);

int main(){
    int n = 5;
    cout << "Direct:" << endl;
    printNumbers(n);
    cout << "\nIndirect:" << endl;
    functionA(n);
    return 0;
}

void printNumbers(int n){
    if (n <= 0){
        return;
    }
    cout << n << endl;
    printNumbers(n - 1);
}

void functionA(int n){
    if(n<=0) return;
    cout <<n<<endl;
    functionB(n-1);
}
void functionB(int n) {
    if(n<=0) return;
    cout <<n<<endl;
    functionA(n-1);
}
