#include<stdio.h>

int binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + ((high - low) / 2);
        if(arr[mid] == target) return mid + 1;
        else if(arr[mid] > target) high = mid -1;
        else low = mid + 1; 
    }
    return -1;
}
int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 2;
    int index = binary_search(arr, n, target);
    if(index == -1) printf("not found");
    else printf("found at: %d", index);
    return 0;
}