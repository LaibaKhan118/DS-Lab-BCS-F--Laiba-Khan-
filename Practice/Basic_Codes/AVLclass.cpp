#include <iostream>
using namespace std;

class AVL
{
private:
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;
        int height;
        Node(int k) : data(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node *root;

    // --- Utility Functions ---
    int getHeight(Node *n)
    {
        return (n == nullptr) ? 0 : n->height;
    }

    int getBalance(Node *n)
    {
        return (n == nullptr) ? 0 : getHeight(n->left) - getHeight(n->right);
    }

    Node *rightRotate(Node *p)
    {
        Node *c = p->left;
        Node *T2 = c->right;

        c->right = p;
        p->left = T2;

        p->height = 1 + max(getHeight(p->left), getHeight(p->right));
        c->height = 1 + max(getHeight(c->left), getHeight(c->right));

        return c;
    }

    Node *leftRotate(Node *p)
    {
        Node *c = p->right;
        Node *T2 = c->left;

        c->left = p;
        p->right = T2;

        p->height = 1 + max(getHeight(p->left), getHeight(p->right));
        c->height = 1 + max(getHeight(c->left), getHeight(c->right));

        return c;
    }

    // --- Core Operations ---
    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node; // no duplicates

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        // Right Right
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        // Left Right
        if (balance > 1 && key > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left
        if (balance < -1 && key < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *getMin(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node *deleteNode(Node *node, int key)
    {
        if (node == nullptr)
            return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }
            else
            {
                Node *temp = getMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr)
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        // Balancing Cases
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVL() : root(nullptr) {}

    void insert(int key)
    {
        root = insert(root, key);
    }

    void remove(int key)
    {
        root = deleteNode(root, key);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder traversal of AVL tree: ";
    tree.display();

    tree.remove(40);
    cout << "After deleting 40: ";
    tree.display();

    return 0;
}

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