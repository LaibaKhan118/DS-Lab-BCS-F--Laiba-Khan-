/*Implement a stack using linked lists. Demonstrate its use with a real-life example (e.g., browser
history navigation).*/

#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string data;
    Node* link;
    Node(string v) {
        data = v;
        link = nullptr;
    }
};

class Stack {
    Node* top;
public:
Stack():top(nullptr){}
~Stack() {
    while(!isEmpty()) {
        Node* temp=top;
        top=top->link;
        delete temp;
    }
}
bool isEmpty() {
    return top==nullptr;
}

void push(string x) {
    Node* n = new Node(x);
    if(!n) {
        cout << "Heap is full!" << endl;
        return;
    }
    n->link = top;
    top = n; 
    cout << "visited: " << top->data << endl;;
}
void pop() {
    if(isEmpty()) {
        cout << "No Current page!" << endl;
        return;
    }
    cout << "Going back from " << top->data;
    Node* temp =top;
    top = top->link;
    if (top != nullptr)
        cout << " to " << top->data << endl;
    else
        cout << " (no previous page)" << endl;

    delete temp;
}
string peek() {
    if(isEmpty())  {
        cout << "No Current page!" << endl;
        return "-";
    }
    return top->data;
}
void display() {
    if(isEmpty())  {
        cout << "No History!" << endl;
        return;
    }
    Node* temp = top;
    cout<<"History (most recent first):" << endl;
    while(temp!=nullptr) {
        cout << temp->data << endl;
        temp = temp->link;
    }
}
};

int main()
{
    Stack BrowserHistory;
    BrowserHistory.push("www.google.com");
    BrowserHistory.push("www.facebook.com");
    BrowserHistory.push("www.wikipedia.com");

    cout << "\nCurrently on:\n" << BrowserHistory.peek() << endl << endl;
    BrowserHistory.display();
    
    cout << "\nGoing back: " << endl;
    BrowserHistory.pop();

    cout << "\nCurrently on:\n" << BrowserHistory.peek() << endl;
    return 0;
}
