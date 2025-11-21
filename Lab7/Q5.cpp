#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

void append(Node*& head, int data) {
    Node* newNode= new Node(data);
    if (!head) {
        head= newNode;
        return;
    }
    Node* temp= head;
    while (temp->next)
        temp= temp->next;
    temp->next= newNode;
}

void printList(Node* head) {
    while (head) {
        cout<< head->data << " ";
        head= head->next;
    }
    cout << endl;
}

void swapNodes(Node* a, Node* b) {
    int temp = a->data;
    a->data= b->data;
    b->data =temp;
}

Node* partition(Node* head, Node* end, Node*& newHead, Node*& newEnd) {
    Node* pivot= end;
    Node* prev =NULL;
    Node* curr =head;
    Node* tail= pivot;
    while (curr !=pivot) {
        if (curr->data <pivot->data) {
            if (newHead == NULL)
                newHead= curr;
            prev = curr;
            curr= curr->next;
        }
        else {
            if (prev)
                prev->next =curr->next;
            Node* temp =curr->next;
            curr->next =NULL;
            tail->next =curr;
            tail =curr;
            curr =temp;
        }
    }
    if (newHead ==NULL)
        newHead =pivot;
    newEnd =tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head==end)
        return head;
    Node* newHead =NULL;
    Node* newEnd =NULL;
    Node* pivot =partition(head, end, newHead, newEnd);
    if (newHead !=pivot) {
        Node* temp =newHead;
        while (temp->next!= pivot)
            temp =temp->next;
        temp->next = NULL;
        newHead = quickSortRecur(newHead, temp);
        temp = newHead;
        while (temp->next)
            temp =temp->next;
        temp->next =pivot;
    }
    pivot->next =quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node*& head) {
    if (!head|| !head->next)
        return;
    Node* end =head;
    while (end->next)
        end =end->next;
    head =quickSortRecur(head, end);
}

int main() {
    Node* head =NULL;
    int arr[] ={10, 7, 8, 9, 1, 5, 3};
    for (int x :arr)
        append(head, x);
    cout <<"Original list: ";
    printList(head);
    quickSort(head);
    cout <<"Sorted list: ";
    printList(head);
    return 0;
}

