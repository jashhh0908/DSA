#include <stdio.h>

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int a[] = {2, 4, 6, 8, 10};
    int n = 5, key = 8;
    int pos = binarySearch(a, n, key);
    if(pos != -1)
        printf("Element found at index %d", pos);
    else
        printf("Element not found");
    return 0;
}
