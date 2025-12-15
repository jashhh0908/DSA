#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *getNode(void) {
    return (struct Node*)malloc(sizeof(struct Node));
}

struct Node *deleteBeg(struct Node *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node *deleteEnd(struct Node *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node *deleteInBetween(struct Node *head, int pos) {
    if(head == NULL) {
        printf("Empty List\n");
        return NULL;
    }
    if(pos == 1) {
        return deleteBeg(head);
    }

    struct Node *temp = head, *prev = NULL;
    for(int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if(temp == NULL) {
            printf("Out of bounds\n");
            return head;
        }
    }
    prev->next = temp->next;
    free(temp);
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
    struct Node *head = getNode();
    struct Node *second = getNode();
    struct Node *third = getNode();
    struct Node *fourth = getNode();

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = NULL;

    display(head);

    head = deleteInBetween(head, 2);
    display(head);

    head = deleteBeg(head);
    display(head);

    head = deleteEnd(head);
    display(head);

    return 0;
}
