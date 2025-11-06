#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

Node* getNode() {
    return new Node;
}

int search(int target, int n) {
    int i = 1;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->info == target) {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}

int main() {
    int i, n, x;
    cout << "Enter no of elements: ";
    cin >> n;
    cout << "Enter values: ";
    int a = n;
    while (a--) {
        cin >> x;
        Node *nn = getNode();
        nn->info = x;
        nn->next = NULL;
        if (head == NULL) {
            head = tail = nn;
        } else {
            tail->next = nn;
            tail = nn;
        }
    }
    int target;
    cout << "Enter target value: ";
    cin >> target;

    int flag = search(target, n);
    if (flag != -1) {
        cout << "Element found at: " << flag;
    } else {
        cout << "Element not found";
    }
    return 0;
}
