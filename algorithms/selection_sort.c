#include<stdio.h>
#include<conio.h>

void display(int a[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void selection_sort(int a[], int n) {
	int i, j, minIndex, temp;
	for(i = 0; i < n - 1; i++) {
		minIndex = i;
		for(j = i + 1; j < n; j++) {
			if(a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;
        //display each iteration over here
	}
}
void main() {
	int i, n, a[100];
	clrscr();
	printf("Enter size: ");
	scanf("%d", &n);

	printf("Enter elements: ");
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("\nBefore Sorting: ");
	display(a, n);
	selection_sort(a,n);
	printf("\nAfter Sorting: ");
	display(a,n);
	getch();
}