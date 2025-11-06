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

void del(int pos, int n) {
    Node *temp = head;
    if(pos == 1) {
        head = head->next;
        delete temp;
        return;
    }
    else if(pos > n) {
        cout << "INVALID INDEX";
    }
    else {
        int i;
        for(i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node *node_to_delete = temp->next;
        temp->next = node_to_delete->next;
        if(node_to_delete == tail)
            tail = temp;
        delete node_to_delete;

    }
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
        int pos;
        cout << "Enter position to delete: ";
        cin >> pos;

        cout << "--Original List--\n";
        print();
        del(pos, n);
        cout << "--New List--\n";
        print();
    }
    else {
        cout << "List is empty, nothing to delete.";
    }
    return 0;
}

