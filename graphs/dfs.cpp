#include<iostream>
using namespace std;

const int vertices = 7;
int visited[vertices] = {0,0,0,0,0,0,0};
int adj[vertices][vertices] = {
    {0,0,0,1,0,0,0},  // Node 0 ↔ 3
    {0,0,0,1,0,0,0},  // Node 1 ↔ 3
    {0,0,0,1,0,0,0},  // Node 2 ↔ 3
    {1,1,1,0,1,1,1},  // Node 3 ↔ 0,1,2,4,5,6 (center)
    {0,0,0,1,0,0,0},  // Node 4 ↔ 3
    {0,0,0,1,0,0,0},  // Node 5 ↔ 3
    {0,0,0,1,0,0,0}   // Node 6 ↔ 3
};

void dfs(int i) {
    cout << i << " ";
    visited[i] = 1;
    for(int j = 0; j < vertices; j++) {
        if(adj[i][j] == 1 && visited[j] == 0){
            dfs(j);
        }
    }
}

int main() {
    int starting_node = 0;
    dfs(starting_node);
    return 0;
}