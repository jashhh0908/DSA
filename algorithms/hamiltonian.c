#include<stdio.h>
#include<conio.h>
#define V 4

int G[V+1][V+1] = {
	{0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1},
	{0, 1, 0, 1, 0},
	{0, 1, 1, 0, 1},
	{0, 1, 0, 1, 0}
};

int x[V+1];

void NextValue(int k) {
	int j;
	while(1) {
		x[k] = (x[k] + 1) % (V+1);
		if(x[k] == 0)
			return;
		if(G[x[k-1]][x[k]] != 0) {
			for(j = 1; j < k; j++) {
				if(x[j] == x[k])
					break;
			}
			if(j == k) {
				if(k < V) {
					return;
				}
				if(G[x[V]][x[1]] != 0) {
					return;
				}
			}
		}
	}
}

void Hamiltonian_Cycle(int k) {
	int i;
	while(1) {
		NextValue(k);
		if(x[k] == 0)
			return;
		if(k == V) {
			printf("Hamiltonian Cycle: ");
			for(i = 1; i <= V; i++) {
				printf("%d ", x[i]);
			}
			printf("%d\n",x[1]);
		} else {
			Hamiltonian_Cycle(k+1);
		}
	}
}

void main() {
	clrscr();
	x[1] = 2;
	Hamiltonian_Cycle(2);
	getch();
}