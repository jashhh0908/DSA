#include<stdio.h>

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *a, int n) {
    int i,j;
    for(i = 0; i < n-1; i++) {
        for(j = i; j < n; j++) {
            if(a[j] < a[i]) {
                swap(&a[j], &a[i]);
            }
        }
    }
}
int main() {
    //take array input from user
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: \n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    };
    printf("Array before sorting: \n");
    display(arr, n);
    selectionSort(arr, n);
    printf("Array after sorting: \n");
    display(arr, n);
    return 0;
}