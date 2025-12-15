#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *getNode() {
    return (struct Node*)malloc(sizeof(struct Node));
}

struct Node *reverse(struct Node *head) {
    struct Node *prev = NULL, *current = head, *front = NULL;
    while(current != NULL) {
        front = current->next;
        current->next = prev;
        prev = current;
        current = front;
    }
    return prev;
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
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 1;
    third->next = fourth;

    fourth->data = 0;
    fourth->next = NULL;
    display(head);
    printf("Reversed");
    head = reverse(head);
    display(head);
    return 0;
}