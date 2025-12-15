#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

struct Node *getNode(void) {
    return (struct Node*)malloc(sizeof(struct Node));
}
void enqueue(int x) {
    struct Node *newNode = getNode();
    newNode->data = x;
    newNode->next = NULL;
    if(front == NULL) {
        front = rear = newNode;
        rear->next = front;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    rear->next = front;
}

int dequeue() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int x;
    if(front == rear) {
        x = front->data;
        free(front);
        front = rear = NULL;
        return x;
    }
    struct Node *temp = front;
    x = temp->data;
    front = front->next;
    rear->next = front;
    free(temp);
    return x;
}

void display() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    struct Node *temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
    printf("\n");
}

int main() {
    int x;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    x = dequeue();
    if(x != -1) 
        printf("Dequeued: %d\n", x);
    display();
    return 0;
}
