#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* child;
    Node(int val):data(val), next(nullptr), child(nullptr) {} 
};

class LinkedList{
private:
    Node* head;

    Node* flattenList(Node* node) {
        Node* curr = node;
        while(curr) {
            if(curr->child){
                Node *childHead = flattenList(curr->child);
                Node *nextNode = curr->next;
                curr->next = childHead;
                curr->child = nullptr;
                Node* tail = childHead;
                while(tail->next) { tail = tail->next; }
                tail->next = nextNode;
            }
            curr = curr->next;
        }
        return node;
    }

    void freeAll(Node* node) {
        while(node) {
        Node* nextNode = node->next;
        if(node->child) { freeAll(node->child); }
        delete node;
        node = nextNode;
        }
    }

    void printList(Node *node, int level = 0)
    {
        if (!node) return;
        for (int i = 0; i < level; i++) cout << "    ";
        
        Node *temp = node;
        while (temp)
        {
            cout << temp->data;
            if (temp->next) cout << "->";

            if (temp->child) {   
                cout << endl;
                for (int i = 0; i < level; i++) cout << "   ";
                cout << "    |\n";
                printList(temp->child, level + 1);
            }
            temp = temp->next;
        }
    }

    public:
    LinkedList(): head(nullptr) {}
    ~LinkedList(){
        freeAll(head);
        head = nullptr;
    }
    Node* getHead() { return head; }
    void setHead(Node* h) { head = h; }
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if(!head) { head = newNode; return; }
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertChildAt(int pos, LinkedList& list) {
        if(!head) {cout<<"Main list is empty\n"; return;}

        Node* temp = head;
        int count = 0;
        while(temp && count < pos) {
            temp = temp->next;
            count++;
        }
        if(!temp) {
            cout << "Invalid position" << endl;
            return;
        }

        temp->child = list.getHead();
        list.setHead(nullptr); 
    }
    void flatten() {
        if(head) { head = flattenList(head); }
    }
    void print() { printList(head, 0); }
};

int main()
{
    LinkedList mainList;
    mainList.insertEnd(1);
    mainList.insertEnd(2);
    mainList.insertEnd(3);

    LinkedList childList;
    childList.insertEnd(4);
    childList.insertEnd(5);

    mainList.insertChildAt(1, childList);

    cout << "Before flattening:\n";
    mainList.print();

    mainList.flatten();

    cout << "\nAfter flattening:\n";
    mainList.print();

    return 0;
}
