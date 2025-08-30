#include <iostream>
using namespace std;
class Matrix{
private:
    int row;
    int col;
    int **matrix;

public:
    Matrix(int r, int c){
        if(r < 1) { 
            cout << "Rows must be at least 1. Assigning 1 to the rows." << endl; 
            row = 1; }
        else {row = r;}
        if(c < 1) { 
            cout << "Columns must be at least 1. Assigning 1 to the rows." << endl; 
            col = 1; }
        else {col = c;}
        
        matrix = new int *[r];
        for (int i = 0; i < r; i++){
            matrix[i] = new int[c]{};
        }
    }
    void inputValues(){
        for (int i = 0; i < row; i++){
            cout << "Row: " << i + 1 << endl;
            for (int j = 0; j < col; j++){
                cout << "Enter the value of element " << j + 1 << ": ";
                cin >> matrix[i][j];
            }
            cout << endl;
        }
    }
    void printValues(){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        }
    }

    friend Matrix operator+(const Matrix &m1, const Matrix &m2);
    friend Matrix operator-(const Matrix &m1, const Matrix &m2);
    ~Matrix(){
        for (int i = 0; i < row; i++) {
            delete[] matrix[i];}
        delete[] matrix;
    }
};

int main()
{
    int r, c;
    cout << "Enter the no. of rows: ";
    cin >> r;
    cout << "Enter the no. columns: ";
    cin >> c;
    cout << "Matrix 1: " << endl;
    Matrix m1(r, c);
    cout << "\nEnter Values:" << endl;
    m1.inputValues();
    cout << "Matrix 2:" << endl;
    Matrix m2(r, c);
    cout << "Enter Values: " << endl;
    m2.inputValues();

    cout << "\nElements of M1:" << endl;
    m1.printValues();
    cout << "Elements of M1:" << endl;
    m2.printValues();

    cout << "Addition:" << endl;
    Matrix m3 = m1 + m2;
    m3.printValues();
    cout << "Subtraction:" << endl;
    Matrix m4 = m1 - m2;
    m4.printValues();

    return 0;
}

Matrix operator+(const Matrix &m1, const Matrix &m2){
    Matrix result(m1.row, m1.col);
    for (int i = 0; i < m1.row; i++){
        for (int j = 0; j < m1.col; j++){result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];}
    }
    return result;
}
Matrix operator-(const Matrix &m1, const Matrix &m2)
{
    Matrix result(m1.row, m1.col);
    for (int i = 0; i < m1.row; i++){
        for (int j = 0; j < m1.col; j++){
            result.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
        }
    }
    return result;
}
