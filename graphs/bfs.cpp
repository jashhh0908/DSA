#include<iostream>
using namespace std;

struct queue {
    int size;
    int front;
    int rear;
    int* arr;
};

int isFull(queue *q) {
    if(q->rear == q->size - 1)
        return 1;
    else 
        return 0;
}

int isEmpty(queue *q) {
    if(q->front == -1 || q->front > q->rear)
        return 1;
    else 
        return 0;
}

void enqueue(queue *q, int value) {
    if(isFull(q))
        cout << "Queue is full";
    else {
        if(q->front == -1) 
            q->front = 0;
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int dequeue(queue *q) {
    if(isEmpty(q)) {
        cout << "Queue is empty";
        return -1;
    } else {
        int value = q->arr[q->front];
        q->front++;
        if(q->front == q->rear)
            q->front = q->rear = -1;
        return value;
    }
}
int main() {
    queue q;
    q.front = q.rear = -1;
    q.size = 100;
    q.arr = new int[q.size];
    int vertices = 7; //7 nodes
    //matrix tells us which is node is connected to which other node
    //for eg. 1st row -> node = 0 and is connected to 1,2,3 nodes.
    int adj[7][7] = {
        {0,1,0,0,1,0,0},  // 0 → 1,4
        {1,0,1,0,0,0,0},  // 1 → 0,2
        {0,1,0,1,0,0,0},  // 2 → 1,3
        {0,0,1,0,0,1,1},  // 3 → 2,5,6
        {1,0,0,0,0,1,0},  // 4 → 0,5
        {0,0,0,1,1,0,0},  // 5 → 3,4
        {0,0,0,1,0,0,0}   // 6 → 3
    };

    int visited[vertices] = {0,0,0,0,0,0,0};
    int starting_node = 0;
    visited[starting_node] = 1;
    cout << starting_node << " ";
    enqueue(&q, starting_node); //put the first node in the queue

    //main BFS logic
    while(!isEmpty(&q)) { //loop till every node is visited
        int current_node = dequeue(&q);
        for(int j = 0; j < vertices; j++) { 
            //check the row for the current node in adj matrix and if the node inside that row has been visited or not - to avoid revisiting
            if(adj[current_node][j] == 1 && visited[j] == 0) { 
                cout << j << " ";
                visited[j] = 1; //we have now reached that univisited node 
                enqueue(&q, j); //run the loop similarly for that unvisited node which is now the current node
            }
        }
    }
}