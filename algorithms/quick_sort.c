#include<stdio.h>
#include<conio.h>

void display(int a[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition_index(int a[], int low, int high) {
	int pivot, i ,j;
	pivot = a[low];
	i = low + 1;
	j = high;
	while(i <= j) {
		while(i <= high && a[i] <= pivot) { i++; }
		while(j >= low && a[j] > pivot) { j--; }
		if(i < j) {
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[j], &a[low]);
	return j;
}

void quick_sort(int a[], int low, int high) {
	int index;
	if(low < high) {
		index = partition_index(a, low, high);
		quick_sort(a, low, index);
		quick_sort(a, index + 1, high);
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
	quick_sort(a, 0, n-1);
	printf("\nAfter Sorting: ");
	display(a,n);
	getch();
}