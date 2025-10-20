/*Write a program to convert an infix expression into postfix form using a stack. Also, evaluate the
postfix expression afterward.*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node* link;
    Node(T v) {
        data = v;
        link = nullptr;
    }
};

template <typename T>
class Stack {
    Node<T>* top;
public:
Stack():top(nullptr){}
~Stack() {
    while(!isEmpty()) {
        Node<T>* temp=top;
        top=top->link;
        delete temp;
    }
}
bool isEmpty() {
    return top==nullptr;
}

void push(T x) {
    Node<T>* n = new Node<T>(x);
    if(!n) {
        cout << "Heap is full!" << endl;
        return;
    }
    n->link = top;
    top = n; 
}
void pop() {
    if(isEmpty()) return;
    Node<T>* temp =top;
    top = top->link;
    delete temp;
}

T peek() {
    return top->data;
}
};



int precedence(char c) {
    if(c == '^') {
        return 3;
    }
    else if(c == '*' || c == '/') {
        return 2;
    }
    else if(c == '+' || c == '-') {
        return 1;
    }
    else return -1;
}

string toPostFix(const string& infix) {
    string postfix = ""; 
    Stack<char> s;

    for(char c: infix) {
        if((c >= 'A' && c <= 'Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) {
            postfix += c;
        }
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while(!s.isEmpty() && s.peek() != '(') {
                char op = s.peek();
                s.pop();
                postfix += op;
            }
            if (!s.isEmpty() && s.peek()=='(') { s.pop(); }
        }
        else {
            while(!s.isEmpty() && s.peek() != '(' && (precedence(c) < precedence(s.peek()) || (precedence(c) == precedence(s.peek()) && c=='^'))) {
                char op = s.peek();
                s.pop();
                postfix += op;
            }
            s.push(c);
        }
    }
    while(!s.isEmpty()) {
        char op = s.peek();
        s.pop();
        postfix += op;
    }
    return postfix;
}

int applyOp(int a, int b, char op) {
    switch (op)
    {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b; 
    case '/': return a/b; 
    case '^': return static_cast<int>(pow(a, b)); 
    default: return 0;
    }
}

int evaluate(const string& postfix) {
    Stack<int> s;

    for(char c: postfix) {
        if(c >= '0' && c <='9') { s.push(c - '0'); }
        else {
            int op2 = s.peek(); 
            s.pop();
            int op1 = s.peek(); 
            s.pop();
            int res = applyOp(op1, op2, c);
            s.push(res);
        }
    }
    return s.peek();
}

int main()
{
    string infix;
    cout << "Enter infix (single digit num for evaluation): ";
    cin >> infix;
    string postfix = toPostFix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluate(postfix) << endl;
    return 0;
}
