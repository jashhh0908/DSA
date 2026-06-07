#include<stdio.h>
#include<conio.h>

#define N 8

int x[N];

/* Checks whether queen can be placed
   in row k and column i */
int Place(int k, int i)
{
	int j;

	for(j = 0; j < k; j++)
	{
		/* Same column */
		if(x[j] == i)
		{
			return 0;
		}

		/* Same diagonal */
		if(abs(x[j] - i) == abs(j - k))
		{
			return 0;
		}
	}

	return 1;
}

/* Prints the chess board */
void printBoard()
{
	int i, j;

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(x[i] == j)
			{
				printf("Q ");
			}
			else
			{
				printf(". ");
			}
		}
		printf("\n");
	}

	printf("\n");
}

/* N Queens Backtracking */
void NQueens(int k)
{
	int i;

	for(i = 0; i < N; i++)
	{
		if(Place(k, i))
		{
			x[k] = i;

			if(k == N - 1)
			{
				printBoard();
			}
			else
			{
				NQueens(k + 1);
			}
		}
	}
}

void main()
{
	clrscr();

	NQueens(0);

	getch();
}