#include <iostream>
#include <list>
#include <string>
using namespace std;

#define TSIZE 100

class Node
{
public:
    string key;
    string value;
    Node *next;

    Node(string k, const string &v)
    {
        key = k;
        value = v;
        next = nullptr;
    }
};

class Hash
{
private:
    list<Node> table[TSIZE];
    int hash(string key)
    {
        int ind = 0;
        for (char i : key)
        {
            ind += i;
        }
        return ind % TSIZE;
    }

public:
    void insert(const string &k, const string &v)
    {
        int index = hash(k);
        for(auto &p : table[index]) {
            if(p.key == k) {
                p.value = v;
                return;
            }
        }
        table[index].push_back(Node(k, v));
    }

    Node *search(string key)
    {
        int index = hash(key);
        for (auto &p : table[index])
        {
            if (p.key == key)
            {
                return &p;
            }
        }
        return nullptr;
    }

    void Delete(string key)
    {
        int index = hash(key);
        for (auto i = table[index].begin(); i != table[index].end(); i++)
        {
            if (i->key == key)
            {
                table[index].erase(i);
                cout << "Key " << key << " deleted Successfully!" << endl;
                return;
            }
        }
        cout << "Error: Key Not Found!" << endl;
    }

    void display()
    {
        for (int i = 0; i < TSIZE; i++)
        {
            if (!table[i].empty())
            {
                cout << "Index " << i << ": ";
                for(auto &temp : table[i])
                {
                    cout << "(" << temp.key << ", " << temp.value << ")";
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    Hash h;

    h.insert("AB", "FASTNU");
    h.insert("CD", "CS");
    h.insert("EF", "AI");

    Node *result = h.search("AB");
    if (result)
        cout << "Search AB -> " << result->value << endl;
    else
        cout << "Key AB not found\n";

    h.Delete("EF");

    cout << "Complete Hash Table:\n";
    h.display();
    return 0;
}
