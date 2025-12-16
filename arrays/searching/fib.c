#include <stdio.h>

int fibSearch(int a[], int n, int key) {
    int fib2 = 0, fib1 = 1, fib = fib2 + fib1;
    while(fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;
    while(fib > 1) {
        int i = (offset + fib2 < n) ? offset + fib2 : n-1;
        if(a[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if(a[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;
        }
        if(fib1 && a[offset + 1] == key) {
            return offset + 1;
        }
    }
    return -1;
}
int main() {
    int a[] = {10, 22, 35, 40, 45, 50};
    int n = 6, key = 22;

    int pos = fibSearch(a, n, key);

    if(pos != -1)
        printf("Element found at index %d", pos);
    else
        printf("Element not found");

    return 0;
}
