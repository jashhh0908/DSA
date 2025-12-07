#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Counting sort for a specific digit place
void countingSort(int arr[], int n, int place) {
    int output[n];
    int count[10] = {0};

    // Count occurrences of digits
    for(int i = 0; i < n; i++) {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    // Compute prefix sums - gives us index where each element is placed in output array
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (in reverse for stability)
    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for(int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}


int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before Sort:\n");
    display(arr, n);
    radixSort(arr, n);
    printf("After Sort:\n");
    display(arr, n);
    return 0;
}
