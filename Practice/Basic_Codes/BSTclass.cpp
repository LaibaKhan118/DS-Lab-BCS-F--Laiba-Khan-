#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height; // new data member

    Node(int v) : data(v), left(nullptr), right(nullptr), height(1) {}
};

class BST
{
private:
    Node *root;

    // Utility to get height safely
    int getHeight(Node *node)
    {
        return (node == nullptr) ? 0 : node->height;
    }

    // Update height based on children's heights
    void updateHeight(Node *node)
    {
        if (node)
            node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    Node *insert(Node *root, int v)
    {
        if (root == NULL)
            return new Node(v);

        if (v < root->data)
            root->left = insert(root->left, v);
        else
            root->right = insert(root->right, v);

        // Update height after insertion
        updateHeight(root);
        return root;
    }

    void inOrder(Node *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        cout << root->data << "(h=" << root->height << ") ";
        inOrder(root->right);
    }

    void inDOrder(Node *root)
    {
        if (root == NULL)
            return;
        inDOrder(root->right);
        cout << root->data << "(h=" << root->height << ") ";
        inDOrder(root->left);
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

    Node *InSuccessor(Node *root)
    {
        Node *curr = root;
        while (curr && curr->left)
            curr = curr->left;
        return curr;
    }

    Node *delNode(Node *root, int key)
    {
        if (!root)
            return NULL;

        if (key < root->data)
            root->left = delNode(root->left, key);
        else if (key > root->data)
            root->right = delNode(root->right, key);
        else
        {
            // Node found
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

        // Update height after deletion
        updateHeight(root);
        return root;
    }

    Node *sortedToBST(vector<int> &arr, int st, int end)
    {
        if (st > end)
            return NULL;
        int mid = st + (end - st) / 2;
        Node *root = new Node(arr[mid]);
        root->left = sortedToBST(arr, st, mid - 1);
        root->right = sortedToBST(arr, mid + 1, end);
        updateHeight(root);
        return root;
    }

    bool Validate(Node *root, Node *min, Node *max)
    {
        if (!root)
            return true;
        if (min && root->data <= min->data)
            return false;
        if (max && root->data >= max->data)
            return false;
        return Validate(root->left, min, root) && Validate(root->right, root, max);
    }

public:
    BST() : root(nullptr) {}

    // Build BST from unsorted array
    void buildBST(vector<int> &arr)
    {
        root = nullptr;
        for (int i : arr)
            root = insert(root, i);
    }

    // Insert single value
    void insert(int val)
    {
        root = insert(root, val);
    }

    // Delete a node
    void deleteValue(int val)
    {
        root = delNode(root, val);
    }

    // Search a value
    bool search(int val)
    {
        return search(root, val) != NULL;
    }

    // Print inorder (ascending)
    void printAscending()
    {
        inOrder(root);
        cout << endl;
    }

    // Print descending
    void printDescending()
    {
        inDOrder(root);
        cout << endl;
    }

    // Build a balanced BST from sorted array
    void buildBalancedBST(vector<int> &sortedArr)
    {
        root = sortedToBST(sortedArr, 0, sortedArr.size() - 1);
    }

    // Validate if it's a BST
    bool isValidBST()
    {
        return Validate(root, NULL, NULL);
    }

    // Get height of whole tree
    int getTreeHeight()
    {
        return getHeight(root);
    }
};

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    BST tree;
    tree.buildBST(arr);

    cout << "Inorder (Ascending with heights): ";
    tree.printAscending();

    cout << "Tree Height: " << tree.getTreeHeight() << endl;

    cout << "\nDeleting 5...\n";
    tree.deleteValue(5);

    cout << "Inorder after deletion: ";
    tree.printAscending();

    cout << "Tree Height: " << tree.getTreeHeight() << endl;

    cout << "\nIs valid BST? " << (tree.isValidBST() ? "Yes" : "No") << endl;
    cout << "Searching for 4: " << (tree.search(4) ? "Found" : "Not Found") << endl;

    return 0;
}
