#include<iostream>
#include<vector>

using namespace std;

int parent(int i) { return (i - 1) / 2; } // Parent index
int left(int i) { return (2 * i) + 1; } // Left child index
int right(int i) { return (2 * i) + 2; } // Right child index

class MaxHeap {
private:
    vector<int> heap;
    void heapify_up(int idx) {
        while(idx != 0 && (heap[idx] > heap[parent(idx)])) {
            swap(heap[idx], heap[parent(idx)]);
            idx = parent(idx);
        }
    }
    void heapify_down(int idx) {
        int largest = idx;
        int l = left(idx);
        int r = right(idx);

        if(l < heap.size() && heap[l] > heap[largest]) {
            largest = l;
        }
        if(r < heap.size() && heap[r] > heap[largest]) {
            largest = r;
        }

        if(idx != largest) {
            swap(heap[idx], heap[largest]);
            heapify_down(largest);
        }
    }
public:
    void insert(int v) {
        if(heap.size() == 100) {
            cout << "Heap Overflow!!!!!!" << endl;
        }
        heap.push_back(v);
        heapify_up(heap.size()-1);
    }
    int getDelMax() {
        if (heap.empty()) return -1;
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
        return max;
    }
    // void del(int x) {
    //     int i;
    //     for (i = 0; i < heap.size(); i++)
    //     {
    //         if(heap[i] == x) {
    //             break;
    //         }
    //     }
    //     int idx = i;
    //     heapify_down(idx);
    // }
    void update_key(int i, int new_val){
        heap[i] = new_val;
    }
     void display() {
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(6);
    maxHeap.insert(4);
    maxHeap.insert(9);
    maxHeap.insert(3);
    maxHeap.insert(2);
    
    maxHeap.display();
    cout << "\nExtracted Max: " << maxHeap.getDelMax() << endl;
    maxHeap.display();
    cout << endl;
    // cout << "Deleting 3: " << endl;
    // maxHeap.del(3);
    // maxHeap.display();
    // cout << endl;
    cout << "Updating element at 3rd index to 10" << endl;
    maxHeap.update_key(2, 10);
    cout << endl;
    maxHeap.display();
    
    return 0;
}
