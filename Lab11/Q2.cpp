#include<iostream>
using namespace std;

#define TSIZE 100

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

class Dictionary {
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
    Dictionary() {
        for (int i = 0; i < TSIZE; i++)
        {
            table[i] = nullptr;
        }
        
    }
    void Add_Record(string k, const string& v) {
        int index = hash(k);
        Node* curr = table[index];

        while(curr) {
            if(curr->key == k) {
                curr->value = v;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(k, v);
        newNode->next = table[index];
        table[index] = newNode;
    }

    Node* Word_Search(string key) {
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

    void Delete_Record(string key) {
        int index = hash(key);
        Node* curr = table[index];
        Node *prev = nullptr;
        while(curr) {
            if(curr->key == key) {
                if(!prev) {
                    table[index] = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Key " << key << " deleted Successfully!" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Error: Key Not Found!" << endl;
    }

    void Print_Dictionary() {
        for(int i = 0 ; i < TSIZE ; i++){
            if(table[i]) {
                Node* temp = table[i];
                cout << "Index " << i << ": " ;
            
                while(temp){
                    cout << "(" << temp->key << ", " << temp->value << ")";
                    temp = temp->next;
                }
                cout << endl;            
            }
        }
    }
};

int main(){
    Dictionary d;

    d.Add_Record("AB", "FASTNU");
    d.Add_Record("CD", "CS");
    d.Add_Record("EF", "AI");
    
    Node *find = d.Word_Search("AB");
    if(find) {
        cout << "Search key AB: " << find->value << endl;
    }
    else {
        cout << "Search key AB: Not Found!" << endl;
    }
    d.Delete_Record("EF");
    cout << "The complete Dictionary:" << endl;
    d.Print_Dictionary();
    return 0;
}
