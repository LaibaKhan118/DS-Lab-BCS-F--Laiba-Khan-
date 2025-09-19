#include <iostream>
using namespace std;
int sumnontail(int n) {
    if (n <= 0) return 0;
    return n + sumnontail(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << sumnontail(n) << endl;
    return 0;
}
