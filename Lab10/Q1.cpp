#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i)+1; }
int right(int i) { return (2*i)+2; }

class MaxHeap
{
private:
    vector<int> heap;
    void heapifyUp(int i)
    {
        while (i>0 && heap[(i-1)/2]<heap[i])
        {
            swap(heap[i], heap[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    void heapifyDown(int i)
    {
        int largest = i;
        int leftChild = left(i);
        int rightChild = right(i);

        if (leftChild<heap.size() && heap[leftChild]>heap[largest])
        {
            largest=leftChild;
        }
        if (rightChild<heap.size() && heap[rightChild]>heap[largest])
        {
            largest =rightChild;
        }

        if (largest !=i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(const vector<int> &values)
    {
        heap = values;
        for (int i = heap.size()/2-1; i>=0; --i)
        {
            heapifyDown(i);
        }
    }
    void update_key(int i, int new_val)
    {
        if(i<0 || i>=heap.size())
        {
            cout<<"Invalid index for update."<<endl;
            return;
        }
        int old_val= heap[i];
        heap[i] =new_val;
        if(new_val>old_val)
        {
            heapifyUp(i);
        }
        else
        {
            heapifyDown(i);
        }
    }
    void deleteElement()
    {
        if(heap.empty())
        {
            cout<<"Heap is empty, cannot delete." << endl;
            return;
        }
        if (heap.size()== 1)
        {
            heap.pop_back();
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    void printHeap() const
    {
        for (int val:heap)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    vector<int> initial_values ={8, 7, 6, 5, 4};
    MaxHeap myHeap(initial_values);
    cout<<"Initial Max Heap: ";
    myHeap.printHeap();

    myHeap.update_key(3, 10);
    cout<<"Heap after updating key at index 3 to 10: ";
    myHeap.printHeap();

    myHeap.deleteElement();
    cout<<"Heap after deleting root: ";
    myHeap.printHeap();
    return 0;
}
