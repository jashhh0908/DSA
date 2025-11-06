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

int main(){
    int i, n;
    cout << "Enter no of elements: ";
    cin >> n;
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

    Node* temp = head;
    cout << "Printing list:";
    while(temp != NULL){
        cout << " " << temp->info;
        temp = temp->next;
    }

    //freeing memory
    temp = head;
    while(temp != NULL){
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}
