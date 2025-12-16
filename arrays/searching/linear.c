#include <stdio.h>
int linearSearch(int a[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(a[i] == key)
            return i;   
    }
    return -1;         
}
int main() {
    int a[] = {5, 2, 9, 1, 7};
    int n = 5, key = 9;
    int pos = linearSearch(a, n, key);
    if(pos != -1)
        printf("Element found at index %d", pos);
    else
        printf("Element not found");
    return 0;
}
