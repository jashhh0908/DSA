#include<stdio.h>
#include<conio.h>
#define V 4
#define M 3

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
		x[k] = (x[k] + 1) % (M + 1);
		if(x[k] == 0)
			return;
		for(j = 1; j <= V; j++) {
			if(G[k][j] != 0 && x[k] == x[j])
				break;
		}
		if(j == V+1)
			return;
	}
}

void M_Colouring(int k) {
	int i;
	while(1) {
		NextValue(k);
		if(x[k] == 0)
			return;
		if(k == V) {
			for(i = 1; i <= V; i++) {
				printf("%d ", x[i]);
			}
			printf("\n");
		} else {
			M_Colouring(k+1);
		}
	}
}

void main() {
	clrscr();
	M_Colouring(1);
	getch();
}