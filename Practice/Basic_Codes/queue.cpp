#include <iostream>
#include <vector>
using namespace std;

//=============== Linear Queue
//---------- Using Arrays
class ALQueue
{
private:
    int *arr;
    int front;
    int rear;
    int cap;

public:
    ALQueue(int c) : front(-1), rear(-1), cap(c)
    {
        arr = new int[cap];
    }
    ~ALQueue()
    {
        delete[] arr;
    }

    bool isEmpty() { return front == -1 || front > rear; }

    bool isFull() { return rear == cap - 1; }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
            front = 0;

        rear++;
        arr[rear] = val;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        front++;
        if (isEmpty())
            front = rear = -1;

        return ans;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue:  ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

//---------- Using Vectors
class VLQueue
{
private:
    vector<int> data;
    int front;
    int rear;
    int capacity;

public:
    VLQueue(int size)
    {
        capacity = size;
        data.resize(capacity);
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front > rear);
    }

    bool isFull()
    {
        return (rear == capacity - 1);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        rear++;
        data[rear] = value;
        cout << value << " enqueued." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        cout << data[front] << " dequeued." << endl;
        front++;
    }

    int frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

//---------- Using LinkedList
class LLNode
{
public:
    int data;
    LLNode *next;

    LLNode(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LLQueue
{
private:
    LLNode *front;
    LLNode *rear;
    int size;

public:
    LLQueue() : size(0)
    {
        front = rear = nullptr;
    }

    ~LLQueue()
    {
        if (!isEmpty())
        {
            LLNode *temp = front;
            do
            {
                LLNode *del = temp;
                temp = temp->next;
                delete del;
            } while (!temp);
        }
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(int value)
    {
        LLNode *n = new LLNode(value);
        if (isEmpty())
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
        size++;
        cout << value << " enqueued." << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        LLNode *temp = front;
        int value = temp->data;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
        size--;
        cout << value << " dequeued." << endl;
        return value;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }
    int getSize() { return size; }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        LLNode *temp = front;
        cout << "Queue elements: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (!temp);
        cout << endl;
    }
};

//=============== Circular Queue
//---------- Using Arrays
class ACQueue
{
private:
    int *arr;
    int front;
    int rear;
    int s;
    int cap;

public:
    ACQueue(int c) : front(-1), rear(-1), cap(c), s(0)
    {
        arr = new int[cap];
    }
    ~ACQueue()
    {
        delete[] arr;
    }

    bool isEmpty() { return front == -1 || rear == -1; }

    bool isFull() { return ((rear + 1) % cap == front); }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % cap;

        arr[rear] = val;
        s++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int val = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % cap;
        s--;
        return val;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        cout << "Queue:  ";
        for (int k = 0; k < s; k++)
        {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        }
        cout << endl;
    }
};

//---------- Using Vectors
class VCQueue {
    vector<int> arr;
    int front, rear, size, capacity;

public:
    VCQueue(int cap) {
        capacity = cap;
        arr.resize(capacity);
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;

        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to dequeue.\n";
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        front = (front + 1) % capacity;
        size--;

        if (size == 0) {
            front = rear = -1;
        }
    }

    int peekFront() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

//---------- Using LinkedList
class CLNode
{
public:
    int data;
    CLNode *next;

    CLNode(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CLQueue
{
private:
    CLNode *front;
    CLNode *rear;

public:
    CLQueue()
    {
        front = rear = nullptr;
    }

    ~CLQueue()
    {
        if (!isEmpty())
        {
            CLNode *temp = front;
            do
            {
                CLNode *del = temp;
                temp = temp->next;
                delete del;
            } while (temp != front);
        }
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(int value)
    {
        CLNode *n = new CLNode(value);
        if (!n)
        {
            cout << "Heap Overflow!" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = n;
            rear->next = front;
        }
        else
        {
            rear->next = n;
            rear = n;
            rear->next = front;
        }

        cout << value << " enqueued." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return;
        }

        int value;
        if (front == rear)
        {
            value = front->data;
            delete front;
            front = rear = nullptr;
        }
        else
        {
            CLNode *temp = front;
            value = temp->data;
            front = front->next;
            rear->next = front;
            delete temp;
        }

        cout << value << " dequeued." << endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        CLNode *temp = front;
        cout << "Queue elements: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};
