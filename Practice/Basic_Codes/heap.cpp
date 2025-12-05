#include <iostream>
#include <vector>
using namespace std;

#include <vector>

class MinHeap
{
    vector<int> heap;
    int capacity;
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyDown(int i)
    {
        int l = left(i), r = right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i)
    {
        while (i != 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    MinHeap(int cap)
    {
        capacity = cap;
        heap.resize(capacity);
    }
    void buildHeap(const vector<int> &arr)
    {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--)
        {
            heapifyDown(i);
        }
    }
    int peek()
    {
        return heap.empty() ? -1 : heap[0];
    }

    void insertKey(int key)
    {
        if (heap.empty())
        {
            return;
        }
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMin()
    {
        if (heap.empty())
            return -1;
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    void delNode(int key)
    {
        int idx = -1;
        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i] == key)
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return; // key not found

        heap[idx] = heap.back();
        heap.pop_back();

        if (idx < heap.size())
        {
            heapifyDown(idx);
            heapifyUp(idx);
        }
    }

    void display()
    {
        for (int x : heap)
            cout << x << " ";
        cout << "\n";
    }
};

#include <vector>

class MaxHeap
{
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyDown(int i)
    {
        int l = left(i), r = right(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i)
    {
        while (i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    void insertKey(int key)
    {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMax()
    {
        if (heap.empty())
            return -1;
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    void buildHeap(const vector<int> &arr)
    {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--)
        {
            heapifyDown(i);
        }
    }
    int peek()
    {
        return heap.empty() ? -1 : heap[0];
    }
    void delNode(int key)
    {
        int idx = -1;
        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i] == key)
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return; // key not found

        heap[idx] = heap.back();
        heap.pop_back();

        if (idx < heap.size())
        {
            heapifyDown(idx);
            heapifyUp(idx);
        }
    }

    void display()
    {
        for (int x : heap)
            cout << x << " ";
        cout << "\n";
    }
};

// HeapSort Ascending (uses Max Heap)
void heapifyMax(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapSortAsc(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

// HeapSort Descending (uses Min Heap)
void heapifyMin(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortDesc(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

// pq using heapify
class PriorityQueue
{
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyDown(int i)
    {
        int l = left(i), r = right(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(int key)
    {
        heap.push_back(key);
        int i = heap.size() - 1;

        while (i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int pop()
    {
        if (heap.empty())
            return -1;
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return top;
    }

    int top() { return heap.empty() ? -1 : heap[0]; }

    void display()
    {
        for (int x : heap)
            cout << x << " ";
        cout << "\n";
    }
};
// priority queue (manual)
struct Node
{
    int value;
    int priority;
    Node *next;
    Node(int val, int pri) : value(val), priority(pri), next(nullptr) {}
};

class PriorityQueue
{
private:
    Node *front;

public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue()
    {
        while (front)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void insert(int val, int pri)
    {
        Node *newNode = new Node(val, pri);
        if (!front || pri > front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *current = front;
            while (current->next && current->next->priority >= pri)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void remove()
    {
        if (!front)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    int peek()
    {
        if (!front)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->value;
    }

    void printQueue()
    {
        if (!front)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *current = front;
        while (current)
        {
            cout << "(" << current->value << ", " << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{

    return 0;
}