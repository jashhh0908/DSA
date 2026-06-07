//codes are done in turbo C
#include<stdio.h>
#include<conio.h>

#define MAX 10
#define INF 9999
#define V 4
void main() {
	int cost[V][V] = {
		{0, 10, 6, 5},
		{10, 0, 0, 15},
		{6, 0, 0, 4},
		{5, 15, 4, 0}
	};

	int visited[V];
	int a, b, i, j, min, minCost = 0, edges = 0;
	clrscr();
	for(i = 0; i < V; i++) {
		for(j = 0; j < V; j++) {
			if(cost[i][j] == 0) {
				cost[i][j] = INF;
			}
		}
	}

	for(i = 0; i < V; i++) {
		visited[i] = 0;
	}

	visited[0] = 1;
	printf("Edges in MST:\n");
	while(edges < V - 1) {
		min = INF;
		a = -1;
		b = -1;

		for(i = 0; i < V; i++) {
			if(visited[i]) {
				for(j = 0; j < V; j++) {
					if(!visited[j] && cost[i][j] < min) {
						min = cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		printf("%d -> %d = %d\n", a,b, min);
		minCost += min;
		edges++;
		visited[b] = 1;
	}

	printf("\nMin Cost = %d", minCost);
	getch();
}