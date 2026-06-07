#include<stdio.h>
#include<conio.h>
#include<string.h>
#define d 256
#define q 101
#define max 50

void main() {
	char T[max], P[max];
	int i, j, s, m, n, found = 0;
	long p, h, t;
	clrscr();
	printf("Enter text: ");
	scanf("%s", T);

	printf("Enter pattern: ");
	scanf("%s", P);

	m = strlen(P);
	n = strlen(T);
	h = 1, p = 0, t = 0;
	for(i = 0; i < m -1; i++) {
		h = (h * d) % q;
	}
	for(i = 0; i < m; i++) {
		p = (p * d + P[i]) % q;
		t = (t * d + T[i]) % q;
	}

	for(s = 0; s <= n-m; s++) {
		if(p == t) {
			for(j = 0; j < m; j++) {
				if(T[s+j] != P[j]) {
					break;
				}
			}
			if(j == m) {
				printf("Pattern found at index: %d\n", s);
				found = 1;
			}
		}
		if(s < n-m) {
			t = (d * (t - T[s] * h) + T[s+m]) % q;
			if(t < 0) {
				t += q;
			}
		}
	}
	if(!found) {
		printf("Pattern not found");
	}
	getch();
}
