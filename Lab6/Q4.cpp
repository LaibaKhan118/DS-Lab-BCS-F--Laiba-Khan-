/*Implement a circular queue using arrays. Handle the following conditions correctly:
1. Enqueue when rear wraps around
2. Dequeue when front moves ahead
3. Prevent overflow when queue is full*/

#include <iostream>
using namespace std;

class CQueue {
    private:
    int front;
    int rear;
    int size;
    int cap;
    public:
    CQueue(int maxSize) {
        cap = maxSize;
        size = 0;
        front = -1;
        rear = -1;
    }
    
    int *a = new int[cap];
    bool isEmpty() {
        return (front==-1 && rear==-1);
    }
    bool isFull() {
        return ((rear+1)%cap == front);
    }
    void enqueue(int x) {
        if(isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        else if(isEmpty()) { front=rear=0; }
        else { rear = (rear+1)%cap; }
        a[rear] = x;
        size++;
    }
    int dequeue() {
        int x = 0;
        if(isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return x;
        }
        else if(front == rear) {
            x = a[front];
            front = rear= -1;
        }
        else {
            x = a[front];
            front = (front+1)%cap;
        } 
        size--;
        return x; 
    }
    void display() {
        if(isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        int i = front;
        for(int k=0; k<size; k++) {
            cout << a[i] << " ";
            i = (i+1)%cap;
        }
    }

    ~CQueue() {
        delete[] a;
    }
};

int main()
{
    CQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    cout << "\nDequeuing an element: " << endl;
    cout << "Removed " << q.dequeue() << endl;
    cout << "Updated Queue: " << endl;
    q.display();
    cout << "\nEnqueuing an element:" << endl;
    q.enqueue(5);
    cout << "Updated Queue: " << endl;
    q.display();
    return 0;
}
