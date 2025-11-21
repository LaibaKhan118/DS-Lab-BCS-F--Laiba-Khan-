#include<iostream>
using namespace std;

#define TSIZE 11
class Node{
public:
    string key;
    string value;
    Node* next;

    Node(string k, const string& v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
private:
    Node* table[TSIZE];
    int hash(string key) {
        int ind = 0;
        for(char i: key) {
            ind += i;
        }
        return ind%TSIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TSIZE; i++)
        {
            table[i] = nullptr;
        }
        
    }
    void insert(string key, const string& v) {
        int index = hash(key);
        Node* curr = table[index];

        while(curr) {
            if(curr->key == key) {
                curr->value = v;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(key, v);
        newNode->next = table[index];
        table[index] = newNode;
    }
    Node* search(string key) {
        int index = hash(key);
        Node* curr = table[index];

        while(curr) {
            if(curr->key == key) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }
};

int main(){
    HashTable Htable;
    Htable.insert("A", "aaaaaa");
    Htable.insert("B", "bbbbb");
    Htable.insert("C", "ccccc");
    Htable.insert("A", "zzzzz");
    cout << "inserted!" << endl;
    Node* find = Htable.search("A");
    if(find) {
        cout << "Found:\nKey:" << find->key << "\nValue:" << find->value; 
    }
   
    return 0;
}
