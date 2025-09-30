#include <iostream>
using namespace std;

// To make it obvious that nothing needs to be done after the recursive call I passed total by reference in sumTail
void sumTail(int n, int& total);
int sumNonTail(int n); 
int main(){
    int n=5, total=0;
    sumTail(n, total);
    cout<<"Total by Tail: "<<total<<endl;
    cout<<"Total by NonTail: "<<sumNonTail(n)<<endl;
    cout<<"\nIn Tail recursion, one call is not depended on the next call's return value, so the stack stays constant\nIn NonTail recursion, one call is depended on the next call's return value, making the stack store call after call untill the last call is reached (the base condition)."<<endl;
    return 0;
}

void sumTail(int n, int& total){
    if(n<=0) return;
    total+=n;
    sumTail(n-1, total);
}

int sumNonTail(int n) {
    if(n==0) return 0;
    return n+sumNonTail(n-1);
}
