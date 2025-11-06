#include<iostream>
using namespace std;

struct Node { 
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
    if(head == nullptr) {
        cout << "List is empty";
        return;
    }
    while(temp != nullptr) {
        cout << " " << temp->info;
        temp = temp->next;
    }
    cout << "\n";
}

void del() {
    if(head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node *temp = head;
    while(temp->next != tail) {
        temp = temp->next;
    }
    temp->next = nullptr;
    delete tail;
    tail = temp;    
}

int main() {
    int i, n, x;
    cout << "Enter no of elements: ";
    cin >> n;
    if(n != 0) {
        int a = n;
        cout << "Enter values: ";
        while(a--){
            cin >> x;
            Node *nn = getNode();
            nn->info = x;
            nn->next = nullptr;

            if(head == nullptr) {
                head = nn;
                tail = nn;
            }
            else {
                tail->next = nn;
                tail = nn;
            }
        }

        cout << "--Original List--\n";
        print();

        del();
        cout << "--New List--\n";
        print();
    }
    else {
        cout << "List is empty, nothing to delete.";
    }
    return 0;
}

