#include <iostream>
using namespace std;
const int N = 9;

bool solver(int grid[N][N]);
bool validate(int grid[N][N], int row, int col, int dig);
bool emptyCell(int grid[N][N], int &row, int &col);
void print(int grid[N][N]);

int main()
{
     int grid[N][N] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };
    cout << "Sudoko to solve:" << endl;
    print(grid);
    cout << endl << endl;
    if(solver(grid)) {
        cout << "Solved Sudoku:" << endl;
        print(grid);
    }
    else cout << "Sudoku is unsolvable" << endl;
    return 0;
}

void print(int grid[N][N]){
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { cout<<grid[i][j]<<" "; }
        cout << endl;
        }
}

bool validate(int grid[N][N], int row, int col, int dig){
    for(int i=0; i<N; i++){
        if(grid[row][i] == dig) return false;
    }
    
    for(int i=0; i<N; i++){
        if(grid[i][col] == dig) return false;
    }

    int r = row-row%3;
    int c = col-col%3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) { 
            if(grid[i+r][j+c] == dig) return false; 
        }
    }

    return true;
}

bool emptyCell(int grid[N][N], int &row, int &col){
   for(row=0; row<N; row++) {
        for(col=0; col<N; col++) { 
            if(grid[row][col] == 0) return true; 
        }
    } 
    return false;
}

bool solver(int grid[N][N]){
    int row, col;
    if(!emptyCell(grid, row, col)) return true;

    for(int dig=1; dig<=9; ++dig) {
        if(validate(grid, row, col, dig)) {
            grid[row][col] = dig;
            if(solver(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}
