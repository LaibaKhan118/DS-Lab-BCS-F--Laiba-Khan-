#include <iostream>
using namespace std;
int main(){    
    int departments;
    cout << "Enter the number of departments: ";
    cin >> departments;
    double **salary = new double *[departments];
    int *employees = new int[departments];
    for (int i = 0; i < departments; i++){
        cout << "Enter the number of employees in department " << i + 1 << ": ";
        cin >> employees[i];
        salary[i] = new double[employees[i]];
    }
    for (int i = 0; i < departments; i++){
        cout << "Department " << i + 1 << ": " << endl;
        for (int j = 0; j < employees[i]; j++){
            cout << "Enter the salary of employee " << i + 1 << ": ";
            cin >> salary[i][j];
        }
        cout << endl;
    }
    cout << endl;
    double *average = new double[departments];
    cout << "The highest salaries in each department: " << endl;
    for (int i = 0; i < departments; i++){
        cout << "Department " << i + 1 << ": ";
        double maxSal = 0;
        double sum = 0;
        for (int j = 0; j < employees[i]; j++){
            if (salary[i][j] > maxSal){ maxSal = salary[i][j]; }
            sum += salary[i][j];
        }
        average[i] = sum / employees[i];
        cout << maxSal;
        cout << endl;
    }
    int best = 0;
    for (int i = 1; i < departments; i++){
        if (average[i] > average[best]){
            best = i;
        }
    }
    cout << "Department " << best + 1 << " has the best average of " << average[best] << "." << endl;
    for (int i = 0; i < departments; i++){
        delete[] salary[i];
    }
    delete[] employees;
    delete[] salary;
    delete[] average;
}
