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



//main functions
struct Node *deleteStart(struct Node *head) {
    if(head == NULL) {
        return NULL;
    }
    if(head->next == NULL) {//1 element LL
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    if(head->next != NULL) {//if list has more than 1 elements 
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    return head;
}

struct Node *deleteEnd(struct Node *head) {
    if(head == NULL)
        return NULL;
    if(head->next == NULL) {//1 element LL
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while(temp->next->next != NULL) 
        temp = temp->next;
    struct Node *tail = temp->next;
    temp->next = NULL;
    free(tail);
    return head;
}

struct Node *deleteAtPos(struct Node *head, int pos){
    if(head == NULL)
        return NULL;
    int i;

    if (pos == 1) {
        head = deleteStart(head);
        return head;
    }
    struct Node *temp = head, *ptr = NULL; 
    for (int i = 1; i < pos; i++) {
        ptr = temp;
        temp = temp->next;
        if (temp == NULL) {
            printf("Out of bounds\n");
            return head;
        }
    }
    if (temp->next == NULL)
        return deleteEnd(head);
    
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return head;
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

int main() {
    struct Node *head = NULL;
    head = create(head, 10);
    head = create(head, 20);
    head = create(head, 30);
    head = create(head, 40);

    printf("Initial DLL: ");
    display(head);

    // 1. Delete middle (pos = 3)
    head = deleteAtPos(head, 4);
    printf("\nAfter deleting pos 4: ");
    display(head);

    // 2. Delete beginning
    head = deleteAtPos(head, 1);
    printf("\nAfter deleting beginning: ");
    display(head);

    // 3. Delete end
    head = deleteAtPos(head, 2);
    printf("\nAfter deleting end: ");
    display(head);

    // 4. Delete last node
    head = deleteAtPos(head, 1);
    printf("\nAfter deleting last node: ");
    display(head);

    // 5. Out of bounds
    head = deleteAtPos(head, 1);

    return 0;
}