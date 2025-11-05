#include <iostream>
using namespace std;

// Algo:
/*
1. Insert node n normally.
2. Starting from that node, check if that node is making the tree unbalanced, i.e., The difference between the height of the left side of that node and the right side of that node is either -1, 0, or 1. If n is not unbalanced, then to the previous (parent) node and check for balance. (bottom up)
3. Once an unbalanced node is found. Use one of the four rules to rotate it.
RULES:
1. Left-Left case: Both the child and grandchild are oon the left of the parent.
    - Rotate parent to the right:
        - The Child becomes root, parent becomes root's right, and child's right becomes parent's left.
2. Right-Left Case: Child is on the left of parent and grandchild is on the left of that child.
    - Rotate the child to the Left
        - The grandchild becomes left child of parent, child becomes the left of the grandchild, the original left of the grandchild(new left child) will become the right of the child(the new grandchild)
    - Rotate the parent (unbalanced node) to the right
        - The Child becomes root, parent becomes root's right, and child's right becomes parent's left.
3. Right-Right case: the child and grandchild are on the right side of the unbalanced node.
    - Rotate the parent to the Left:
        - The Child becomes root, parent becomes root's left, and child's left becomes parent's right.
4. Right-Left case: The child is on the right on the unbalanced parent, and the grandchild is on the left of that child.
    - Rotate the child to the left:
        - The grandchild becomes right child of parent, child becomes the right of the grandchild, the original right of the grandchild(new right child) will become the left of the child(the new grandchild)
    - Rotate the parent (unbalanced node) to the left:
        - The Child becomes root, parent becomes root's left, and child's left becomes parent's right.
*/

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int k) : data(k), left(nullptr), right(nullptr), height(1) {}
};

// Get height of a node
int getHeight(Node *n)
{
    return (n == nullptr) ? 0 : n->height;
}

// Get balance factor
int getBalance(Node *n)
{
    if (n == nullptr)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Right rotate
Node *rightRotate(Node *p)
{
    Node *c = p->left;
    Node *T2 = c->right;

    c->right = p;
    p->left = T2;

    // Update heights
    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
    c->height = max(getHeight(c->left), getHeight(c->right)) + 1;

    return c;
}

// Left rotate
Node *leftRotate(Node *p)
{
    Node *c = p->right;
    Node *T2 = c->left;

    c->left = p;
    p->right = T2;

    // Update heights
    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
    c->height = max(getHeight(c->left), getHeight(c->right)) + 1;

    return c;
}

// Insert into AVL tree
Node *insert(Node *root, int key)
{
    // 1. Normal BST insert
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // no duplicates

    // 2. Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Get balance factor
    int balance = getBalance(root);

    // 4. Perform rotations

    // Left Left Case
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal (sorted order)
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Get minimum node (used in deletion)
Node *getMin(Node *root)
{
    Node *current = root;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Delete node from AVL
Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return root;

    // Normal BST deletion
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
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
            Node *IS = getMin(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        }
    }

    // If only one node
    if (root == nullptr)
        return root;

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balance
    int balance = getBalance(root);

    // 4 rotation cases
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Main function
int main()
{
    Node *root = nullptr;

    // Insert values
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of AVL tree: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 40);
    cout << "After deleting 40: ";
    inorder(root);
    cout << endl;

    return 0;
}