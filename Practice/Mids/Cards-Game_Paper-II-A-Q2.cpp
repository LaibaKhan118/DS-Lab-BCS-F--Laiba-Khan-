#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Card {
    public:
    int rank;
    char suit;

    Card() {}
    Card(int r, char s): rank(r), suit(s){}

    void displayCard() {
        cout << ((rank==11)? "J" : (rank==12)? "Q" : (rank==13)? "K" : (rank==14)? "A" : to_string(rank)) << "-" << suit;
    }
};

Card generateRandom() {
    int rank = rand()%13+2;
    char s[] = {'h', 's', 'c', 'd'};
    char suit = s[rand()%4];
    return Card(rank, suit);
}

class Node {
    public:
    Card data;
    Node* next;

    Node(Card d) {
        data = d;
        next = nullptr;
    }
};

class Linkedlist {
    private:
    Node* head;

    public:
    Linkedlist() { head = nullptr; }
    ~Linkedlist() {
        Node* temp = head;
        while(temp) {
            Node* n = temp->next;
            delete temp;
            temp = n;
        }
        head = nullptr;
    }
    void insert(Card c) {
        Node* n = new Node(c);
        if(!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = n;
    }

    Card playCard() {
        if(!head) {
            cout << "No cards Left!" << endl; 
            return Card(-1, 'x');
        }
        Node* temp = head;
        Card c = temp->data;
        head = head->next;
        delete temp;
        return c;
    }

    bool isEmpty() {
        if(!head) return true;
        return false;
    }

    void DisplayHand() {
        if(!head) return;
        Node* temp = head;
        while(temp) {
            temp->data.displayCard();
            if(temp->next) cout << " -> ";
            temp = temp->next;
        }
    }
};

int main()
{
    srand(time(0));
    Linkedlist player1;
    Linkedlist player2;

    for (int i = 0; i < 5; i++)
    {
        player1.insert(generateRandom());
        player2.insert(generateRandom());
    }

    cout << "Player 1 initial hand: ";
    player1.DisplayHand();
    cout << endl;
    cout << "Player 2 initial hand: ";
    player2.DisplayHand();

    cout << "\n--- GAME START ---\n";
    
    bool player1Turn = true;

    while(!player1.isEmpty() && !player2.isEmpty()) {
        Card c1 = player1.playCard();
        Card c2 = player2.playCard();

        cout << "\nPlayer 1 played: ";
        c1.displayCard();
        cout << "\nPlayer 2 played: ";
        c2.displayCard();

        if(player1Turn){
            cout << "\n\nPlayer 1 played first:" << endl;
            if (c1.suit == c2.suit) {
                if(c1.rank > c2.rank) {
                    cout << "Player 1 wins this round!" << endl;
                    player1.insert(c1);
                    player1.insert(c2);
                    player1Turn = true;
                }
                else {
                    cout << "Player 2 wins this round!" << endl;
                    player2.insert(c1);
                    player2.insert(c2);
                    player1Turn = false; 
                }
            }
            else {
                cout << "Different suit! Both cards go to player 1" << endl;
                player1.insert(c1);
                player1.insert(c2);
                player1Turn = true;
            }
        }
        else {
            cout << "\n\nPlayer 2 played first:" << endl;
            if (c2.suit == c1.suit) {
                if(c2.rank > c1.rank) {
                    cout << "Player 2 wins this round!" << endl;
                    player2.insert(c1);
                    player2.insert(c2);
                    player1Turn = false;
                }
                else {
                    cout << "Player 1 wins this round!" << endl;
                    player1.insert(c1);
                    player1.insert(c2);
                    player1Turn = true;
                }
            }
            else {
                cout << "Different suit! Both cards go to player 2" << endl;
                player2.insert(c1);
                player2.insert(c2);
                player1Turn = false;
            }
        }
        cout << "\nPlayer 1 cards left: ";
        player1.DisplayHand();
        cout << endl;
        cout << "Player 2 cards left: ";
        player2.DisplayHand();
    }

    if(player1.isEmpty()) {
        cout << "\n\n Player 1 WINS!!" << endl;
    }
    else {
        cout << "\n\n Player 2 WINS!!" << endl;
    }
    return 0;
}