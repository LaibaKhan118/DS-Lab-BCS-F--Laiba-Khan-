#include <iostream>
using namespace std;
class safePointer{
protected:
    int *ptr;
public:
    safePointer(){
        ptr = new int(0);
    }
    void setValue(int p){
        if (!ptr){
            ptr = new int;
        }
        *ptr = p;
        cout << "initialized" << endl;
    }
    int getValue(){
        if (!ptr){
            cout << "No value was set. Setting it to zero." << endl;
            return 0;
        }
        return *ptr;
    }
    void release(){
        delete ptr;
        ptr = nullptr;
        cout << "released\n";
    }
    ~safePointer(){
        delete ptr;
    }
    safePointer(const safePointer &) = delete;
    safePointer &operator=(const safePointer &) = delete;
};

int main(){
    safePointer marks[5];
    marks[0].setValue(40);
    marks[1].setValue(60);
    marks[2].setValue(70);
    marks[3].setValue(85);
    marks[4].setValue(58);

    cout << "The Marks:" << endl;
    for (int i= 0; i< 5; i++){
        cout << marks[i].getValue() <<endl;
    }

    marks[3].release();
    cout<< marks[3].getValue() << endl;

    marks[3].setValue(44);
    cout << marks[3].getValue();
    return 0;
}
