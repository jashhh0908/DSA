// IDK IF HEAP CODE IS THERE OR NOT, JUST DOING INCASE SO DONT COME AT ME

#include<stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//helper function
void heapify(int arr[], int n, int i) {  
    int parent = i;
    int left = i*2 + 1, right = i*2 + 2; 
    if(left < n && arr[left] > arr[parent]) {
        parent = left;
    } 
    if(right < n && arr[right] > arr[parent]) {
        parent = right;
    }
    if(parent != i) {
        swap(&arr[parent], &arr[i]);
        heapify(arr, n, parent);
    }
}
//helper function
void buildHeap(int arr[], int n) {
    int i;
    for(i = n/2 - 1; i >= 0; i--) {
        heapify(arr,n,i);
    }
}

//main function
void insert(int arr[], int *n, int x) {
    arr[*n] = x;
    int i = *n; //index of the inserted element
    (*n)++;
    int parent = (i-1)/2;
    while(arr[i] > arr[parent]) {
        swap(&arr[parent], &arr[i]);
        i = parent;
        parent = (i-1)/2;
    }
}
void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int arr[100], n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int i;
    printf("Enter elements of array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    buildHeap(arr,n);
    printf("Max Heap: ");
    display(arr,n);

    int x;
    printf("\nEnter element to insert: ");
    scanf("%d", &x);
    insert(arr,&n,x);
    display(arr,n);
}