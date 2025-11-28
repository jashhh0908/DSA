#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *getNode() {
    return (struct Node*)malloc(sizeof(struct Node));
}

//main function 
struct Node *create(struct Node *head, int val) {
    if(head == NULL) {
        head = getNode();
        head->data = val;
        head->next = head->prev = NULL;
        return head;
    }
    struct Node *newNode = getNode();
    newNode->data = val;
    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }   
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
    return head;
}

void display(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    //user-input
    struct Node *head = NULL;
    int val = 0;
    while(val != -1) {
        printf("enter a value (-1 to stop): ");
        scanf("%d", &val);
        if(val == -1)
            break;
        else {
            head = create(head, val);
        }
    }

    printf("Printing LL: "); //4 2 1 0
    display(head);

    //hard-coded
    /*
    struct Node *head = getNode();
    struct Node *second = getNode();
    struct Node *third = getNode();
    struct Node *fourth = getNode();
    
    head->data = 4;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 1;
    third->prev = second;
    third->next = fourth;

    fourth->data = 0;
    fourth->prev = third;
    fourth->next = NULL;
    */
    return 0;
}