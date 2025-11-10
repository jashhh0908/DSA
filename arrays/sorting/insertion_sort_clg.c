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

void insertionSort(int *a, int n) {
    int i,j,key;
    for(i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            swap(&a[j], &a[j + 1]);
            j--;
        }
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");   
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: \n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting: \n");
    display(arr, n);
    insertionSort(arr, n);      
    printf("Array after sorting: \n");
    display(arr, n);
    return 0;
}