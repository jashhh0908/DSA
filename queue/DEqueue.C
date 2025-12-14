//Input restricted - insert rear, delete (both)
//Output restricted - insert (both), delete front
#include <stdio.h>
#define MAX 10
int deque[MAX]; int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void insert_rear(int x) {
    if (isFull()) {
        printf("DEqueue is full\n");
        return;
    }
    if (front == -1) front = rear = 0;
    else rear++;
    deque[rear] = x;    
}

void insert_front(int x) {
    if (front == 0 && !isEmpty()) {
        printf("Cannot insert at front\n");
        return;
    }
    if (front == -1) front = rear = 0;
    else front--;
    deque[front] = x;
}

int delete_front() {
    if (isEmpty()) {
        printf("DEqueue is empty\n");
        return -1;
    }
    int x = deque[front++];
    if (front > rear) front = rear = -1;
    return x;
}

int delete_rear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    int x = deque[rear--];
    if (front > rear) front = rear = -1;
    return x;
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {

    printf("---- Testing Input Restricted Deque ----\n");
    // Allowed: insert_rear, delete_front, delete_rear

    insert_rear(10);
    insert_rear(20);
    insert_rear(30);
    display();

    printf("Deleted from front: %d\n", delete_front());
    display();

    printf("Deleted from rear: %d\n", delete_rear());
    display();


    printf("\n---- Testing Output Restricted Deque ----\n");
    // Allowed: insert_front, insert_rear, delete_front

    insert_front(5);
    insert_rear(15);
    insert_front(2);
    display();

    printf("Deleted from front: %d\n", delete_front());
    display();

    // delete_rear();  // ❌ NOT allowed in output-restricted deque

    return 0;
}
