#include <iostream>
using namespace std; 
void printnumber(int n){
    if(n<1){
      return;
    }
    else{ 
      cout<<n<<endl;
      printnumber(n-1); 
    }
}

int main() {
    int n;
    cout<<"Enter the number to print: ";
    cin>>n;
    printnumber(n);
    return 0;
}
