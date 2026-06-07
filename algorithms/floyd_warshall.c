#include <stdio.h>
#include <conio.h>
#define V 4
#define INF 9999

void printDistance(int dist[][V])
{
    int i, j;
    printf("Shortest Distance Matrix:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }

        printf("\n");
    }
}

void printPi(int pi[][V])
{
    int i, j;
    printf("Pi Matrix:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            if(pi[i][j] == -1)
                printf("NIL ");
            else
                printf("%d ", pi[i][j]);
        }

        printf("\n");
    }
}

void main()
{
    int dist[V][V] =
    {
        {0, 10, 6, 5},
        {10, 0, 1, 0},
        {6, 1, 0, 2},
        {5, 0, 2, 0}
    };

    int pi[V][V];
    int i, j, k;
    clrscr();

    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            if(dist[i][j] == 0 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            if(i == j) {
                pi[i][j] = -1;
            }
            else if(dist[i][j] != 0) {
                pi[i][j] = i;
            }
            else {
                pi[i][j] = -1;
            }
        }
    }

    for(k = 0; k < V; k++) {
        for(i = 0; i < V; i++) {
            for(j = 0; j < V; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
        //if asked to show every iteration, print over here
    }

    printDistance(dist);
    printf("\n");
    printPi(pi);

    getch();
}