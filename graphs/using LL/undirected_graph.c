#include<stdio.h>
#include<stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adjList[10];
int vertices;

struct Node *getNode() {
    return (struct Node*)malloc(sizeof(struct Node));
}
void createGraph() {
    int i, edges, u ,v;
    printf("Enter no of vertices: ");
    scanf("%d", &vertices);

    for(i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }

    printf("Enter no of edges: ");
    scanf("%d", &edges);
    for(i = 0; i < edges; i++) {
        printf("Enter edge: (u,v) u->v: ");
        scanf("%d %d", &u, &v);
        struct Node *newNode = getNode();
        newNode->vertex = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;

        //2-way link
        struct Node *temp = getNode();
        temp->vertex = u;
        temp->next = adjList[v];
        adjList[v] = temp;
    }
}

void display() {
    int i;
    struct Node *temp;
    printf("Adjacency List (undirected graph):\n");
    for(i = 0; i < vertices; i++) {
        printf("%d => ", i);
        temp = adjList[i];
        while(temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    createGraph();
    display();
    return 0;
}