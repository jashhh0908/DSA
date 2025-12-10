// IDK IF HEAP CODE IS THERE OR NOT, JUST DOING INCASE SO DONT COME AT ME

#include<stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//this function compares one node with its child nodes at a time
void heapify(int arr[], int n, int i) {  
    int parent = i;
    int left = i*2 + 1, right = i*2 + 2; 
    //1 - based indexing formulae are left = i*2, right = i*2 + 1
    //since practically arrays are 0-based we adjust for it by adding one 
    //parent node doesn't need +1 as it is already adjusted for in buildHeap function
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
//this function runs for every non-leaf node for the tree and heapifies down to up (max-heap) 
// n/2 - 1 gives the starting non-leaf node 
void buildHeap(int arr[], int n) {
    int i;
    for(i = n/2 - 1; i >= 0; i--) {
        heapify(arr,n,i);
    }
}
void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    int i;
    printf("Enter elements of array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    buildHeap(arr,n);
    printf("Max Heap: ");
    display(arr,n);
}