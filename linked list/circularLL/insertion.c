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
    newNode->next = NULL;
    if(head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct Node *last = head;
    while(last->next != head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node *insertEnd(struct Node *head, int x) {
    struct Node *newNode = getNode();
    newNode->data = x;
    newNode->next = NULL;
    if(head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct Node *last = head;
    while(last->next != head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = head;
    return head;
}
struct Node *insertBetween(struct Node *head, int x, int pos) {
    if(pos == 1) {
        head = insertBeg(head, x);
        return head;
    }
    struct Node *current = head, *previous = NULL;
    for (int i = 1; i < pos; i++) {
        previous = current;
        current = current->next;
        // came back to head BEFORE reaching position
        if (current == head) {
            if (i == pos - 1) {
                // exactly n+1 → insert at end
                return insertEnd(head, x);
            } else {
                // crossed length → out of bounds
                printf("Out of bounds\n");
                return head;
            }
        }
    }
    struct Node *newNode = getNode();
    newNode->data = x;
    newNode->next = current;
    previous->next = newNode;
    return head;
}

void display(struct Node *head) {
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    printf("List: ");
    struct Node *temp = head;
    printf("%d ", temp->data);
    temp = temp->next;
    while(temp != head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Node *head = NULL;
    head = insertBeg(head, 5);
    head = insertBeg(head, 4);
    head = insertBeg(head, 3);
    head = insertBeg(head, 2);
    head = insertEnd(head, 6);
    head = insertBetween(head, 27, 1);
    display(head);
}