#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} 
};

class LinkedList{
    private: 
        Node * head;

        Node* reverse(Node* node) {
            Node* previous = nullptr;
            Node* current = node;
            Node* next = nullptr;
            while (current){
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            return previous;
        }

    public:
        LinkedList():head(nullptr){}

        void insertEnd(int val) {
            Node* newNode = new Node(val);
            if (!head) {
                head = newNode;
                return;
            }
            Node* temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void print() {
            Node* temp = head;
            while(temp){
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << "END" << endl;
        }

        bool isPalindrome() {
            if(!head || !head->next) return true;
            Node* slow = head; 
            Node* fast = head;
            while(fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }

            slow->next = reverse(slow->next);
            Node* first = head;
            Node* second = slow->next;
            while(second) {
                if(first->data != second->data) return false;
                    first = first->next;
                    second = second->next;
            }
            return true;
        }
};

int main()
{
    LinkedList list;
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(2);
    list.insertEnd(1);

    list.print();

    cout << (list.isPalindrome() ? "Palindrom" : "Not a Palindrome") << endl;
    return 0;
}
