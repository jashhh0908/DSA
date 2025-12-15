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
    //if list is empty or one node only
    if(head == NULL || head->next == head) {
        return head;
    }
    struct Node *prev = NULL, *current = head, *front = NULL;
    do{
        front = current->next;
        current->next = prev;
        prev = current;
        current = front;
    } while(current != head);
    head->next = prev;
    head = prev;
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;
    if(head == NULL)
        return;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
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
    fourth->next = head; 

    display(head);

    printf("Reversed\n");
    head = reverse(head);

    display(head);

    return 0;
}
