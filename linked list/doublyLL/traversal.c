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

void display(struct Node *head){
    if(head == NULL) {
        printf("List is empty");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverseDisplay(struct Node *tail) {
    if(tail == NULL) {
        printf("List is empty");
        return;
    }
    struct Node *temp = tail;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main() {
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

    printf("From front: ");
    display(head);
    printf("\nFrom back: ");
    reverseDisplay(fourth);
    return 0;
}