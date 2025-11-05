#include <iostream>
#include <vector>
using namespace std;

//========== Using Arrays
class AStack
{
    int *arr;
    int capacity;
    int top;

public:
    AStack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }
    ~AStack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }
};

//========== Using Vectors
class VStack
{
    vector<int> arr;

public:
    void push(int x)
    {
        arr.push_back(x);
    }

    int pop()
    {
        if (arr.empty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = arr.back();
        arr.pop_back();
        return val;
    }

    int peek()
    {
        if (arr.empty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr.back();
    }

    bool isEmpty()
    {
        return arr.empty();
    }

    int size()
    {
        return arr.size();
    }
};

//========== Using LinkedList
class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};
class LStack
{
    Node *top;
    int count;

public:
    LStack() : top(nullptr), count(0) {}
    ~LStack()
    {
        while (!isEmpty())
        {
            Node *temp = top;
            top = top->next;
            delete top;
        }
        top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int x)
    {
        Node *n = new Node(x);
        n->next = top;
        top = n;
        count++;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node *temp = top;
        top = top->next;
        int val = temp->data;

        count--;
        delete temp;
        return val;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    int size() { return count; }
};
