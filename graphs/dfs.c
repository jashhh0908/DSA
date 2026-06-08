#include <stdio.h>
#define V 9

int visited[V] = {0};

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

int dfs(int i, int goal) {
    int j;
    printf("%d ", i);
    if(i == goal) return 1;
    visited[i] = 1;

    for (j = 0; j < V; j++) {
        if (adj[i][j] == 1 && visited[j] == 0) {
            if(dfs(j,goal)){
                return 1;
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


    int flag = dfs(start, goal);
    if(flag) printf("\nGoal found!");
    else printf("\nGoal not found!");
    return 0;
}
