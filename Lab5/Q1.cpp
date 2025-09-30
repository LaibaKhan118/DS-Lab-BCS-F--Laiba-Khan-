#include <iostream>
using namespace std;

int calculateFactorial(int n) {
    if(n==1||n==0){
        return 1;
    }
    return n*(calculateFactorial((n-1)));
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int result= calculateFactorial(n);
    cout <<"Fatorial: " <<result<<endl;
    return 0;
}
