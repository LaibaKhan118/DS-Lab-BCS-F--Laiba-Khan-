/*Design a job scheduling system where:
1. Processes (with IDs & priorities) arrive and are stored in a queue.
2. Execution order is determined using a stack (LIFO execution of high-priority tasks).
3. Demonstrate how both queue (arrival order) and stack (execution handling) are
combined.*/

#include <iostream>
#include <vector>
using namespace std;

struct Job{
    int id;
    int priority; //the smaller the number the higher the priority

    Job(int i, int p): id(i), priority(p) {}
};

class QNode {
    public:
    Job process;
    QNode* next;

    QNode(const Job& p) : process(p), next(nullptr) {}
};

class Queue{
    private:
    QNode* front;
    QNode* rear;

    public:
    Queue(){ front = rear = nullptr; }
    ~Queue() {
        QNode* temp = front;
        while(temp) {
            QNode* del = temp;
            temp = temp->next;
            delete del;
        }
        front = rear = nullptr;
    }
    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(const Job& j) {
        QNode *n = new QNode(j);
        if(!n){
            cout << "Heap is Full" << endl;
            return;
        }
        if(!rear) { front = rear = n; }
        else {
            rear->next = n;
            rear = n;
        }
    }

    Job Dequeue() {
        if(!isEmpty()) {
        QNode* temp = front;
        Job p = front->process;
        front = front->next;
        if(!front) { rear = nullptr; }
        delete temp;
        return p;
        }
        else {
            throw runtime_error("Queue is empty!");
        }
    }

    void display() {
        QNode* temp = front;
        while(temp) {
            cout << "ID: " << temp->process.id << ", Priority: " << temp->process.priority << endl;
            temp=temp->next;
        }
    }
};

class Node{
public:
    Job data;
    Node* link;
    Node(const Job& v):data(v), link(nullptr) {}
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

void push(const Job& x) {
    Node* n = new Node(x);
    if(!n) {
        cout << "Heap is full!" << endl;
        return;
    }
    n->link = top;
    top = n; 
}
Job pop() {
    if(isEmpty()) {
        throw runtime_error("Stack is empty!");
    }
    Node* temp =top;
    Job p = top->data;
    top = top->link;
    delete temp;
    return p;
}
void display() {
        Node* temp = top;
        while(temp) {
            cout << "ID: " << temp->data.id << ", Priority: " << temp->data.priority << endl;
            temp=temp->link;
        }
    }
};

void scheduler(){
    Queue arrivalQueue;
    Stack executionStack;

    arrivalQueue.enqueue(Job(1, 5));
    arrivalQueue.enqueue(Job(2, 8));
    arrivalQueue.enqueue(Job(3, 3));
    arrivalQueue.enqueue(Job(4, 7));
    arrivalQueue.enqueue(Job(5, 2));

    cout << "Arrival Order: " << endl;
    arrivalQueue.display();
    cout << endl;

    vector<Job> sortedJobs;
    while(!arrivalQueue.isEmpty()) {
        sortedJobs.push_back(arrivalQueue.Dequeue());
    }
    for(int i=0; i<sortedJobs.size()-1; i++) {
        for(int j = i+1; j<sortedJobs.size(); j++) {
            if(sortedJobs[i].priority < sortedJobs[j].priority) {
                swap(sortedJobs[i], sortedJobs[j]);
            }
        }
    }
    for(auto& j : sortedJobs) {
        executionStack.push(j);
    }

    cout << "Execution Order: " << endl;
    executionStack.display();
    cout << endl;
}

int main()
{
    scheduler();
    return 0;
}
