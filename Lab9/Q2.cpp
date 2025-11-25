#include <iostream>
using namespace std;

class AVL
{
private:
    class Node{
    public:
        int data;
        Node *left;
        Node *right;
        int height;
        Node(int k) :data(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node *root;
    int getHeight(Node *n){
        return (n == nullptr) ? 0 :n->height;
    }

    int getBalance(Node *n){
        return (n == nullptr) ? 0 :getHeight(n->left) - getHeight(n->right);
    }

    Node *rightRotate(Node *p){
        Node *c =p->left;
        Node *T2 = c->right;
        c->right= p;
        p->left= T2;
        p->height =1 +max(getHeight(p->left), getHeight(p->right));
        c->height= 1 +max(getHeight(c->left), getHeight(c->right));
        return c;
    }

    Node *leftRotate(Node *p){
        Node *c =p->right;
        Node *T2= c->left;
        c->left= p;
        p->right= T2;
        p->height =1 +max(getHeight(p->left), getHeight(p->right));
        c->height = 1+max(getHeight(c->left), getHeight(c->right));
        return c;
    }

    Node *insert(Node *node, int key){
        if (node== nullptr)
            return new Node(key);

        if (key<node->data)
            node->left= insert(node->left, key);
        else if (key >node->data)
            node->right =insert(node->right, key);
        else
            return node; 
            
        node->height =1 +max(getHeight(node->left), getHeight(node->right));

        int balance =getBalance(node);
        if (balance >1 && key< node->left->data)
            return rightRotate(node);

        if (balance< -1 && key> node->right->data)
            return leftRotate(node);

        if (balance >1 && key >node->left->data)
        {
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance <-1 && key< node->right->data)
        {
            node->right =rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    void inorder(Node *node){
        if (node==nullptr)
            return;
        inorder(node->left);
        cout<< node->data << " ";
        inorder(node->right);
    }

public:
    AVL() : root(nullptr) {}

    void insert(int key){
        root = insert(root, key);
    }

    void display(){
        inorder(root);
        cout << endl;
    }
};

int main(){
    AVL tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal of AVL tree: ";
    tree.display();

    cout << "\nInserting 55..." << endl;
    tree.insert(55);

    cout << "Inorder traversal of AVL tree: ";
    tree.display();
}
