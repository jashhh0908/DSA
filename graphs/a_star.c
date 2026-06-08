#include <stdio.h>
#include <conio.h>
#define max 10
#define INF 9999

int graph[max][max] = {
    {0,2,4,0,0,0},
    {0,0,1,7,3,0},
    {0,0,0,2,1,8},
    {0,0,0,0,2,3},
    {0,0,0,0,0,2},
    {0,0,0,0,0,0}
};

int h[max] = {7, 6, 2, 8, 1, 0}, g[max], f[max];

int parent[max];

int open[max], closed[max];

int getMinF(int n) {
    int i, min = INF, index = -1;
    for(i = 0; i < n; i++) {
        if(open[i] && f[i] < min) {
            min = f[i];
            index = i;
        }
    }
    return index;
}

void printPath(int goal) {
    if(parent[goal] == -1) {
        printf("%d ", goal);
        return;
    }
    printPath(parent[goal]);
    printf("%d ", goal);
}

void Astar(int start, int goal, int n) {
    //initialization
    int i, current, newG;
    for(i = 0; i < n; i++) {
        g[i] = INF;
        f[i] = INF;
        open[i] = 0;
        closed[i] = 0;
        parent[i] = -1;
    }

    //put start in OPEN
    g[start] = 0, f[start] = g[start] + h[start], open[start] = 1;
    while(1) {
        //choose min node in opepn from minF
        current = getMinF(n);
        if(current == -1) {
            printf("Goal not found!");
            return;
        }
        //check if goal
        if(current == goal) {
            printf("Goal found!\n");
            printf("Path: ");
            printPath(current);
	    printf("\nCost = %d", g[current]);
            return;
        }
        //move current from OPEN to CLOSED
        open[current] = 0;
        closed[current] = 1;
        //examine neighbours
        for(i = 0; i < n; i++) {
            if(!closed[i] && graph[current][i] > 0) {
                newG = g[current] + graph[current][i];
                if(!open[i] || newG < g[i]) {
                    parent[i] = current;
                    g[i] = newG;
                    f[i] = g[i] + h[i];
                    open[i] = 1;
                }
            }
        }
    }
}

void main() {
    int start, goal;
    clrscr();
    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter goal node: ");
    scanf("%d", &goal);

    Astar(start, goal, 6);
    getch();
}