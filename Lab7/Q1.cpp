#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node
{
    string name;
    int score;
    Node *next;
    Node(string n, int s):name(n), score(s), next(NULL){}
};

void addNode(Node *&head, string name, int score){
    Node *newNode = new Node(name,score);
    newNode->next=head;
    head =newNode;
}

void display(Node *head){
    while (head){
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int getMaxScore(Node *head)
{
    int mx = 0;
    while (head){
        if (head->score > mx)
            mx = head->score;
        head = head->next;
    } return mx;
}

void radixSort(Node *&head){
    if (!head) { return; }

    int maxScore = getMaxScore(head);

    for (int exp = 1; maxScore / exp > 0; exp *= 10){
        Node *buckets[10] = {NULL};
        Node *bucketTails[10] = {NULL};
        Node *curr = head;
        while (curr){
            int digit = (curr->score / exp) % 10;
            if (!buckets[digit]){
                buckets[digit] = bucketTails[digit] = curr;
            }
            else{
                bucketTails[digit]->next = curr;
                bucketTails[digit] = curr;
            }
            curr = curr->next;
        }

        Node *newHead = NULL;
        Node *newTail = NULL;

        for (int i = 0; i < 10; i++){
            if (buckets[i]){
                if (!newHead){
                    newHead = buckets[i];
                    newTail = bucketTails[i];
                }
                else{
                    newTail->next = buckets[i];
                    newTail = bucketTails[i];
                }
            }
        }
        newTail->next = NULL;
        head = newHead;
    }
}

int listLength(Node *head){
    int count = 0;
    while (head){
        head = head->next;
        count++;
    }
    return count;
}

void buildPointerArray(Node *head, Node **arr){
    int i = 0;
    while (head){
        arr[i++] = head;
        head = head->next;
    }
}

int binarySearch(Node **arr, int size, string name, int score)
{
    int left = 0, right = size - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (arr[mid]->score == score){
            if (arr[mid]->name == name)
                return mid;
            int i = mid - 1;
            while (i >= 0 && arr[i]->score == score){
                if (arr[i]->name == name) { return i; }
                i--;
            }
            i = mid + 1;
            while (i < size && arr[i]->score == score){
                if (arr[i]->name == name)
                    return i;
                i++;
            }
            return -1;
        }
        else if (arr[mid]->score < score)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void deleteNode(Node *&head, string name, int score)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr){
        if (curr->name == name && curr->score == score){
            if (prev)
                prev->next = curr->next;
            else
                head = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main()
{
    Node *head = NULL;
    addNode(head, "Ayan", 90);
    addNode(head, "Zameer", 60);
    addNode(head, "Sara", 70);
    addNode(head, "Sohail", 30);
    addNode(head, "Ahmed", 20);
    radixSort(head);

    cout << "Sorted List:" << endl;
    display(head);

    string name;
    int score;

    cout << "\nEnter name to search: ";
    cin >> name;
    cout << "Enter score: ";
    cin >> score;

    int n = listLength(head);
    Node **arr = new Node *[n];
    buildPointerArray(head, arr);

    int index = binarySearch(arr, n, name, score);

    if (index != -1)
    {
        cout << "\nRecord found. Deleting...\n";
        deleteNode(head, name, score);
    }
    else
    {
        cout << "\nRecord NOT found.\n";
    }

    cout << "\nUpdated List:\n";
    display(head);

    delete[] arr;
    return 0;
}
