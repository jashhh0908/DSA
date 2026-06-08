#include <stdio.h>
#include <conio.h>
#define V 9

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

int dls(int current, int goal, int limit) {
    int i;
    printf("%d ", current);
    if(current == goal) return 1;
    if(limit == 0) return 0;
    visited[current] = 1;
    for(i = 0; i < V; i++) {
        if(adj[current][i] && !visited[i]) {
            if(dls(i, goal, limit - 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int dfid(int current, int goal, int maxDepth) {
    int i, depth;

    for(depth = 0; depth <= maxDepth; depth++) {
        for(i = 0; i < V; i++) {
            visited[i] = 0;
        }

	printf("\nDepth %d: ", depth);

	if(dls(current, goal, depth)) {
	    return 1;
	}
    }
    return 0;
}

void main() {
    int i, start, goal, flag, depth;
    clrscr();
    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter goal node: ");
    scanf("%d", &goal);

    printf("Enter max depth: ");
    scanf("%d", &depth);
    for(i = 0; i < V; i++) {
	visited[i] = 0;
    }
    flag = dfid(start, goal, depth);
    if(flag) printf("\nGoal found!");
    else printf("\nGoal not found!");
    getch();
}