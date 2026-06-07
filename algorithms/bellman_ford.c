#include<stdio.h>
#include<conio.h>

#define V 4
#define INF 9999

struct Edge {
    int u, v, w;
};

void main() {
    int cost[V][V] = {
        {0, 10, 6, 5},
        {10, 0, 1, 0},
        {6, 1, 0, 2},
        {5, 0, 2, 0}
    };

    int i, j, u, v, w, source, dist[V];
    struct Edge edges[V * V];
    int E = 0;

    clrscr();

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            if(cost[i][j] != 0) {
                edges[E].u = i;
                edges[E].v = j;
                edges[E].w = cost[i][j];
                E++;
            }
        }
    }

    for(i = 0; i < V; i++) {
        dist[i] = INF;
    }

    dist[source] = 0;

    for(i = 1; i < V; i++) {
        for(j = 0; j < E; j++) {
            u = edges[j].u;
            v = edges[j].v;
            w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(j = 0; j < E; j++) {
        u = edges[j].u;
        v = edges[j].v;
        w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative Weight Cycle Detected!\n");
            break;
        }
    }

    printf("Shortest Distances:\n");
    for(i = 0; i < V; i++) {
        printf("%d --> %d = %d\n", source, i, dist[i]);
    }
    getch();
}