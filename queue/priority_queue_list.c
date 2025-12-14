#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int data, int priority) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if(front == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if(front == NULL) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    struct Node *temp = front, *prev = NULL;
    struct Node *maxNode = front,*maxPrev = NULL;

    while(temp != NULL) {
        if(temp->priority > maxNode->priority) {
            maxNode = temp;
            maxPrev = prev;
        }
        prev = temp;
        temp = temp->next;
    }
    int data = maxNode->data;
    // Case 1: highest priority node is front
    if(maxPrev == NULL) {
        front = front->next;
        if(front == NULL) //if on doing front->next, front is NULL => list has only one node hence reset to NULL
            rear = NULL;
    }
    // Case 2: node is middle or last
    else {
        maxPrev->next = maxNode->next;
        if(maxNode == rear)
            rear = maxPrev;
    }
    free(maxNode);
    return data;
}

void display() {
    if(front == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Priority Queue:\n");
    while(temp != NULL) {
        printf("%d (Priority %d)\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    enqueue(1, 5);
    enqueue(2, 4);
    enqueue(3, 3);
    enqueue(4, 2);
    enqueue(5, 1);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}