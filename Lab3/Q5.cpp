#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val):data(val), next(nullptr) {}
};

class DNode {
    public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) :data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
    private:
    Node* head;

    public:
    LinkedList():head(nullptr){}
    ~LinkedList(){
        if(!head) {return;}
        Node* fast = head;
        Node* slow = head;
        bool isCircular = false;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                isCircular = true;
                break;
            }
        }

        if(isCircular) {
            Node* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = nullptr;
        }

        while(head) {
            Node* newNode = head->next;
            delete head;
            head = newNode;
        }
    }
    Node* getHead() {return head;}

    void insertEnd(int val) {
        Node* newNode=new Node(val);
        if(!head){
            head = newNode;
            return;
        }
        Node * temp = head;
        while(temp->next) { temp=temp->next; }
        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        while(temp) {
            cout << temp->data;
            if(temp->next) cout << "->";
            temp = temp->next;
        }
        cout<<endl;
    }

    DNode* doubly() {
        if(!head) return nullptr;
        DNode* Dhead = new DNode(head->data);
        DNode* Dtail = Dhead;
        Node* temp = head->next;
        while(temp) {
            DNode* newNode = new DNode(temp->data);
            Dtail->next = newNode;
            newNode->prev = Dtail;
            Dtail = newNode;
            temp = temp->next;
        }
        return Dhead;
    }

    void Circular() {
        if(!head) return;
        Node* temp = head;
        while(temp->next) { temp= temp->next; }
        temp->next = head;
    }
};

void printDoubly(DNode* head) {
    cout << "Forward: \n";
    DNode* tail = nullptr;
    while(head) {
        cout << head->data << "<->";
        if(!head->next) {tail = head;}
        head = head->next;
    }

    cout << "NULL\nBackward:\n";
    while(tail) {
        cout<<tail->data<<"<->";
        tail = tail->prev;
    }
    cout << "NULL" << endl;
}

void freeDoubly(DNode* head) {
    while(head)
    {
        DNode* newNode = head->next;
        delete head;
        head=newNode;
    }    
} 

int main()
{
    LinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    cout << "Original: ";
    list.print();

    DNode *dlist = list.doubly();
    cout << "Converted to Doubly: \n";
    printDoubly(dlist);

    list.Circular();
    cout << "Converted to Circular (print 5 nodes): ";
    Node *h = list.getHead();
    for (int i = 0; i < 5; i++)
    {
        cout << h->data << " -> ";
        h = h->next;
    }
    cout << "(back...)\n";

    freeDoubly(dlist); 
    return 0;
}
