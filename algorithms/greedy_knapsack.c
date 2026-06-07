#include<stdio.h>
#include<conio.h>

struct Item {
	int p, w;
	float r;
};

void main() {
	struct Item item[20], temp;
	int i, j, n, capacity;
	float profit = 0;
	clrscr();
	printf("Enter no of items: ");
	scanf("%d", &n);

	printf("\nEnter values for each item.\n\n");
	for(i = 0; i < n; i++) {
		printf("Enter profit and weight for Item %d: ", i+1);
		scanf("%d %d", &item[i].p, &item[i].w);
		item[i].r = (float)item[i].p / (float)item[i].w;
	}

	printf("Enter capacity of knapsack: ");
	scanf("%d", &capacity);

	//sort descending
	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n-i-1; j++) {
			if(item[j].r < item[j+1].r) {
				temp = item[j];
				item[j] = item[j+1];
				item[j+1] = temp;
			}
		}
	}

	for(i = 0; i < n; i++) {
		if(item[i].w <= capacity) {
			profit += item[i].p;
			capacity -= item[i].w;
		} else {
			profit += ((float)capacity / (float)item[i].w) * item[i].p;
			capacity = 0;
		}
		if(capacity == 0) break;
	}

	printf("Maximum profit = %.2f", profit);
	getch();
}