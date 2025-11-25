#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node{
public:
    int id;
    string name;
    int hp;
    int ap;
    Node *left;
    Node *right;

    Node(int i, string n, int h, int a): id(i), name(n), hp(h), ap(a), left(nullptr), right(nullptr) {}
};

class BST{
private:
    Node *root;
    Node *InSuccessor(Node *root){
        while (root && root->left)
            root =root->left;
        return root;
    }
    void inOrder(Node *root){
        if (!root)
            return;
        inOrder(root->left);
        cout << "\n ID: " << root->id << ", Name: " << root->name<< ", HP: " << root->hp << ", AP: " << root->ap;
        inOrder(root->right);
    }

public:
    BST() : root(nullptr) {}
    Node *insert(Node *root, int i, string n, int h, int a){
        if (!root)
            return new Node(i, n, h, a);

        if (i < root->id)
            root->left = insert(root->left, i, n, h, a);
        else if (i > root->id)
            root->right = insert(root->right, i, n, h, a);

        return root;
    }
    void insert(int i, string n, int h, int a){
        root = insert(root, i, n, h, a);
    }

    Node *delNode(Node *root, int key){
        if (!root)
            return nullptr;

        if (key < root->id)
            root->left = delNode(root->left, key);
        else if (key > root->id)
            root->right = delNode(root->right, key);
        else{
            if (!root->left){
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right){
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else{
                Node *IS = InSuccessor(root->right);
                root->id = IS->id;
                root->name = IS->name;
                root->hp = IS->hp;
                root->ap = IS->ap;
                root->right = delNode(root->right, IS->id);
            }
        }
        return root;
    }

    void deleteByID(int id){
        root = delNode(root, id);
    }
    Node *getRoot() { return root; }

    void updateHP(Node *fighter, int newHP){
        if (fighter)
            fighter->hp = newHP;
    }

    Node *getFrontline()
    {
        Node *temp =root;
        if (!temp)
            return nullptr;
        while (temp->left)
            temp =temp->left;
        return temp;
    }

    void printTeam(){
        if (!root){
            cout <<"\n(Empty Team)";
            return;
        }
        inOrder(root);
        cout << endl;
    }
};

void battleRound(BST &player, BST &enemy, int round)
{
    cout << "\n==============================";
    cout <<"\n          ROUND " <<round;
    cout<< "\n==============================\n";

    cout<< "\n--- PLAYER TEAM ---";
    player.printTeam();
    cout <<"\n--- ENEMY TEAM ---";
    enemy.printTeam();
    cout<< endl;

    Node *p =player.getFrontline();
    Node *e = enemy.getFrontline();

    if (!p || !e) { return; }

    cout<< "\nPlayer frontline: "<< p->name<<" (HP: " <<p->hp<< ")";
    cout <<"\nEnemy frontline: " <<e->name <<" (HP: " <<e->hp <<")\n";

    // Player attacks first
    int dmg1 =p->ap +(rand() % 5);
    e->hp -=dmg1;

    cout << "\nPlayer "<< p->name <<" attacks " <<e->name<< " for " << dmg1 << " damage!\n";

    if (e->hp<= 0){
        cout << "Enemy "<< e->name <<" is defeated!\n";
        enemy.deleteByID(e->id);
        return;
    }

    int dmg2 =e->ap +(rand() % 5);
    p->hp -=dmg2;

    cout <<"Enemy " <<e->name << " counters for "<< dmg2 << " damage!\n";

    if (p->hp <= 0)
    {
        cout<< "💀 Player " << p->name << " is defeated!\n";
        player.deleteByID(p->id);
    }
}

void startBattle(BST &player, BST &enemy)
{
    int round = 1;
    while (player.getRoot() && enemy.getRoot())
    {
        battleRound(player, enemy, round);
        round++;
    }

    if (!enemy.getRoot())
        cout << "\nPLAYER WINS THE BATTLE!!\n";
    else
        cout << "\nENEMIES WIN THE BATTLE!!\n";
}

int main()
{
    srand(time(NULL));

    BST player;
    BST enemy;

    player.insert(10, "Knight", 45, 8);
    player.insert(5, "Archer", 30, 7);
    player.insert(15, "Mage", 25, 10);
    player.insert(3, "Paladin", 50, 6);
    player.insert(8, "Rogue", 28, 9);

    enemy.insert(12, "Goblin", 22, 5);
    enemy.insert(6, "Orc", 35, 8);
    enemy.insert(18, "Dark Mage", 30, 9);
    enemy.insert(1, "Skeleton", 20, 4);
    enemy.insert(9, "Troll", 55, 7);

    cout << "\n== BATTLE BEGINS NOW ==\n";

    startBattle(player, enemy);

    return 0;
}
