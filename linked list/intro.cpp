#include<iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};

Node *head = NULL;

Node *getNode(void){
    return new Node;
}

int main(){
    Node *newNode = getNode();
    head = newNode;
    Node *second = getNode();
    Node *third = getNode();

    head->info = 7;
    head->next = second;

    second->info = 8;
    second->next = third;

    third->info = 9;
    third->next = NULL;

    cout << "Printing linked list: ";
    Node *temp = head;
    while(temp != NULL){
        cout << " " << temp->info;
        temp = temp->next;
    }

    delete head;
    delete second;
    delete third;
    
    return 0;
}