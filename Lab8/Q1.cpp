#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int v):data(v), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;
    Node *insert(Node *root, int v){
        if (root == NULL)
            return new Node(v);

        if (v < root->data)
            root->left =insert(root->left, v);
        else
            root->right= insert(root->right, v);
        return root;
    }

    void inOrder(Node *root){
        if (root == NULL)
            return;
        inOrder(root->left);
        cout<< root->data << " ";
        inOrder(root->right);
    }

    void inDOrder(Node *root){
        if (root == NULL)
            return;
        inDOrder(root->right);
        cout << root->data << " ";
        inDOrder(root->left);
    }

    Node *search(Node *root, int key){
        if (!root)
            return NULL;
        if (root->data == key)
            return root;
        else if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    Node *InSuccessor(Node *root){
        Node *curr = root;
        while (curr && curr->left)
            curr = curr->left;
        return curr;
    }

    Node *delNode(Node *root, int key){
        if (!root)
            return NULL;
        if (key < root->data)
            root->left = delNode(root->left, key);
        else if (key > root->data)
            root->right = delNode(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *IS = InSuccessor(root->right);
                root->data = IS->data;
            }
        }
        return root;
    }

public:
    BST() : root(nullptr) {}
    void buildBST(vector<int> &arr)
    {
        root = nullptr;
        for (int i : arr)
            root = insert(root, i);
    }
    void insert(int val)
    {
        root = insert(root, val);
    }
    void deleteValue(int val)
    {
        root = delNode(root, val);
    }
    bool search(int val)
    {
        return search(root, val) != NULL;
    }
    void printAscending(){
        inOrder(root);
        cout<< endl;
    }
    void printDescending(){
        inDOrder(root);
        cout<< endl;
    }
};

int main()
{
    vector<int> arr ={3, 2, 1, 5, 6, 4};

    BST tree;
    tree.buildBST(arr);

    cout << "Inorder (Ascending with heights): ";
    tree.printAscending();

    cout << "\nDeleting 5...\n";
    tree.deleteValue(5);

    cout << "Inorder after deletion: ";
    tree.printAscending();
    cout << "Searching for 4: " << (tree.search(4) ? "Found" : "Not Found") << endl;

    return 0;
}
