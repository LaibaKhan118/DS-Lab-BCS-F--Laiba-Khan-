#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int k) :data(k), left(nullptr), right(nullptr), height(1) {}
};
Node *rotateRight(Node *y){
    Node *x =y->left;
    Node *t2= x->right;
    x->right= y;
    y->left= t2;
    return x;
}

Node *rotateLeft(Node *x){
    Node *y = x->right;
    Node *t2= y->left;
    y->left =x;
    x->right =t2;
    return y;
}

int height(Node *n){
    if (!n) { return 0; }
    return 1 +max(height(n->left), height(n->right));
}

int getBalance(Node *n){
    return height(n->left)-height(n->right);
}

Node *convertToAVL(Node *root){
    if (!root) { return nullptr; }
    root->left =convertToAVL(root->left);
    root->right =convertToAVL(root->right);
    int balance= getBalance(root);

    if (balance>1){
        if (getBalance(root->left) <0)
            root->left =rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance< -1){
        if (getBalance(root->right) >0)
            root->right =rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

int main()
{

    return 0;
}

/*
Q: Why AVL?
A: AVL trees maintain strict height balance and prevent the BST from becoming skewed, keeping operations efficient even in the worst case.

Q: How nodes are linked
A: When calling convertToAVL(root), recursion rebuilds the tree bottom-up, returning balanced subtrees.
After left and right subtree conversions, the function checks the balance factor and performs rotations if required.

Q: Temporary pointers used in rotations
A:
x → child node that becomes the new root after rotation.
y → original unbalanced parent node.
t2 → the subtree that must be reattached during rotation to preserve BST structure.

Q: Correspondence to original nodes (Tree A example)
A: If 0010 becomes unbalanced (left-heavy),
y = 0010,
x = 0008 (left child of 0010),
t2 = x->right (the right subtree of 0008).

Q: Type of rotation
A:
Tree A is Left-heavy so Right Rotation (LL case).
Tree B is Already height-balanced so No rotation needed, already AVL.

Q: What node is returned and why (3–4 lines)
A: The conversion function always returns the new root of the (sub)tree.
If a rotation occurs, the rotated node (x for right rotation or y for left rotation) becomes the updated root.
This root is returned upward to correctly rebuild parent links.
Thus, the tree remains fully balanced from bottom to top.
*/
