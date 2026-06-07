#include<stdio.h>
#include<conio.h>

#define V 4
#define E 5

struct Edge {
	int u, v, w;
};

int parent[V];
int find(int x) {
	while(parent[x] != x) {
		x = parent[x];
	}
	return x;
}

void main() {
	int cost[V][V] = {
		{0, 10, 6, 5},
		{10, 0, 0, 15},
		{6, 0, 0, 4},
		{5, 15, 4, 0}
	};

	struct Edge edges[E], temp;
	int i, j, minCost = 0, count = 0, edgeCount = 0;
	int uRoot, vRoot;
	clrscr();
	//initialize parent array
	for(i = 0; i < V; i++) {
		parent[i] = i;
	}
	//convert matrix to edge list
	for(i = 0; i < V; i++) {
		for(j = i+1; j < V; j++) {
			if(cost[i][j] != 0) {
				edges[edgeCount].u = i;
				edges[edgeCount].v = j;
				edges[edgeCount].w = cost[i][j];
				edgeCount++;
			}
		}
	}
	//sort edge list
	for(i = 0; i < E-1; i++) {
		for(j = 0; j < E-i-1; j++) {
			if(edges[j].w > edges[j+1].w) {
				 temp = edges[j];
				 edges[j] = edges[j+1];
				 edges[j+1] = temp;
			}
		}
	}
	//print sorted edge list
	for(i = 0; i < E; i++) {
		printf("%d --> %d = %d\n", edges[i].u, edges[i].v, edges[i].w);
	}

	printf("\n");

	printf("Edges in MST:\n");
	for(i = 0; i < E && count < V-1; i++) {
		uRoot = find(edges[i].u);
		vRoot = find(edges[i].v);
		if(uRoot != vRoot) {
			printf("%d --> %d = %d\n", edges[i].u, edges[i].v, edges[i].w);
			minCost += edges[i].w;
			parent[vRoot] = uRoot;
			count++;
		}
	}
	printf("\nTotal minimum cost = %d", minCost);
	getch();
}