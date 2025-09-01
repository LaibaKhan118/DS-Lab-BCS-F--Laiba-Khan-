#include <iostream>
using namespace std;
class Matrix{
private:
    int row;
    int col;
    int **matrix;
public:
    Matrix(int r, int c){
        row = r;
        col = c;
        matrix = new int *[r];
        for (int i= 0; i <r; i++){
            matrix[i] = new int[c]{};
        }
    }
    void inputValues(){
        for (int i = 0; i < row; i++){
            cout << "Row: " << i + 1 << endl;
            for (int j = 0; j < col; j++){
                cout << "Enter the value of element " << j + 1 << ": ";
                cin >> matrix[i][j];
            } cout << endl;
        }
    }
    void printValues(){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cout << matrix[i][j] << "  ";
            }cout << endl;
        }
    }

    void compressedMatrix(){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (matrix[i][j]){
                    cout << i << " " << j << " " << matrix[i][j] << endl;
                }
            }
        }
    }

    ~Matrix(){
        for (int i = 0; i < row; i++){
            delete[] matrix[i];
        } delete[] matrix;
    }
};

int main()
{
    int r, c;
    cout << "Enter the no. of rows: ";
    cin >> r;
    cout << "Enter the no. columns: ";
    cin >> c;
    Matrix m1(r, c);
    cout << "\nEnter Values:" << endl;
    m1.inputValues();

    cout << "\nElements of the sparse matrix:" << endl;
    m1.printValues();

    cout << "\nCompressed Form:" << endl;
    m1.compressedMatrix();

    return 0;
}
