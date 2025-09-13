#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

    Node* reverse(Node *headNode, int k)
    {
        Node *previous= nullptr;
        Node *current= headNode;
        Node *next = nullptr;
        int count =0;
        Node* temp= headNode;
        int nCount = 0;
        while(temp && nCount < k) {
            temp = temp->next;
            nCount++;
        }
        if(nCount < k) return headNode;
        while (current && count<k)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            count++;
        }
        if(next) headNode->next = reverse(next, k);
        return previous;
    }

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() { 
        Node* temp = head;
        while (temp){
            Node* next=temp->next;
            delete temp;
            temp=next;
        }
    }
    void insertEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void reverseInGroups(int k) { head = reverse(head, k); }
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
};

int main()
{
    LinkedList list;
    for(int i=0; i<9;i++){
        list.insertEnd(i);
    }

    list.reverseInGroups(3);

    cout << "Merged List" << endl;
    list.print();
    return 0;
}
