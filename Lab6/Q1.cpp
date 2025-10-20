/*
Task 1: Implement a stack using arrays. Support the following operations:
1. Push an element
2. Pop an element
3. Peek (top element)
4. Display stack contents
*/

#include <iostream>
using namespace std;
#define MAX 50

class Stack {
private:
    int top;
public:
    int a[MAX];

    Stack() {top = -1;}
    void push(int x) { //if we're printing a message, no need for boolean return
        if(top >= (MAX-1)){
            cout << "OverFlow" << endl;
            return;
        }
        a[++top] = x;
    }
    int pop() {
        if(top < 0){ 
            cout << "UnderFlow" << endl;
            return 0; 
        }
        return a[top--];
    }
    int peek() {
        if(top<0) {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return a[top];
    }
    bool isEmpty() {
        return (top<0);
    }
};

void display(Stack* s){
    if(s->isEmpty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << "Elements of Stack from top to bottom:" << endl;
    Stack temp;
    while(!s->isEmpty()) {
        int x = s->peek();
        cout << x << " ";
        temp.push(x);
        s->pop();
    }
    while(!temp.isEmpty()) {
        int x = temp.peek();
        s->push(x);
        temp.pop();
    }
}


int main()
{
    Stack s;
    s.push(20);
    s.push(200);
    s.push(2000);
    s.push(20000);

    display(&s);
    return 0;
}
