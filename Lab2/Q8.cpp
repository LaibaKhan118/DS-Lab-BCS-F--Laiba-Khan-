#include <iostream>
using namespace std;
int main(){
    int n, m;
    cout << "Enter the number of days: ";
    cin >> n;
    cout << "Enter how many times do you want to take the temperature: ";
    cin >> m;
    float **temp = new float *[n];
    for (int i= 0; i< n; i++){
        temp[i] = new float[m];
    }
    float *average = new float[n];
    for (int i= 0; i< n; i++){
        cout << "Day: " << i + 1 << endl;
        float sum = 0;
        for (int j= 0; j< m; j++) {
            cout << "Enter Temp " << j + 1 << ": ";
            cin >> temp[i][j];
            sum += temp[i][j];
        }
        average[i] = sum / m;
        cout << "Average: " << average[i] << endl;
    }
    int hottest = 0;
    int coldest = 0;
    for (int i = 1; i < n; i++){
        if (average[i] > average[hottest]){
            hottest = i;
        }
        if (average[i] < average[coldest]){
            coldest = i;
        }
    }
    cout << "Hottest Day: " << hottest + 1 << endl;
    cout << "Coldest Day: " << coldest + 1 << endl;
    return 0;
}
