#include <stdio.h>

#define V 9   // number of vertices

int adj[V][V] = {
    {0,1,1,0,0,0,0,0,0},
    {1,0,0,1,1,0,0,0,0},
    {1,0,0,0,0,1,1,0,0},
    {0,1,0,0,0,0,0,1,0},
    {0,1,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,1},
    {0,0,0,1,0,0,0,0,0}, 
    {0,0,0,0,0,0,1,0,0}
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

int bfs(int start, int goal) {
    int i, v;

    for (i = 0; i < V; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        v = dequeue();
        printf("%d ", v);
        if (v == goal) return 1;
        for (i = 0; i < V; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    return 0;
}

int main() {
    int start, goal;
    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter goal node: ");
    scanf("%d", &goal);


    int flag = bfs(start, goal);
    if(flag) printf("\nGoal found!");
    else printf("\nGoal not found!");
    return 0;
}
