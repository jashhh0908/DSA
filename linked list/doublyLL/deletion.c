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

int nodeCount (struct Node *head) {
    int c = 0;
    struct Node *temp = head;
    while(temp != NULL) {
        temp = temp->next;
        c++;
    }
    return c;
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

struct Node *deleteMiddle(struct Node *head, int pos){
    if(head == NULL)
        return NULL;
    int i;
    struct Node *ptr = head, *temp = head;
    for(i = 1; i < pos; i++) {
        ptr = temp;
        temp = temp->next;
    }
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
    printf("Printing LL: "); 
    display(head);

    int n = nodeCount(head);
    int pos;
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    if(pos == 1) 
        head = deleteStart(head);
    else if(pos == n) {
        head = deleteEnd(head);
    } else if(pos > n) {
        printf("Out of bounds");
        return 0;
    } else {
        head = deleteMiddle(head, pos);
    }
    printf("Printing LL: "); 
    display(head);

    return 0;
}