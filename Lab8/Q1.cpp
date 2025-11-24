#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int v) :data(v), left(nullptr), right(nullptr) {}
};

class BST{
private:
    Node *root;
    Node *insert(Node *root, int v){
        if (root ==NULL)
            return new Node(v);

        if (v< root->data)
            root->left =insert(root->left, v);
        else
            root->right= insert(root->right, v);
        return root;
    }

    void inOrder(Node *root){
        if (root== NULL)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void preOrder(Node *root){
        if (root== NULL)
            return;
        cout<< root->data<< " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(Node *root){
        if (root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    Node *search(Node *root, int key){
        if (!root)
            return NULL;
        if (root->data ==key)
            return root;
        else if (key< root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    Node *InSuccessor(Node *root){
    while (!root && !root->left)
        root =root->left;
    return root;
}
Node *delNode(Node *root, int key){
    if (!root)
        return NULL;
    if (key< root->data){
        root->left =delNode(root->left, key);
    }
    else if (key >root->data){
        root->right =delNode(root->right, key);
    }
    else{
        if (root->left== NULL){
            Node *temp= root->right;
            delete root;
            return temp;
        }
        else if (root->right== NULL){
            Node *temp =root->left;
            delete root;
            return temp;
        }
        else{
            Node *IS= InSuccessor(root->right);
            root->data =IS->data;
            root->right =delNode(root->right, IS->data);
        }
    }
    return root;
}

public:
    BST() : root(nullptr) {}
    void buildBST(vector<int> &arr){
        root = nullptr;
        for (int i :arr)
            root= insert(root, i);
    }
    void insert(int val){
        root= insert(root, val);
    }
    void deleteValue(int val){
        root= delNode(root, val);
    }
    bool search(int val){
        return search(root, val) != NULL;
    }
    void printInOrder(){
        inOrder(root);
        cout << endl;
    }
    void printPreOrder(){
        preOrder(root);
        cout << endl;
    }
    void printPostOrder(){
        postOrder(root);
        cout << endl;
    }
};

int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    BST tree;
    tree.buildBST(arr);

    cout << "Preorder Traversal: ";
    tree.printPreOrder();
    cout << "Postorder Traversal: ";
    tree.printPostOrder();
    cout << "Inorder Traversal: ";
    tree.printInOrder();

    cout << "\nDeleting 5...\n";
    tree.deleteValue(5);

    cout << "Inorder after deletion: ";
    tree.printInOrder();
    cout << "Searching for 4: " << (tree.search(4) ? "Found" : "Not Found") << endl;

    return 0;
}
