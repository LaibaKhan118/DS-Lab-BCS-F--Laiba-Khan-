#include <iostream>
using namespace std;
#define TSIZE 15

class Node {
public:
    int rollNum;
    string name;

    Node(int r, string n): rollNum(r), name(n) {}
};

class HashTable{
    Node* table[TSIZE];

    int hash(int key) {
        return key % TSIZE;
    }
public:
    HashTable() {
        for (int i = 0; i < TSIZE; i++)
        {
            table[i] = nullptr;
        }
    }

    void insert(int roll, const string& name) {
        int index = hash(roll);
        int attempt = 0;
        while(attempt < TSIZE) {
            int currIndex = (index + attempt * attempt) % TSIZE;
            if(!table[currIndex]) {
                Node *newNode = new Node(roll, name);
                table[currIndex] = newNode;
                return;
            }
            else if(table[currIndex]->rollNum == roll) {
                table[currIndex]->name = name;
                return;
            }
            attempt++;
        }
        cout << "Error: Table Full!" << endl;
    }
    
    void search(int roll) {
    int index = hash(roll);
    int attempt = 0;
    while(attempt < TSIZE) {
        int currIndex = (index + attempt * attempt) % TSIZE;
        if(table[currIndex]->rollNum == roll) {
            cout << "[" << currIndex << "]: " << "Name: " << table[currIndex]->name << endl;
            return;
        }
        attempt++;
    }
    cout << "Record not found!" << endl;
    }
};
int main()
{
    HashTable studentRecords;

    studentRecords.insert(101, "Laiba");
    studentRecords.insert(202, "Yumna");
    studentRecords.insert(101, "Faiza"); 
    studentRecords.insert(303, "Aamna");
    studentRecords.insert(16, "Abeeha"); 
    studentRecords.insert(31, "Zunairah");

    studentRecords.search(101);

    return 0;
}
