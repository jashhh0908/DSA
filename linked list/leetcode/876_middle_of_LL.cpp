//easy difficulty
//return LL after middle node 
//optimal approach using tortoise hare method
#include<iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};

Node* head = nullptr;
Node* tail = nullptr;

Node* getNode(){
    return new Node;
}

Node* middleNode(Node* head){
    Node *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr) { //tortoise hare algo
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print(Node *temp){
    cout << "OUTPUT:";
    while(temp != NULL){
        cout << " " << temp->info;
        temp = temp->next;
    }
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
    Node *temp = middleNode(head);
    print(temp);
}