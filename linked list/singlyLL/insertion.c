#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *getNode(void) {
    return (struct Node*)malloc(sizeof(struct Node));
}

struct Node *insertBeg(struct Node *head, int x) {
    struct Node *newNode = getNode();
    newNode->data = x;
    newNode->next = head;
    return newNode;
}

struct Node *insertEnd(struct Node *head, int x) {
    struct Node *newNode = getNode();
    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node *insertBetween(struct Node *head, int x, int pos) {
    if(pos == 1)
        return insertBeg(head, x);

    struct Node *newNode = getNode();
    newNode->data = x;
    newNode->next = NULL;

    struct Node *current = head, *previous = NULL;

    for(int i = 1; i < pos; i++) {
        previous = current;
        current = current->next;
        if(current == NULL) {
            printf("Out of bounds\n");
            free(newNode);
            return head;
        }
    }

    newNode->next = current;
    previous->next = newNode;
    return head;
}

void display(struct Node *head) {
    if(head == NULL) {
        printf("Empty list\n");
        return;
    }
    printf("List: ");
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    head = insertBeg(head, 3);
    head = insertBeg(head, 2);
    head = insertBeg(head, 1);

    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    head = insertBetween(head, 99, 3);   // insert at position 3

    display(head);

    return 0;
}