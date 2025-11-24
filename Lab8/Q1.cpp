#include <iostream>
#include <vector>
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

    Node *InSuccessor(Node *root)
    {
        while (!root && !root->left)
            root = root->left;
        return root;
    }
    

public:
    BST() : root(nullptr) {}
    Node *insert(Node *root, int v)
    {
        if (root == NULL)
            return new Node(v);

        if (v < root->data)
            root->left = insert(root->left, v);
        else
            root->right = insert(root->right, v);
        return root;
    }

    void inOrder(Node *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void preOrder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(Node *root)
    {
        if (root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    Node *search(Node *root, int key)
    {
        if (!root)
            return NULL;
        if (root->data == key)
            return root;
        else if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
    void buildBST(vector<int> &arr)
    {
        root = nullptr;
        for (int i : arr)
            root = insert(root, i);
    }
    Node *delNode(Node *root, int key)
    {
        if (!root)
            return NULL;
        if (key < root->data)
        {
            root->left = delNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = delNode(root->right, key);
        }
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
                root->right = delNode(root->right, IS->data);
            }
        }
        return root;
    }
    Node *getRoot() { return root; }
};

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    BST tree;
    tree.buildBST(arr);

    cout << "Preorder Traversal: ";
    tree.preOrder(tree.getRoot());
    cout << "\nPostorder Traversal: ";
    tree.postOrder(tree.getRoot());
    cout << "\nInorder Traversal: ";
    tree.inOrder(tree.getRoot());

    cout << "\nDeleting 5...\n";
    tree.delNode(tree.getRoot(), 5);

    cout << "Inorder after deletion: ";
    tree.inOrder(tree.getRoot());
    cout << "\nSearching for 4: " << (tree.search(tree.getRoot(), 4) ? "Found" : "Not Found") << endl;

    return 0;
}
