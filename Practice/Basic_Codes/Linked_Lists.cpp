#include <iostream>
using namespace std;

//============= Singly Linked List
class SNode
{
public:
    int data;
    SNode *next;

    SNode(int d) : data(d), next(nullptr) {}
};

class SinglyList
{
private:
    SNode *head;
    void reverse()
    {
        SNode *pre = nullptr;
        SNode *curr = head;
        SNode *next = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        head = pre;
    }

public:
    SinglyList() : head(nullptr) {}
    ~SinglyList()
    {
        SNode *temp = head;
        while (temp)
        {
            SNode *next = temp->next;
            delete temp;
            temp = temp->next;
        }
        head = nullptr;
    }

    void insertAtStart(int v)
    {
        SNode *node = new SNode(v);
        node->next = head;
        head = node;
    }
    void insertAtEnd(int v)
    {
        SNode *node = new SNode(v);
        if (!head)
        {
            head = node;
            return;
        }
        SNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        node->next = head;
    }
    void insertAtPos(int v, int p)
    {
        if (p == 0)
        {
            insertAtStart(v);
            return;
        }
        SNode *temp = head;
        for (int i = 0; temp && (i < p - 1); i++)
        {
            temp = temp->next;
        }
        if (!temp)
            return;
        SNode *node = new SNode(v);
        node->next = temp->next;
        temp->next = node;
    }

    void deleteAtStart()
    {
        if (!head)
        {
            return;
        }
        SNode *n = head;
        head = head->next;
        delete n;
    }
    void delteAtEnd()
    {
        if (!head)
        {
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        SNode *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void deleteAtPos(int p)
    {
        if (p == 0)
        {
            deleteAtStart();
            return;
        }
        SNode *temp = head;
        for (int i = 0; temp && (i < p - 1); i++)
        {
            temp = temp->next;
        }
        if (temp || temp->next)
        {
            return;
        }
        SNode *toDel = temp->next;
        temp->next = toDel->next;
        delete toDel;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        SNode *temp = head;
        while (temp)
        {
            cout << temp->data;
            temp = temp->next;
            if (temp)
            {
                cout << " -> ";
            }
        }
    }
};

//============= Circular Singly Linked List
class CNode
{
public:
    int data;
    CNode *next;

    CNode(int d) : data(d), next(nullptr) {}
};

class CircularList
{
private:
    CNode *head;

public:
    CircularList() : head(nullptr) {}

    ~CircularList()
    {
        if (!head)
            return;
        CNode *temp = head->next;
        while (temp != head)
        {
            CNode *next = temp->next;
            delete temp;
            temp = next;
        }
        delete head;
        head = nullptr;
    }

    void insertAtStart(int v)
    {
        CNode *node = new CNode(v);
        if (!head)
        {
            head = node;
            head->next = head;
            return;
        }
        CNode *temp = head;
        while (temp->next != head)
            temp = temp->next;
        node->next = head;
        temp->next = node;
        head = node;
    }

    void insertAtEnd(int v)
    {
        CNode *node = new CNode(v);
        if (!head)
        {
            head = node;
            head->next = head;
            return;
        }
        CNode *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = node;
        node->next = head;
    }

    void insertAtPos(int v, int p)
    {
        if (p == 0)
        {
            insertAtStart(v);
            return;
        }
        if (!head)
            return;

        CNode *temp = head;
        for (int i = 0; temp->next != head && i < p - 1; i++)
            temp = temp->next;

        CNode *node = new CNode(v);
        node->next = temp->next;
        temp->next = node;
    }

    void deleteAtStart()
    {
        if (!head)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        CNode *temp = head;
        while (temp->next != head)
            temp = temp->next;

        CNode *toDel = head;
        temp->next = head->next;
        head = head->next;
        delete toDel;
    }

    void deleteAtEnd()
    {
        if (!head)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        CNode *temp = head;
        while (temp->next->next != head)
            temp = temp->next;

        CNode *toDel = temp->next;
        temp->next = head;
        delete toDel;
    }

    void deleteAtPos(int p)
    {
        if (!head)
            return;

        if (p == 0)
        {
            deleteAtStart();
            return;
        }

        CNode *temp = head;
        for (int i = 0; temp->next != head && i < p - 1; i++)
            temp = temp->next;

        if (temp->next == head)
            return;

        CNode *toDel = temp->next;
        temp->next = toDel->next;
        delete toDel;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        CNode *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

// ============= Doubly Linked List

class DNode
{
public:
    int data;
    DNode *next;
    DNode *prev;

    DNode(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoublyList
{
private:
    DNode *head;

public:
    DoublyList() : head(nullptr) {}

    ~DoublyList()
    {
        DNode *temp = head;
        while (temp)
        {
            DNode *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }

    void insertAtStart(int v)
    {
        DNode *node = new DNode(v);
        if (!head)
        {
            head = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

    void insertAtEnd(int v)
    {
        DNode *node = new DNode(v);
        if (!head)
        {
            head = node;
            return;
        }
        DNode *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = node;
        node->prev = temp;
    }

    void insertAtPos(int v, int p)
    {
        if (p == 0)
        {
            insertAtStart(v);
            return;
        }
        DNode *temp = head;
        for (int i = 0; temp && i < p - 1; i++)
            temp = temp->next;

        if (!temp)
            return;

        DNode *node = new DNode(v);
        node->next = temp->next;
        node->prev = temp;

        if (temp->next)
            temp->next->prev = node;

        temp->next = node;
    }

    void deleteAtStart()
    {
        if (!head)
            return;

        DNode *temp = head;
        head = head->next;

        if (head)
            head->prev = nullptr;

        delete temp;
    }

    void deleteAtEnd()
    {
        if (!head)
            return;

        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        DNode *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPos(int p)
    {
        if (!head)
            return;

        if (p == 0)
        {
            deleteAtStart();
            return;
        }

        DNode *temp = head;
        for (int i = 0; temp && i < p; i++)
            temp = temp->next;

        if (!temp)
            return;

        if (temp->next)
            temp->next->prev = temp->prev;

        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
    }

    void displayForward()
    {
        DNode *temp = head;
        cout << "Forward: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward()
    {
        if (!head)
            return;

        DNode *temp = head;
        while (temp->next)
            temp = temp->next;

        cout << "Backward: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

//============= Circular Doubly Linked List
class CDNode
{
public:
    int data;
    CDNode *next;
    CDNode *prev;

    CDNode(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class CircularDoublyList
{
private:
    CDNode *head;

public:
    CircularDoublyList() : head(nullptr) {}

    ~CircularDoublyList()
    {
        if (!head)
            return;

        CDNode *temp = head->next;
        while (temp != head)
        {
            CDNode *next = temp->next;
            delete temp;
            temp = next;
        }
        delete head;
        head = nullptr;
    }

    void insertAtStart(int v)
    {
        CDNode *node = new CDNode(v);
        if (!head)
        {
            head = node;
            head->next = head;
            head->prev = head;
            return;
        }

        CDNode *tail = head->prev;
        node->next = head;
        node->prev = tail;
        tail->next = node;
        head->prev = node;
        head = node;
    }

    void insertAtEnd(int v)
    {
        CDNode *node = new CDNode(v);
        if (!head)
        {
            head = node;
            head->next = head;
            head->prev = head;
            return;
        }

        CDNode *tail = head->prev;
        tail->next = node;
        node->prev = tail;
        node->next = head;
        head->prev = node;
    }

    void insertAtPos(int v, int p)
    {
        if (!head || p == 0)
        {
            insertAtStart(v);
            return;
        }

        CDNode *temp = head;
        for (int i = 0; i < p - 1 && temp->next != head; i++)
            temp = temp->next;

        CDNode *node = new CDNode(v);
        node->next = temp->next;
        node->prev = temp;
        temp->next->prev = node;
        temp->next = node;
    }

    void deleteAtStart()
    {
        if (!head)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        CDNode *tail = head->prev;
        CDNode *toDel = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete toDel;
    }

    void deleteAtEnd()
    {
        if (!head)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        CDNode *tail = head->prev;
        CDNode *newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        delete tail;
    }

    void deleteAtPos(int p)
    {
        if (!head)
            return;

        if (p == 0)
        {
            deleteAtStart();
            return;
        }

        CDNode *temp = head;
        for (int i = 0; i < p && temp->next != head; i++)
            temp = temp->next;

        if (temp == head)
            return;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void displayForward()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        CDNode *temp = head;
        cout << "Forward: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayBackward()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        CDNode *temp = head->prev;
        cout << "Backward: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << endl;
    }
};
