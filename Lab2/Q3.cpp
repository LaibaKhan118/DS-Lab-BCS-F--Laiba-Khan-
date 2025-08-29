#include <iostream>
using namespace std;
int main(){
    int students;
    cout << "Enter the number of students: ";
    cin >> students;
    int **marks = new int *[students];
    int *courses = new int[students];
    for (int i = 0; i < students; i++){
        cout << "Enter the number of courses of student " << i << ": ";
        cin >> courses[i];
    }
    for (int i = 0; i < students; i++){
        marks[i] = new int[courses[i]];
    }
    for (int i = 0; i < students; i++){
        cout << "Student " << i << endl;
        for (int j = 0; j < courses[i]; j++){
            cout << "Enter the marks of course " << j << ": ";
            cin >> marks[i][j];
        }
    }
    int sum = 0;
    cout << "Average Marks: " << endl;
    for (int i = 0; i < students; i++){
        cout << "Student " << i << ": ";
        for (int j = 0; j < courses[i]; j++){
            sum += marks[i][j];
        }
        int avg = sum / courses[i];
        cout << avg << endl;
    }
    return 0;
}
