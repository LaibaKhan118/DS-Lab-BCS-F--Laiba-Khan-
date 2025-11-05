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

Node *insert(Node *root, int v)
{
    if (root == NULL)
        return (new Node(v));
    if (v < root->data)
    {
        root->left = insert(root->left, v);
    }
    else
    {
        root->right = insert(root->right, v);
    }
    return root;
}

Node *buildBST(vector<int> &arr)
{
    Node *root = nullptr;
    for (int i : arr)
    {
        root = insert(root, i);
    }
    return root;
}

// To print, use inorder Traversal.
// Ascending: (LVR)
void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Descending (use reverse inorder traversal: RVL)
void inDOrder(Node *root)
{
    if (root == NULL)
        return;
    inDOrder(root->right);
    cout << root->data << " ";
    inDOrder(root->left);
}

Node *search(Node *root, int key)
{
    if (!root)
        return NULL;
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
Node *InSuccessor(Node *root)
{
    while (!root && !root->left)
        root = root->left;
    return root;
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

Node *sortedToBST(vector<int> &arr, int st, int end)
{
    if (st > end)
    {
        return NULL;
    }
    int mid = st + (end - st) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sortedToBST(arr, st, mid - 1);
    root->right = sortedToBST(arr, mid + 1, end);
    return root;
}
Node *BalancedBST(vector<int> &arr)
{
    return sortedToBST(arr, 0, arr.size() - 1);
}

bool Validate(Node *root, Node *min, Node *max)
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
} // O(n)
bool isValidBST(Node *root)
{
    return Validate(root, NULL, NULL);
}
int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr);
    inOrder(root);
    cout << endl;
    delNode(root, 5);
    inOrder(root);
    cout << endl;
    return 0;
}