#include <stdio.h>

#define V 5   // number of vertices

int adj[V][V] = {
    {0, 1, 1, 0, 0}, //0 -> 1,2
    {1, 0, 0, 1, 1}, //1 -> 0,3,4
    {1, 0, 0, 0, 1}, //2 -> 0,4
    {0, 1, 0, 0, 0}, //3 -> 1
    {0, 1, 1, 0, 0}  // 4 -> 1,2
};

int visited[V];
int queue[V];
int front = -1, rear = -1;

void enqueue(int x) {
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void bfs(int start) {
    int i, v;

    for (i = 0; i < V; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < V; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    bfs(0);   
    return 0;
}
