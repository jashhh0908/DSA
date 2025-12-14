#include<stdio.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
    if(rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = queue[front++];
    if(front > rear) front = rear = -1;
    return x;
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while(i <= rear) {
        printf("%d ", queue[i]);
        i++;
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