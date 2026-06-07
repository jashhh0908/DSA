#include<stdio.h>
#include<conio.h>
#define max 50

int c[max][max];
char b[max][max];

void printLcs(char x[], int i, int j) {
	if(i == 0 || j == 0) return;
	if(b[i][j] == 'D') {
		printLcs(x, i-1, j-1);
		printf("%c", x[i-1]);
	} else if(b[i][j] == 'U') {
		printLcs(x, i-1, j);
	} else {
		printLcs(x, i, j-1);
	}
}
void main() {
	char x[max], y[max];
	int i, j, m = 0, n = 0;
	clrscr();
	printf("Enter string 1: ");
	scanf("%s", x);

	printf("Enter string 2: ");
	scanf("%s", y);

	while(x[m] != '\0') { m++; }
	while(y[n] != '\0') { n++; }

	for(i = 0; i <= m; i++) {
		c[i][0] = 0;
	}
	for(j = 0; j <= n; j++) {
		c[0][j] = 0;
	}

	for(i = 1; i <= m; i++) {
		for(j = 1; j <= n; j++) {
			if(x[i-1] == y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 'D';
			} else if(c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 'U';
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = 'L';
			}
		}
	}
	printf("Length = %d\n", c[m][n]);
	printf("LCS = ");
	printLcs(x, m, n);
	getch();
}