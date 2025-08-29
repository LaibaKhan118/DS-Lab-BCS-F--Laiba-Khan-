#include <iostream>
using namespace std;
int main(){
    int benches, seats;
    cout << "Enter the number of banches in each class: ";
    cin >> benches;
    cout << "Enter the number of seats on each bench: ";
    cin >> seats;
    int **seating = new int *[benches];
    for (int i = 0; i < benches; i++){
        seating[i] = new int[seats]{};
    }
    cout << "Enter the status of each seat (0 for no and 1 for yes):" << endl;
    for (int i = 0; i < benches; i++){
        for (int j = 0; j < seats; j++){
            cout << "Is seat " << j << " of row " << i << " occupied? ";
            cin >> seating[i][j];
        }
    }
    cout << endl << "The Seating Chart: " << endl;
    for (int i = 0; i < benches; i++){
        for (int j = 0; j < seats; j++){
            cout << seating[i][j] << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < benches; i++){
        delete[] seating[i];
    }
    delete[] seating;
    return 0;
}
