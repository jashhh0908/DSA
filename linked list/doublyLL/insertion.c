#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *getNode() {
    return (struct Node*)malloc(sizeof(struct Node));
}

struct Node *insertBeg(struct Node *head, int val) {
    struct Node *newNode = getNode();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) {
        head = newNode;
        return head;
    }
    head->prev = newNode;
    head = newNode;
    return head;
}

struct Node *insertEnd(struct Node *head, int val) {
    struct Node *newNode = getNode();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node *insertAtPos(struct Node *head, int val, int pos) {
    if (pos == 1) {
        return insertBeg(head, val);
    }

    struct Node *temp = head, *ptr = NULL;
    for (int i = 1; i < pos; i++) {
        ptr = temp;
        if (temp == NULL) {
            printf("Out of bounds\n");
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL)
        return insertEnd(head, val);

    struct Node *newNode = getNode();
    newNode->data = val;

    newNode->next = temp;
    newNode->prev = ptr;
    ptr->next = newNode;
    temp->prev = newNode;
    
    return head;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    printf("Initial DLL: ");
    display(head);

    head = insertBeg(head, 5);
    printf("After insertBeg(5): ");
    display(head);

    head = insertAtPos(head, 15, 3);
    printf("After insertAtPos(15, 3): ");
    display(head);

    head = insertEnd(head, 40);
    printf("After insertEnd(40): ");
    display(head);
    return 0;
}
