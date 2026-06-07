#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 50

void ComputePrefix(char P[], int m, int pi[]) {
	int k = 0, q;
	pi[0] = 0;
	for(q = 1; q < m; q++){
		while(k > 0 && P[k] != P[q]) {
			k = pi[k-1];
		}
		if(P[k] == P[q]) {
			k++;
		}
		pi[q] = k;
	}
}

void main() {
	char T[max], P[max];
	int pi[max];
	int i, m, n, q, found;
	clrscr();
	printf("Enter text: ");
	scanf("%s", T);

	printf("Enter pattern: ");
	scanf("%s", P);

	m = strlen(P);
	n = strlen(T);

	ComputePrefix(P, m, pi);

	q = 0, found = 0;
	for(i = 0; i < n; i++) {
		while(q > 0 && P[q] != T[i]) {
			q = pi[q-1];
		}
		if(P[q] == T[i]) {
			q++;
		}
		if(q == m) {
			found = 1;
			printf("Pattern found at index: %d\n", i-m+1);
			q = pi[q-1];
		}
	}
	if(!found) {
		printf("No pattern found");
	}
	getch();
}