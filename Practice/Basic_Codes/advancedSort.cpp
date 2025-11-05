#include <iostream>
#include <vector>
using namespace std;

//============ Merge Sort
//------------ For array vector
void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[1]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
        while (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= end)
        {
            temp.push_back(arr[j]);
            j++;
        }
        for (int idx = 0; idx < temp.size(); idx++)
        {
            arr[idx + st] = temp[idx];
        }
    }
}
void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // right half
        merge(arr, st, mid, end);
    }
}

//================= Quick Sort
//--------------For Array Vectors
int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1, pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}
void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx - 1);  // left half
        quickSort(arr, pivIdx + 1, end); // right half
    }
}

//*************** Both in Linked List
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList() { head = nullptr; }
    ~LinkedList()
    {
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insert(int val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
    }

    void display()
    {
        Node *temp = head;
        cout << "List: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // --- MERGE SORT IMPLEMENTATION ---

    Node *merge(Node *left, Node *right)
    {
        if (!left)
            return right;
        if (!right)
            return left;

        Node *result = nullptr;

        if (left->data <= right->data)
        {
            result = left;
            result->next = merge(left->next, right);
        }
        else
        {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    void split(Node *source, Node **frontRef, Node **backRef)
    {
        Node *slow = source;
        Node *fast = source->next;

        while (fast)
        {
            fast = fast->next;
            if (fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = nullptr;
    }

    Node *mergeSort(Node *h)
    {
        if (!h || !h->next)
            return h;

        Node *a;
        Node *b;
        split(h, &a, &b);
        a = mergeSort(a);
        b = mergeSort(b);
        return merge(a, b);
    }

    void sortMerge()
    {
        head = mergeSort(head);
        cout << "List sorted using Merge Sort.\n";
    }

    // --- QUICK SORT IMPLEMENTATION ---

    Node *getTail(Node *cur)
    {
        while (cur && cur->next)
            cur = cur->next;
        return cur;
    }

    Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
    {
        Node *pivot = end;
        Node *prev = nullptr;
        Node *cur = head;
        Node *tail = pivot;

        while (cur != pivot)
        {
            if (cur->data < pivot->data)
            {
                if (!(*newHead))
                    *newHead = cur;
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                    prev->next = cur->next;
                Node *tmp = cur->next;
                cur->next = nullptr;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if (!(*newHead))
            *newHead = pivot;
        *newEnd = tail;
        return pivot;
    }

    Node *quickSortRecur(Node *head, Node *end)
    {
        if (!head || head == end)
            return head;

        Node *newHead = nullptr;
        Node *newEnd = nullptr;

        Node *pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot)
        {
            Node *tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = nullptr;

            newHead = quickSortRecur(newHead, tmp);

            tmp = getTail(newHead);
            tmp->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);
        return newHead;
    }

    void sortQuick()
    {
        head = quickSortRecur(head, getTail(head));
        cout << "List sorted using Quick Sort.\n";
    }
};
