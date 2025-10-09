#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int n;
vector<vector<char>>mat;
set<string>palindromes;

bool isPalindrome(string& s) {
    int i = 0, j = s.size() -1;
    while(i < j) {
        if(s[i++] != s[j--]) return false;
    }
    return true;
}

void findPalindromes(int i, int j, string& current, vector<vector<bool>>visited) {
    if(i<0 || j <0 || i>=n || j>=n || visited[i][j] == true || current.size() > n) return;

    visited[i][j] = true;
    current += mat[i][j];
    if(current.size() == n && isPalindrome(current)) {
        palindromes.insert(current);
    }

    findPalindromes(i, j+1, current, visited);
    // findPalindromes(i+1, j, current, visited);
    // findPalindromes(i, j-1, current, visited);
    // findPalindromes(i-1, j, current, visited);
    // findPalindromes(i+1, j+1, current, visited);
    // findPalindromes(i+1, j-1, current, visited);
    // findPalindromes(i-1, j+1, current, visited);
    // findPalindromes(i-1, j-1, current, visited);

    // for (int x = -1; x <= 1; x++)
    // {
    //     for (int y = -1; y <= 1; y++)
    //     {
    //         if(x != 0 || y != 0) 
    //             findPalindromes(i+x, j+y, current, visited);
    //     }
        
    // }
    

    visited[i][j]=false;
    current.pop_back();
}

int main() {
    n=5;
    mat = {
        {'G', 'R', 'O', 'O', 'T'},
        {'B', 'A', 'R', 'R', 'O'},
        {'W', 'R', 'D', 'B', 'S'},
        {'R', 'A', 'D', 'A', 'R'},
        {'W', 'E', 'S', 'E', 'W'}
    };


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string current = "";
            vector<vector<bool>>visited(n, vector<bool>(n, false));
            findPalindromes(i, j, current, visited);
        }
    }

    if(palindromes.empty()) {
        cout << "No palindromes found!" << endl;
    }
    else {
        cout << "Palindromes found:" << endl;
        for(auto& p : palindromes) {
            cout << p << endl;
        }
    }
    return 0;
}