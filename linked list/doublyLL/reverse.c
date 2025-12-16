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

struct Node *reverse(struct Node *head) {
    struct Node *temp = NULL, *current = head, *newHead;
    while(current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        newHead = current;
        current = current->prev;
    }
    return newHead;
}
void display(struct Node *head) {
    printf("List: ");
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

    display(head);

    printf("Reversed\n");
    head = reverse(head);

    display(head);

    return 0;
}
