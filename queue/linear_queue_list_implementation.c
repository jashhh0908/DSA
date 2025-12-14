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
        return;
    }
    rear->next = newNode;
    rear = newNode; 
}

int dequeue() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = front->data;
    if(front->next == NULL) {
        free(front);
        front = rear = NULL;
        return x;
    }
    struct Node *temp = front;
    front = front->next;
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
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    int x = dequeue();
    if(x != -1)
        printf("Dequeued: %d\n", x);
    display();
    return 0;
}