#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

public:
    BST() : root(nullptr) {}

    Node *insert(Node *root, int v)
    {
        if (root == NULL)
            return new Node(v);

        if (v < root->data)
            root->left = insert(root->left, v);
        else if (v > root->data) 
            root->right = insert(root->right, v);
        return root;
    }

    void buildBST(vector<int> &arr)
    {
        root = nullptr;
        for (int i : arr)
            root = insert(root, i);
    }
    bool Validate(Node *root, Node* min, Node* max)
    {
        if (!root)
            return true;
        if (min && root->data <= min->data)
            return false;
        else if (max && root->data >= max->data)
            return false;
        else
        {
            return ((Validate(root->left, min, root) && Validate(root->right, root, max)));
        }
    }
    bool isValidBST()
    {
        return Validate(root, NULL, NULL);
    }
    void inOrder(Node* root)
    {
        if (!root)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    Node *getRoot() { return root; }
    void setRoot(Node* r) { root=r; }
};

int main()
{
    vector<int> arr = {10, 5, 20, 5};

    BST tree;
    tree.buildBST(arr);

    cout << "1.\nInorder Traversal: ";
    tree.inOrder(tree.getRoot());
    cout << endl;
    if(tree.isValidBST()) {
        cout << "This is a valid BST" << endl;
    }
    else {
        cout << "This is not a valid BST" << endl;
    }

    Node *n10 = new Node(10);
    Node *n5 = new Node(5);
    Node *n20 = new Node(20);
    Node *n40 = new Node(40);

    n10->left = n5;
    n10->right = n20;
    // INVALID: Insert 40 into the LEFT subtree
    n5->left = n40;
    BST tree2;
    tree2.setRoot(n10);

    cout << "2.\nInorder Treversal: ";
    tree2.inOrder(tree2.getRoot());
    cout << endl;
    if(tree2.isValidBST()) {
        cout << "This is a valid BST" << endl;
    }
    else {
        cout << "This is not a valid BST" << endl;
    }

    return 0;
}
