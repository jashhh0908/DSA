#include<stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;

int isFull() {
    return front == (rear + 1) % MAX;
}
int isEmpty() {
    return front == -1;
}
void enqueue(int x) {
    if(isFull()) {
        printf("Queue is full\n");
        return;
    }
    if(front == -1) front = rear = 0;
    else if(rear == MAX - 1) rear = 0;
    else rear++;
    queue[rear] = x;
}

int dequeue() {
    if(isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = queue[front];
    if(front == rear) front = rear = -1;
    else if(front == MAX - 1) front = 0;
    else front++; 
    return x;
}

void display() {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while(1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i+1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
}