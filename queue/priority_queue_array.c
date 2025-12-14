#include<stdio.h>
#define MAX 5

int pq[MAX][2];
int front = -1, rear = -1;

void enqueue(int data, int priority) {
    if (rear == MAX - 1) {
        printf("Priority Queue Full \n");
        return;
    }
    if(front == -1) front = 0;
    rear++;
    pq[rear][0] = data;
    pq[rear][1] = priority;
}

int dequeue() {
    if(front == -1 || front > rear) {
        printf("Priority Queue Empty");
        return -1;
    } 
    int maxPriority = pq[front][1];
    int pos = front, i;
    for(i = front + 1; i <= rear; i++) {
        if(pq[i][1] > maxPriority) {
            maxPriority = pq[i][1];
            pos = i;
        }
    }

    int data = pq[pos][0];
    for(i = pos; i < rear; i++) {
        pq[i][0] = pq[i+1][0];
        pq[i][1] = pq[i+1][1];
    }
    rear--;
    if(front > rear)
        front = rear = -1;
    return data;
}

void display() {
    if(front == -1){
        printf("PQ is empty\n");
        return;
    }
    printf("PQ: ");
    int i;
    for(i = front; i <= rear; i++) {
        printf("%d (Priority Number - %d )\n", pq[i][0], pq[i][1]);
    }
    printf("\n");
}

int main() {
    enqueue(1,5);
    enqueue(2,4);
    enqueue(3,3);
    enqueue(4,2);
    enqueue(5,1);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}