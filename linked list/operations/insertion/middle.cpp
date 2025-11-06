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
    while(temp != NULL){
        cout << " " << temp->info;
        temp = temp->next;
    }
}

void freeList(){
    Node *temp = head;
    while(temp != NULL){
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
        cout << "Enter values: ";
        while(a--){
            cin >> x;
            Node *newNode = getNode();
            newNode->info = x;
            newNode->next = NULL;

            if(head == NULL){
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    Node *newVal = getNode();
    int pos;
    cout << "Enter value to be inserted: ";
    cin >> newVal->info;
    cout << "Enter position: ";
    cin >> pos;

    if(pos == 1){ //at the beginning
        cout << "\n--Original List--\n";
        print();
        if(head == NULL) {
            newVal->next = head;
            head = newVal;
            tail = newVal;    
        }
        else{
            newVal->next = head;
            head = newVal;
        }
        cout << "\n--New List--\n";
        print();
    }
    else if(pos == n + 1){ //at the end 
        cout << "\n--Original List--\n";
        print();
        newVal->next = NULL;
        tail->next = newVal;
        tail = newVal;
        cout << "\n--New List--\n";
        print();
    }
    else if(pos > n + 1){ //out of bounds
        printf("\nINVALID INDEX");
    }
    else{ //middle of the list
        cout << "\n--Original List--\n";
        print();
        Node *temp = head;
        for(i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        newVal->next = temp->next;
        temp->next = newVal;
    
        cout << "\n--New List--\n";
        print();
    }

    freeList();

    return 0;
}