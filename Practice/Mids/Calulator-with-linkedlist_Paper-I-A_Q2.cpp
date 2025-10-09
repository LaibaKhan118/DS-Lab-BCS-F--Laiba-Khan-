#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
    string data;
    Node* next;
    Node* pre;

    Node(string d) {
        data = d;
        next = nullptr;
        pre = nullptr;
    }
};

class LinkedList{
    private:
    Node* head;
    Node* tail;

    public:
    LinkedList() { head = tail = nullptr; }
    ~LinkedList() {
        Node* temp = head;
        while(temp) {
            Node* n = temp->next;
            delete temp;
            temp = n;
        }
        head = tail = nullptr;
    }
    void insert(string val) {
        Node* n = new Node(val);
        if(!head) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->pre = tail;
        tail = n;
    }
    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data;
            if(temp->next) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
    }

    double evaluate(Node* &current) {
        double value =0;
        string op = "add";

        while(current && current->data != ")"){
            string token = current->data;

            if(token=="(") {
                current = current->next;
                double subVal = evaluate(current);
                if(op=="add") value+=subVal;
                if(op=="minus") value-=subVal;
                if(op=="multiply") value*=subVal;
                if(op=="divide") value/=subVal;
            }
            else if (token == "add" || token == "minus" || token == "multiply" || token == "divide") {op = token;}
            else {
                double num = stod(token);
                if(op=="add") value+=num;
                if(op=="minus") value-=num;
                if(op=="multiply") value*=num;
                if(op=="divide") value/=num;
            }
            current = current->next;
        }
        return value;
    }

    Node* gethead() {
        return head;
    }
};

int main() {
    LinkedList expr;

    expr.insert("10");
    expr.insert("add");
    expr.insert("(");
    expr.insert("12");
    expr.insert("multiply");
    expr.insert("(");
    expr.insert("2");
    expr.insert(")");
    expr.insert("minus");
    expr.insert("2");
    expr.insert(")");

    cout << "Expression: ";
    expr.display();

    Node* start = expr.gethead();
    cout << "\nAnswer: " << expr.evaluate(start) << endl;
}