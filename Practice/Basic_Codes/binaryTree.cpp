#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};
class SNode
{
public:
    string data;
    SNode *left;
    SNode *right;
    SNode(string v) : data(v), left(nullptr), right(nullptr) {}
};

static int preidx = -1;
Node *buildPreOrder(vector<int> &preOrder)
{
    preidx++;
    if (preOrder[preidx] == -1)
        return nullptr;
    Node *root = new Node(preOrder[preidx]);
    root->left = buildPreOrder(preOrder);
    root->right = buildPreOrder(preOrder);
    return root;
} // O(n)

void preTreversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preTreversal(root->left);
    preTreversal(root->right);
} // O(n)

void inTreversal(Node *root)
{
    if (root == NULL)
        return;
    inTreversal(root->left);
    cout << root->data << " ";
    inTreversal(root->right);
} // O(n)

void postTreversal(Node *root)
{
    if (root == NULL)
        return;
    postTreversal(root->left);
    postTreversal(root->right);
    cout << root->data << " ";
} // O(n)

void levelTreversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
} // O(n)
void levelLineTreversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
} // O(n)

int diameter = 0;
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    diameter = max(diameter, left + right);
    return max(left, right) + 1;
}

int calcDiameter(Node *root)
{
    height(root);
    return diameter;
}

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

int count(Node *root)
{
    if (root == NULL)
        return 0;
    int left = count(root->left);
    int right = count(root->right);
    return left + right + 1;
} // O(n)

int sumNodes(Node *root)
{
    if (root == NULL)
        return 0;
    int left = sumNodes(root->left);
    int right = sumNodes(root->right);
    return (left + right + root->data);
} // postOrder O(n)

bool identical(Node *root1, Node *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }
    bool left = identical(root1->left, root2->left);
    bool right = identical(root1->right, root2->right);
    return ((left) && (right) && (root1->data == root2->data));
}

bool subTree(Node *mainR, Node *subR)
{
    if (mainR == NULL || subR == NULL)
    {
        return mainR == subR;
    }
    if ((mainR->data == subR->data) && identical(mainR, subR))
    {
        return true;
    }
    return (subTree(mainR->left, subR) || subTree(mainR->right, subR));
}

bool isFullBinaryTree(Node *root)
{
    if (root == nullptr)
        return true;

    // If leaf node, it's full
    if (root->left == nullptr && root->right == nullptr)
        return true;

    // If both left and right exist, check recursively
    if (root->left && root->right)
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);

    // If only one child exists
    return false;
}

bool isCompleteBinaryTree(Node *root)
{
    if (root == nullptr)
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
            // If we found a non-null node after a null one -> not complete
            if (encounteredNull)
                return false;

            q.push(current->left);
            q.push(current->right);
        }
    }

    return true;
}

// Function to check if the given string is an operator
bool isOperator(const string &c)
{
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

// Function to evaluate the expression tree
double evaluate(SNode *root)
{
    if (root == nullptr)
        return 0;

    // If leaf node, it’s a number
    if (!isOperator(root->data))
        return stod(root->data); // convert string to double

    // Evaluate left and right subtrees
    double leftVal = evaluate(root->left);
    double rightVal = evaluate(root->right);

    // Apply the operator
    if (root->data == "+")
        return leftVal + rightVal;
    if (root->data == "-")
        return leftVal - rightVal;
    if (root->data == "*")
        return leftVal * rightVal;
    if (root->data == "/")
        return leftVal / rightVal;

    return 0; // default (should not reach here)
}

int main()
{

    return 0;
}

