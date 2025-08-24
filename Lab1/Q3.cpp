/*Q3: Create a C++ class Box that uses dynamic memory allocation for an integer. 
Implement the Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/

#include <iostream>
using namespace std;

class Box{
private:
    int *a;
public:
    Box(){
        a = new int;
        *a = 0;
        cout << "Default Constructor Executed!" << endl;
    }
    Box(int s){
        a = new int;
        *a = s;
        cout << "Parameterized Constructor Executed!" << endl;
    }
    Box(const Box &b){
        a = new int;
        *a = *(b.a);
        cout << "Copy Constructor Executed!" << endl;
    }
    Box &operator=(const Box &b){
        if (this!=&b){
            delete a;
            a = new int;
            *a = *(b.a);
        }
        cout << "Assignment Operator Executed!" << endl;
        return *this;
    }
    ~Box(){
        delete a;
    }

    void setSide(int s) { *a = s; }
    int getSide() { return *a; }
};

int main(){
    cout << "Copy Constructor:" << endl;
    Box b1(100); 
    Box b2 = b1;
    b2.setSide(250);

    cout << "b1: " << b1.getSide() << endl;
    cout << "b2: " << b2.getSide() << endl;

    cout << "Since Deep copy works, when we change the value of b2, it didn't affect the value of b1. \n
      If it were a shallow copy, the pointers in b2 and b1 would have pointed to the same thing, and changing that value from any pointer would change it for boht objects." << endl;

    cout << endl << "Copy Assignment Operator:" << endl;
    Box b3;
    b3 = b1;
    b3.setSide(340);

    cout << "b1: " << b1.getSide() << endl;
    cout << "b3: " << b3.getSide() << endl;

    cout << "If there was no Copy Assignment Operator, then changing the value in b3 would have also reflected in b1 because the pointers in b1 and b3 point to the same thing" << endl;
}





