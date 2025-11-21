#include<iostream>
using namespace std;

#define TSIZE 100
class Node{
public:
    string value;
    Node* next;

    Node(const string& v) {
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
    void Add_Record(const string& v) {
        int index = hash(v);
        Node* curr = table[index];

        while(curr) {
            if(curr->value == v) {
                curr->value = v;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(v);
        newNode->next = table[index];
        table[index] = newNode;
    }
    Node* Word_Search(string word) {
        int index = hash(word);
        Node* curr = table[index];

        while(curr) {
            if(curr->value == word) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    void display() {
        for(int i = 0 ; i < TSIZE ; i++){
             Node* temp = table[i];
            if(temp == NULL){
                    continue;
                }
            cout << "[" << i << "]: " ;
           
            while(temp != NULL){
                cout << "(" << temp->value << ")" ;
                Node* curr = temp->next;

                while(curr != NULL){
                    cout << "->" ;
                     cout << "(" << curr->value << ")" ;
                     curr= curr->next;
                }
                cout << endl;
                temp = NULL;
            }
            
        }
    }
};

int main(){
    HashTable Htable;
    Htable.Add_Record("aaaaaa");
    Htable.Add_Record("bbbbb");
    Htable.Add_Record("ccccc");
    Htable.Add_Record("zzzzz");
    cout << "Inserted!" << endl;
    Node* find = Htable.Word_Search("aaaaaa");
    if(find) {
        cout << "Found:\nValue:" << find->value; 
    }
   cout << endl;
Htable.display();
    return 0;
}
