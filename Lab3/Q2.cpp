#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val):data(val),next(nullptr) {}
};

class LinkedList{
    private:
    Node* head;

    public:
    LinkedList():head(nullptr){}
    ~LinkedList() { 
        Node* temp = head;
        while (temp) {
            Node* next=temp->next;
            delete temp;
            temp= next;
        }
    }
    void insertEnd(int val) {
        Node* newNode= new Node(val);
        if(!head) { 
            head =newNode; return;
        }
        Node* temp = head;
        while(temp->next) {
            temp= temp->next;
        }
        temp->next = newNode;
    }

    Node *getHead() { return head; }

    void print() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    static LinkedList merge(LinkedList &l1, LinkedList& l2)
    {
        Node* a = l1.getHead();
        Node* b = l2.getHead();

        if(!a) { return l2; }
        else if(!b) {return l1;}
        Node* newHead = nullptr;
        if(a->data <= b->data) {
            newHead = a;
            a = a->next;
        }
        else{
            newHead = b;
            b = b->next;
        }
        Node* tail = newHead;

        while(a && b) {
            if (a->data <= b->data)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = (a? a:b);

        LinkedList mergedList;
        mergedList.head = newHead;
        return mergedList;

    }
};

int main()
{
    LinkedList list1, list2;
    list1.insertEnd(1);
    list1.insertEnd(3);
    list1.insertEnd(5);
    list2.insertEnd(2);
    list2.insertEnd(4);
    list2.insertEnd(6);

    LinkedList combined = LinkedList::merge(list1, list2);
    cout << "Merged List" << endl;
    combined.print();
    return 0;
}
