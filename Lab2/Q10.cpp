#include <iostream>
using namespace std;
int main(){
    int category;
    cout << "Enter the number of categories: ";
    cin >> category;
    int **id = new int *[category];
    int *books = new int[category];
    for (int i = 0; i < category; i++){
        cout << "Enter the number of books in category " << i + 1 << ": ";
        cin >> books[i];
        id[i] = new int[books[i]];
    }
    for (int i = 0; i < category; i++){
        cout << "Category " << i + 1 << ": " << endl;
        for (int j = 0; j < books[i]; j++){
            cout << "Enter the id of book " << i + 1 << ": ";
            cin >> id[i][j];
        }
        cout << endl;
    }

    bool flag = false;
    int find, cat;
    cout << "Enter the ID of the book you want to search: ";
    cin >> find;

    for (int i = 0; i < category; i++){
        for (int j = 0; j < books[i]; j++){
            if (id[i][j] == find){
                flag = true;
                cat = i;
                break;
            }
        }
        if (flag){
            break;
        }
    }
    if (flag){
        cout << "Book with ID " << find << " is Available in Category: " << cat + 1 << endl;
    }
    else {
        cout << "Not Found." << endl;
    }
    for (int i = 0; i < category; i++){
        delete[] id[i];
    }
    delete[] books;
    delete[] id;
}
