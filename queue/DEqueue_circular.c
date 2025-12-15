#include<stdio.h>
#define MAX 5

int deque[MAX], front = -1, rear = -1;

int isFull() {
    return front == (rear + 1) % MAX;
}
int isEmpty() {
    return front == -1;
}
void insert_rear(int x) {
    if(isFull()) {
        printf("Overflow\n");
        return;
    }
    if(front == -1) front = rear = 0;
    else if(rear == MAX - 1) rear = 0;
    else rear++;
    deque[rear] = x;
}
void insert_front(int x) {
    if(isFull()) {
        printf("Overflow\n");
        return;
    }
    if(front == -1) front = rear = 0;
    else if(front == 0) front = MAX - 1;
    else front--;
    deque[front] = x;
}
int delete_front() {
    if(isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    int x = deque[front];
    if(front == rear) front = rear = -1;
    else if(front == MAX - 1) front = 0;
    else front++;
    return x; 
}
int delete_rear() {
    if(isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    int x = deque[rear];
    if(front == rear) front = rear = -1;
    else if(rear == 0) rear = MAX - 1;
    else rear--;
    return x;
}
void display() {
    if(front == -1) {
        printf("Empty Queue\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while(1) {
        printf("%d ", deque[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {

    insert_rear(10);
    insert_rear(20);
    insert_rear(30);
    display();          // 10 20 30

    insert_front(5);
    display();          // 5 10 20 30

    insert_front(1);
    display();          // 1 5 10 20 30 (FULL)

    insert_rear(99);   // Overflow
    display();

    printf("Deleted front: %d\n", delete_front());
    display();          // 5 10 20 30

    printf("Deleted rear: %d\n", delete_rear());
    display();          // 5 10 20

    printf("Deleted front: %d\n", delete_front());
    printf("Deleted front: %d\n", delete_front());
    printf("Deleted front: %d\n", delete_front());
    display();          // empty

    printf("Deleted rear: %d\n", delete_rear()); // Underflow

    return 0;
}
