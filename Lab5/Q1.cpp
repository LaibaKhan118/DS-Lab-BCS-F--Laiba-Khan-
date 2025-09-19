#include <iostream>
using namespace std; 
int calculateFactorial(int n){
    if(n==0||n==1){
      return 1;
    }
    else{ return n*calculateFactorial(n-1); }
}
int main() {
  int n;
  cout<< "Enter the number for factorial calculation: ";
  cin>>n;
  int result;
  result = calculateFactorial(n);
  cout<<"Factorial of "<<n<<" is "<<result<<endl;
  return 0;
}
