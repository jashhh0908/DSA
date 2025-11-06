#include<iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

Node *getNode(){
    return new Node;
}

void print(){
    Node *temp = head;
    while(temp != NULL) {
        cout << " " << temp->info;
        temp = temp->next;
    }
}

void insertBeg(){
    Node *nn = getNode();
    cout << "Enter value to be inserted at start: ";
    cin >> nn->info;

    cout << "\nOriginal List: ";
    print();

    if(head == NULL){
        nn->next = NULL;
        head = nn;
        tail = nn;
    }
    else{
        nn->next= head;
        head = nn;
    }
    cout << "\nNew List: ";
    print();
}

void insertEnd(){
    Node *nn = getNode();
    cout << "Enter value to be inserted at end: ";
    cin >> nn->info;
    nn->next = NULL;

    cout << "\nOriginal List: ";
    print();

    if(head == NULL){
        head = nn;
        tail = nn;
    }
    else {
        tail->next = nn;
        tail = nn;
    }
    cout << "\nNew List: ";
    print();
}

void insert_at_pos(int n){
    Node *nn = getNode();
    int pos;
    cout << "Enter value: ";
    cin >> nn->info;
    cout << "Enter position: ";
    cin >> pos;

    if(pos > n) {
        cout << "\nINVALID INDEX";
    }
    else {
        cout << "\nOriginal List: ";
        print();
        Node *temp = head;
        int i;
        for (i = 1; i < pos-1; i++){
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;

        cout << "\nNew List: ";
        print();
    }
}

void freeList(){
    Node *temp = head;
    while(temp != NULL) {
        Node *nn = temp->next;
        delete temp;
        temp = nn;
    }
}
int main(){
    int i, n, x;
    cout << "Enter no of elements: ";
    cin >> n;
    if(n != 0){
        int a = n;
        while(a--){
            cout << "Enter values: ";
            cin >> x;
            Node *newNode = getNode();
            newNode->info = x;
            newNode->next = NULL;
            
            if (head == NULL){
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    int ch;
    cout << "\n---Linked List Operations---\n";
    cout << "1 - insert at start \n2 - insert at end \n3 - insert at a position\n";
    cout << "Enter your choice: ";
    cin >> ch;
    switch (ch) {
        case 1: insertBeg();
                break;
        case 2: insertEnd();
                break;
        case 3: insert_at_pos(n);
                break; 
        default: cout << "INVALID INPUT!";
    }

    freeList();
    return 0;
}