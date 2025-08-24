/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records, complete with a shallow copy implementation?
Define attributes such as student name, exam date, and score within the class,
and include methods to set these attributes and display exam details.
As part of this exercise, intentionally omit the implementation of the copy constructor and copy assignment operator.
Afterward, create an instance of the "Exam" class, generate a shallow copy, and observe any resulting issues?*/

#include <iostream>
#include <cstring>
using namespace std;

class Exam{
private:
    char *name;
    char *date;
    float score; 
public:
    Exam(const char *n, const char *d, float s){
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        date = new char[strlen(d) + 1];
        strcpy(date, d);

        score = s;
    }

    ~Exam(){
        delete[] name;
        delete[] date;
    }

    void setName(const char *n){
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    void setDate(const char *d){
        delete[] date;
        date = new char[strlen(d) + 1];
        strcpy(date, d);
    }
    void setScore(float s) { score = s; }

    void display() const{
        cout << "Student: " << name << endl << "  Date: " << date << endl << "  Score: " << score << endl;
    }
};

int main(){
    Exam e1("Laiba", "23-08-25", 70);
    e1.display();
    cout << endl;
    Exam e2 = e1;
    e2.display();

    cout << "Changed e2's name...\n";
    e2.setName("Faiza");

    cout << "\ne1:" << endl;
    e1.display();
    cout << "\ne2:" << endl;
    e2.display();

    cout << "Due to shallow copy, the pointer copied the address instead of the value.\nSo, when we changed the value of a member of the second object, it changed the value that was supposed to be the first object's." << endl;
    return 0;
}
