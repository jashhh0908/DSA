// 1. pick a pivot and place it in its correct place in the sorted array
// 2. smaller on the left, larger on the right
// 3. keep on swapping & repeating as array gets smaller
//  TC - O(n logn)

#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition_Index(int *a, int low, int high) // to find the correct sorted position of pivot in the array
{
    int pivot = a[low];
    int i = low + 1, j = high;
    while(i <= j) {
        while(i <= high && a[i] <= pivot) i++; //find larger element than pivot
        while(j >= low  && a[j] > pivot) j--; //find smaller element than pivot
        if(i < j) //to check if i has crossed j or not 
            swap(&a[i], &a[j]); 
    }
    swap(&a[low], &a[j]); //if i has crossed j then replace pivot with j
    return j;
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int index = partition_Index(a, low, high);
        quick_sort(a, low, index - 1); //solve for left subarray
        quick_sort(a, index + 1, high); //solve for right subarray
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}