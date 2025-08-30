#include <iostream>
using namespace std;
class Tracker{
private:
    int size;
    int cap;
    double *expenses;
public:
    Tracker(int n){
        size = n;
        cap = n;
        expenses = new double[n]{};
    }
    ~Tracker(){
        delete[] expenses;
    }

    void inputExpenses(){
        for (int i= 0; i < size; i++){
            cout << "Enter the expenses for month: " << i + 1 << ": ";
            cin >> expenses[i];
        }
    }

    double calculateTotal(){
        double total = 0.0;
        for (int i =0; i< size; i++){
            total += expenses[i];
        }
        return total;
    }

  double calculateAverage() {
        double total = 0.0;
        for (int i = 0; i < size; i++){
            total += expenses[i];
        }
        return total / size;
    }

    void sizeDown(int newsize){
        size = newsize;
        double *newExpenses = new double[size];
        for (int i = 0; i < size; i++){
            newExpenses[i] = expenses[i];
        }
        delete[] expenses;
        expenses = newExpenses;
        cap = size;
    }

    void sizeUp(int newsize){
        size = newsize;
        double *newExpenses = new double[size];
        for (int i = 0; i < cap; i++){
            newExpenses[i] = expenses[i];
        }
        for (int i = cap; i < size; i++){
            cout << "Enter the expenses for month " << i + 1 << ": ";
            cin >> newExpenses[i];
        }
        delete[] expenses;
        expenses = newExpenses;
        cap = size;
    }

    void displayExpenses(){
        for (int i = 0; i < size; i++){
            cout << "Month " << i + 1 << ": " << expenses[i] << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of months: ";
    cin >> n;
    if (n < 1){
        cout << "The number must be greater than 0." << endl;
        return 1;
    }
    Tracker monthlyExpenses(n);
    cout << endl;

    monthlyExpenses.inputExpenses();
    cout << "Total Expenses: " << monthlyExpenses.calculateTotal() << endl;
    cout << "Average Expenses: " << monthlyExpenses.calculateAverage() << endl;

    char c;
    int m;
    while (true){
        cout << "\nWould you like to add or reduce months? (y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y'){
            cout << "Enter the new number of total months: ";
            cin >> m;
            if (m > n){
                monthlyExpenses.sizeUp(m);
            }
            else if (m < n && m > 0){
                monthlyExpenses.sizeDown(m);
            }
            else{
                cout << "The new value cannot be equal to the current value or less than 1!" << endl;
                continue;
            }
            cout << "Total Expenses: " << monthlyExpenses.calculateTotal() << endl;
            cout << "Average Expenses: " << monthlyExpenses.calculateAverage() << endl;
        }
        else{
            cout << "Thank You for using this tracker!" << endl;
            return 0;
        }
    }
    return 0;
}
