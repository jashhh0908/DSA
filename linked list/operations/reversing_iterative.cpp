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

Node *reverse() {
    Node *prev = nullptr, *current = head, *front = nullptr;

    while(current != nullptr) {
        front = current->next; //saving rest of the linked list after the node 
        current->next = prev; //flipping the arrow of the node to point to the previous node
        prev = current; //becomes the front of the reversed part 
        current = front; //move it forward to the next node to process rest of the list
    }
    return prev; //prev is the head of the linked list  
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
        cout << "--Original List--\n";
        print();

        head = reverse();

        cout << "\n--Reversed List--\n";
        print();
    }
    else {
        cout << "List is empty";
    }
}
