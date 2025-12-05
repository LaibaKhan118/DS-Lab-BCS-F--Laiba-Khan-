#include <iostream>
using namespace std;

#include <vector>

struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

class HashTable {
    int size;
    vector<Node*> table;

public:
    HashTable(int s) : size(s), table(s, nullptr) {}

    int hash(int key) { return key % size; }

    void insertKey(int key) {
        int index = hash(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    bool searchKey(int key) {
        int index = hash(key);
        Node* temp = table[index];
        while (temp) {
            if (temp->key == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hash(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp) {
            if (temp->key == key) {
                if (prev) prev->next = temp->next;
                else table[index] = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp) { cout << temp->key << " -> "; temp = temp->next; }
            cout << "NULL\n";
        }
    }
};
class HashTableDH {
    int size;
    vector<int> table;

public:
    HashTableDH(int s) : size(s), table(s, -1) {}

    int hash1(int key) { return key % size; }
    int hash2(int key) { return 7 - (key % 7); }

    void insertKey(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (table[index] != -1)
            index = (index + step) % size;
        table[index] = key;
    }

    bool searchKey(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (table[index] != -1) {
            if (table[index] == key) return true;
            index = (index + step) % size;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (table[index] != -1) {
            if (table[index] == key) { table[index] = -1; return; }
            index = (index + step) % size;
        }
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " : " << table[i] << "\n";
    }
};


class HashTableLP {
    int size;
    vector<int> table;

public:
    HashTableLP(int s) : size(s), table(s, -1) {}

    int hash(int key) { return key % size; }

    void insertKey(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i) % size] != -1) i++;
        table[(index + i) % size] = key;
    }

    bool searchKey(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i) % size] != -1) {
            if (table[(index + i) % size] == key) return true;
            i++;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i) % size] != -1) {
            if (table[(index + i) % size] == key) {
                table[(index + i) % size] = -1;
                return;
            }
            i++;
        }
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " : " << table[i] << "\n";
    }
};

class HashTableQP {
    int size;
    vector<int> table;

public:
    HashTableQP(int s) : size(s), table(s, -1) {}

    int hash(int key) { return key % size; }

    void insertKey(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i*i) % size] != -1) i++;
        table[(index + i*i) % size] = key;
    }

    bool searchKey(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i*i) % size] != -1) {
            if (table[(index + i*i) % size] == key) return true;
            i++;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i*i) % size] != -1) {
            if (table[(index + i*i) % size] == key) {
                table[(index + i*i) % size] = -1;
                return;
            }
            i++;
        }
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " : " << table[i] << "\n";
    }
};

class HashTableRH {
    int size;
    int count;
    vector<int> table;

public:
    HashTableRH(int s) : size(s), table(s, -1), count(0) {}

    int hash(int key) { return key % size; }

    double loadFactor() { return (double)count / size; }

    void rehash() {
        int oldSize = size;
        size *= 2;
        vector<int> oldTable = table;

        table.assign(size, -1);
        count = 0;

        for (int i = 0; i < oldSize; i++)
            if (oldTable[i] != -1) insertKey(oldTable[i]);
    }

    void insertKey(int key) {
        if (loadFactor() > 0.7) rehash();

        int index = hash(key);
        int i = 0;
        while (table[(index + i) % size] != -1) i++;
        table[(index + i) % size] = key;
        count++;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " : " << table[i] << "\n";
    }
};

int main()
{
    
    return 0;
}