#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

Node *getNode(){
    return new Node;
}

void print() {
    Node *temp = head;
    while (temp != nullptr) {
        cout << " " << temp->info;
        temp = temp->next;
    }
}

Node* reverse(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *newHead = reverse(head->next); //calling it to solve for a shorter list (smaller problem) | This returns the last node as the head after n-1 recursion calls
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main() {
    int i,n,x;
    cout << "Enter no of elements: ";
    cin >> n;
    if(n != 0) {
        int a = n;
        cout << "Enter values: ";
        while(a--) {
            cin >> x;
            Node *nn = getNode();
            nn->info = x;
            nn->next = nullptr;
            if(head == nullptr) {
                head = tail = nn;
            }
            else {
                tail->next = nn;
                tail = nn;
            }
        }
        cout << "\n--Original List--\n";
        print();

        head = reverse(head);

        cout << "\n--Reversed List--\n";
        print();
    }
    else {
        cout << "List is empty";
    }
}
