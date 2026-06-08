#include<stdio.h>
#include<conio.h>

void display(int a[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void merge(int a[], int low, int mid, int high) {
	int i, j, k, temp[100];
	i = low, j = mid+1, k = low;
	while(i<= mid && j <= high) {
		if(a[i] < a[j]) {
			temp[k] = a[i];
			i++; k++;
		} else {
			temp[k] = a[j];
			j++; k++;
		}
	}
	while(i<= mid) {
		temp[k] = a[i];
		i++; k++;
	}
	while(j <= high) {
		temp[k] = a[j];
		j++; k++;
	}
	for(i = low; i <= high; i++) {
		a[i] = temp[i];
	}
    //display here
    printf("Merged [%d..%d]: ", low, high);
    display(a, high + 1);
}
void merge_sort(int a[], int low, int high) {
	int mid;
	if(low < high) {
		mid = low + (high - low) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
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
	merge_sort(a, 0, n-1);
	printf("\nAfter Sorting: ");
	display(a,n);
	getch();
}