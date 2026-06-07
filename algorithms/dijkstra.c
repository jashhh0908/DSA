#include<stdio.h>
#include<conio.h>

#define V 4
#define INF 9999

void main() {
    int cost[V][V] = {
        {0, 10, 6, 5},
        {10, 0, 1, 0},
        {6, 1, 0, 2},
        {5, 0, 2, 0}
    };

    int i, j, u, min, visited[V], dist[V], source;

    clrscr();

    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            if(cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;
            }
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    //initialize distances and source
    for(i = 0; i < V; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(i = 1; i < V; i++) {
        min = INF;

        for(j = 0; j < V; j++) {
            //check if current vertex is not visited and if distance is minimum
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        //relax
        for(j = 0; j < V; j++) {
            if(!visited[j] && dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("Shortest Distances:\n");

    for(i = 0; i < V; i++) {
        printf("%d --> %d = %d\n", source, i, dist[i]);
    }

    getch();
}