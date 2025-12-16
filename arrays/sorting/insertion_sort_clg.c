#include <stdio.h>

void insertionSort(int a[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = a[i];        // element to be inserted
        j = i - 1;
        // shift elements greater than key to the right
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;    // insert key at correct position
    }
}

int main() {
    int a[] = {8, 3, 5, 2, 4};
    int n = 5;

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
