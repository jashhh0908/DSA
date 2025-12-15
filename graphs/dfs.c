#include <stdio.h>
#define V 7

int visited[V] = {0};

int adj[V][V] = {
    {0,0,0,1,0,0,0},  // 0 -> 3
    {0,0,0,1,0,0,0},  // 1 -> 3
    {0,0,0,1,0,0,0},  // 2 -> 3
    {1,1,1,0,1,1,1},  // 3 -> 0,1,2,4,5,6
    {0,0,0,1,0,0,0},  // 4 -> 3
    {0,0,0,1,0,0,0},  // 5 -> 3
    {0,0,0,1,0,0,0}   // 6 -> 3
};

void dfs(int i) {
    int j;
    printf("%d ", i);
    visited[i] = 1;

    for (j = 0; j < V; j++) {
        if (adj[i][j] == 1 && visited[j] == 0) {
            dfs(j);
        }
    }
}

int main() {
    int start = 0;
    dfs(start);
    return 0;
}
