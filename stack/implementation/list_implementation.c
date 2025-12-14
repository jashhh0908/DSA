#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *getNode(void) {
    return (struct Node*)malloc(sizeof(struct Node));
}

struct Node *push(struct Node *top, int x) {
    struct Node *newNode = getNode();
    newNode->data = x;
    newNode->next = NULL;
    if(top == NULL) {
        return newNode;
    }
    newNode->next = top;
    top = newNode;
    return top;
}

struct Node *pop(struct Node *top) {
    if(top == NULL) {
        printf("Stack is empty!\n");
        return NULL;
    }
    struct Node *popped = top;
    top = top->next;
    printf("Popped element: %d\n", popped->data);
    free(popped);
    return top;
}

void display(struct Node *top){
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek(struct Node *top) {
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d", top->data);
}
int main() {
    struct Node *top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    display(top);
    top = pop(top);
    display(top);
    peek(top);
}