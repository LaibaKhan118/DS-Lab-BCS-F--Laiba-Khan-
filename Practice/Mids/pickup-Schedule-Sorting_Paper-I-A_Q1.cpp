#include <iostream>
using namespace std;

struct Customer{
    string name;
    int day;
    int month;
    int hanger;
};

bool Compare(Customer &a, Customer &b) {
    if(a.month != b.month) return (a.month < b.month);
    else if(a.day != b.day) return (a.day < b.day);
    else return a.name.length() > b.name.length();
}

void insertionSort(Customer *arr, int n) {
    for(int i = 1; i < n; i++) {
        Customer key = arr[i];
        int j = i-1;
        while(j>=0 && Compare(key, arr[j])){
            arr[j+1] = arr[j];
            j--;
        } 
        arr[j+1] = key;
    }
}

void assignHanger(Customer *arr, int n) {
    for(int i=0; i<n; i++) {
        arr[i].hanger = i+1;
    }
}

int searchByName(Customer *arr, int n, string target, int l, int h) {
    if (l>h) {
        return -1;
    }
    int mid = l+(h-l)/2;
    if(arr[mid].name == target) return arr[mid].hanger;
    else if(arr[mid].name > target) return searchByName(arr, n, target, l, mid-1);
    else return searchByName(arr, n, target, mid+1, h);
}

int main()
{
    int n;
    cout<<"Enter the number of cutomers: ";
    cin >> n;
    Customer *arr = new Customer[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Customer " << i+1 << ":" << endl;
        cout<<"  Enter Name: ";
        cin >> arr[i].name;
        cout<<"  Enter Day: ";
        cin >> arr[i].day;
        cout<<"  Enter Month: ";
        cin >> arr[i].month;
    }
    
    insertionSort(arr, n);
    assignHanger(arr, n);
    
    cout<<"\nSorted Cutomers: \nHanger No. - Name - (day/month)" << endl<<endl;
    for(int i=0; i<n; i++) {
        cout << arr[i].hanger << "- " << arr[i].name << " - (" << arr[i].day << "/" << arr[i].month << ")" << endl;
    }

    cout << endl;
    string target;
    cout << "Enter a name to search the hanger number: ";
    cin >> target;
    int hangerNo = searchByName(arr, n, target, 0, n-1);
    if(hangerNo == -1) {
        cout << "No record Found!" << endl;
    } 
    else {
        cout << "The Hanger Number for " << target << " is " << hangerNo << endl;
    }

    delete[] arr;
    return 0;
}
