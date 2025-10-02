/*Create a program that solves the N-Queens problem for any given N using backtracking. The
program should print all possible solutions for placing N queens on an N x N chessboard so
that no two queens threaten each other. This task requires you to use a recursive function to
place queens row by row , and a validation function to check if a queen can be placed in a
specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous
row and try a different column.*/

#include <iostream>
using namespace std;

void print(char** const grid, int N);
bool isSafe(char** const grid, int row, int col, int N);
void solution(char** grid, int row, int N);

int main()
{
    int N;
    cout << "Enter the Size: ";
    cin >> N;

    char** chessboard = new char*[N];
    for(int i=0; i<N; i++) {
        chessboard[i] = new char[N];  
        for(int j=0; j<N; j++) chessboard[i][j]='-';
    }
    print(chessboard, N);
    solution(chessboard, 0, N);

    return 0;
}

void print(char** const grid, int N) {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) cout << grid[i][j] << " ";
        cout << endl;
    } 
    cout << endl;
}
bool isSafe(char** const grid, int row, int col, int N){
    for(int i=0; i<row; i++){
        if(grid[i][col] == 'Q') return false;
    }
    for(int i=row, j=col; i>=0 && j>=0; --i,--j) {
        if(grid[i][j] == 'Q') return false;
    }
    for(int i=row, j=col; i>=0 && j<N; --i,++j) {
        if(grid[i][j] == 'Q') return false;
    }

    return true;
}
void solution(char** grid, int row, int N) {
    if(row == N) {
        print(grid, N);
    }
    else {
        for(int col=0; col<N; ++col) {
            if(isSafe(grid, row, col, N)) {
                grid[row][col]='Q';
                solution(grid, row+1, N);
                grid[row][col]='-';
            }
        }
    }
}

