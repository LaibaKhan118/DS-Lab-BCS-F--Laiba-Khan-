#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class BinTree
{
private:
    int diameter;
    int preidx;

    Node *buildPreOrderHelper(vector<int> &preOrder)
    {
        preidx++;
        if (preOrder[preidx] == -1)
            return nullptr;
        Node *root = new Node(preOrder[preidx]);
        root->left = buildPreOrderHelper(preOrder);
        root->right = buildPreOrderHelper(preOrder);
        return root;
    }

    int heightHelper(Node *root)
    {
        if (root == nullptr)
            return 0;
        int left = heightHelper(root->left);
        int right = heightHelper(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }

    bool identical(Node *root1, Node *root2)
    {
        if (root1 == nullptr || root2 == nullptr)
            return root1 == root2;
        bool left = identical(root1->left, root2->left);
        bool right = identical(root1->right, root2->right);
        return left && right && (root1->data == root2->data);
    }

public:
    Node *root;

    BinTree()
    {
        root = nullptr;
        diameter = 0;
        preidx = -1;
    }

    // Build tree from preorder (using -1 for nulls)
    Node *buildPreOrder(vector<int> &preOrder)
    {
        preidx = -1;
        root = buildPreOrderHelper(preOrder);
        return root;
    }

    // Traversals
    void preTraversal(Node *root)
    {
        if (!root)
            return;
        cout << root->data << " ";
        preTraversal(root->left);
        preTraversal(root->right);
    }

    void inTraversal(Node *root)
    {
        if (!root)
            return;
        inTraversal(root->left);
        cout << root->data << " ";
        inTraversal(root->right);
    }

    void postTraversal(Node *root)
    {
        if (!root)
            return;
        postTraversal(root->left);
        postTraversal(root->right);
        cout << root->data << " ";
    }

    void levelTraversal(Node *root)
    {
        if (!root)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }

    void levelLineTraversal(Node *root)
    {
        if (!root)
            return;
        queue<Node *> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr == nullptr)
            {
                if (!q.empty())
                {
                    cout << endl;
                    q.push(nullptr);
                }
            }
            else
            {
                cout << curr->data << " ";
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        cout << endl;
    }

    // Height and Diameter
    int height(Node *root) { return heightHelper(root); }
    int calcDiameter(Node *root)
    {
        diameter = 0;
        heightHelper(root);
        return diameter;
    }

    // Depth of a given key
    int depth(Node *root, int key, int currentDepth = 0)
    {
        if (root == nullptr)
            return -1;
        if (root->data == key)
            return currentDepth;
        int left = depth(root->left, key, currentDepth + 1);
        if (left != -1)
            return left;
        return depth(root->right, key, currentDepth + 1);
    }

    // Count and sum of nodes
    int count(Node *root)
    {
        if (!root)
            return 0;
        return 1 + count(root->left) + count(root->right);
    }

    int sumNodes(Node *root)
    {
        if (!root)
            return 0;
        return root->data + sumNodes(root->left) + sumNodes(root->right);
    }

    // Subtree check
    bool subTree(Node *mainR, Node *subR)
    {
        if (mainR == nullptr || subR == nullptr)
            return mainR == subR;
        if (mainR->data == subR->data && identical(mainR, subR))
            return true;
        return subTree(mainR->left, subR) || subTree(mainR->right, subR);
    }

    // Check if Full Binary Tree
    bool isFullBinaryTree(Node *root)
    {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        if (root->left && root->right)
            return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
        return false;
    }

    // Check if Complete Binary Tree
    bool isCompleteBinaryTree(Node *root)
    {
        if (!root)
            return true;
        queue<Node *> q;
        q.push(root);
        bool encounteredNull = false;

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            if (current == nullptr)
            {
                encounteredNull = true;
            }
            else
            {
                if (encounteredNull)
                    return false;
                q.push(current->left);
                q.push(current->right);
            }
        }
        return true;
    }
};

int main()
{
    BinTree tree;
    vector<int> preOrder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    tree.buildPreOrder(preOrder);

    cout << "Preorder: ";
    tree.preTraversal(tree.root);
    cout << "\nInorder: ";
    tree.inTraversal(tree.root);
    cout << "\nPostorder: ";
    tree.postTraversal(tree.root);
    cout << "\nLevel Order: ";
    tree.levelTraversal(tree.root);
    cout << "Level by Line:\n";
    tree.levelLineTraversal(tree.root);

    cout << "\nHeight: " << tree.height(tree.root);
    cout << "\nDiameter: " << tree.calcDiameter(tree.root);
    cout << "\nCount: " << tree.count(tree.root);
    cout << "\nSum: " << tree.sumNodes(tree.root);
    cout << "\nDepth of 5: " << tree.depth(tree.root, 5);
    cout << "\nIs Full Binary Tree? " << (tree.isFullBinaryTree(tree.root) ? "Yes" : "No");
    cout << "\nIs Complete Binary Tree? " << (tree.isCompleteBinaryTree(tree.root) ? "Yes" : "No") << endl;

    return 0;
}
