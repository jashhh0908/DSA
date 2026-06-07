#include<stdio.h>
#include<conio.h>
#define max 20
int w[20], x[20], n, m;
void sos(int s, int k, int r) {
	int i;
	x[k] = 1;
	//check if including the current element reaches the target
	if(s + w[k] == m) {
		printf("{ ");
		for(i = 0; i < n; i++) {
			if(x[i] == 1) {
				printf("%d ", w[i]);
			}
		}
		printf("}\n");
		x[k] = 0;
	//check if including the next element doesn't exceed the target
	} else if((k+1 < n) && (s + w[k] + w[k+1] <= m)) {
		sos(s + w[k], k+1, r - w[k]);
	}
	/*
	   check if we excldue the current element and include the next one
	   can we still reach our target
	*/
	if((k+1 <  n) && (s + r - w[k] >= m) && (s + w[k+1] <= m)) {
		x[k] = 0;
		sos(s, k+1, r - w[k]);
	}
}

void main() {
	int i, total = 0;
	clrscr();
	printf("Enter target: ");
	scanf("%d", &m);

	printf("Enter no of weights: ");
	scanf("%d", &n);

	printf("Enter weights: ");
	for(i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		total += w[i];
	}

	sos(0, 0, total);
	getch();
}
