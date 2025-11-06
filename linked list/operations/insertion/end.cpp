#include<iostream>
using namespace std;

struct Node{
    int info;
    Node* next; 
};

Node* head = NULL;
Node* tail = NULL;

Node* getNode(){
    return new Node;
}

void print(){
    Node* temp = head;
    cout << "Printing list:";
    while(temp != NULL){
        cout << " " << temp->info;
        temp = temp->next;
    }
}

void insertEnd(){
    Node *newVal = getNode();
    cout << "\nEnter value to be inserted at the end: ";
    cin >> newVal->info;
    newVal->next = NULL;
    if (head == NULL){
        head = newVal;
        tail = newVal;
    }
    else{
        tail->next = newVal;
        tail = newVal;
    }
}

void freeList(){
    Node *temp = head;
    while(temp != NULL){
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}
int main(){
    int i, n;
    cout << "Enter no of elements: ";
    cin >> n;
    if(n != 0){
        cout << "Enter values: ";
        for(i = 0; i < n; i++){
            int x;
            cin >> x;
            Node* newNode = getNode();
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
    cout << "\n--List--\n";
    print();

    insertEnd();

    cout << "--New List--\n";
    print();

    freeList();
    return 0;
}
