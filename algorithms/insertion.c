//codes are done in turbo C

#include<stdio.h>
#include<conio.h>

void insertion(int n, int arr[]) {
	int i, j, key;
	for(i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main() {
	int n, arr[100], i;
	clrscr();
	printf("Enter size: ");
	scanf("%d", &n);

	printf("Enter elements: ");
	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Before sorting: ");
	for(i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}

	insertion(n, arr);

	printf("\nAfter sorting: ");
	for(i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
	getch();
	return 0;
}