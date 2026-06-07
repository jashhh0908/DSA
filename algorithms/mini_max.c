//codes are done in turbo C
#include<stdio.h>
#include<conio.h>

struct Pair {
	int min;
	int max;
};

struct Pair minimax(int arr[], int low, int high) {
	struct Pair result, left, right;
	int mid;
	if(low == high) {
		result.min = arr[low];
		result.max = arr[low];
		return result;
	}
	if(high == low + 1) {
		if(arr[low] < arr[high]) {
			result.min = arr[low];
			result.max = arr[high];
		}
		else {
			result.min = arr[high];
			result.max = arr[low];
		}
		return result;
	}
	mid = low + (high - low) / 2;
	left = minimax(arr, low, mid);
	right = minimax(arr, mid + 1, high);

	if(left.min < right.min) {
		result.min = left.min;
	} else {
		result.min = right.min;
	}
	if(left.max > right.max) {
		result.max = left.max;
	} else {
		result.max = right.max;
	}
	return result;
}
int main() {
	int n, arr[100], i;
	struct Pair ans;
	clrscr();
	printf("Enter size: ");
	scanf("%d", &n);

	printf("Enter elements: ");
	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	ans = minimax(arr, 0, n-1);
	printf("\nMinimum = %d", ans.min);
	printf("\nMaximum = %d", ans.max);
	getch();
	return 0;
}