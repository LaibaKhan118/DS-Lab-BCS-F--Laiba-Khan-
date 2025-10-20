/*Implement a linear queue using arrays with the following operations:
1. Enqueue
2. Dequeue
3. Display queue contents
4. Check if queue is empty/full*/

#include <iostream>
using namespace std;
#define MAX 50

class Queue {
    int front;
    int rear;

public:
    int a[MAX];
    Queue() {
        front = rear= -1;
    }
    bool isEmpty() {
        return (front < 0 || front  > rear);
    }
    bool isFull() {
        return rear == MAX-1;
    }
    void enqueue(int x) {
        if(isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if(front == -1) front =0;
        a[++rear] = x;
    }
    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return a[front++];
    }
    void display() {
        if(isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        int tempf = front;
        int tempr = rear;
        while(tempf <= rear) {
            cout << a[tempf++] << " ";
        }
    }
};



int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << "Queue Content:" << endl;
    q.display();
    cout << "\nDequeuing an element:" << endl;
    q.dequeue();
    q.display();
    cout << "\nEnqueuing an element:" << endl;
    q.enqueue(5);
    q.display();

    return 0;
}
