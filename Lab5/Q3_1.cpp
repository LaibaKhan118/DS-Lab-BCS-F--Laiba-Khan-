#include <iostream>
using namespace std;
int sumtail(int n, int total) {
    if (n <= 0) return total;
    return sumtail(n - 1, total + n);
}
int main() {
    int n;
    cin >> n;
    cout << sumtail(n, 0) << endl;
    return 0;
}
