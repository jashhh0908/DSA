#include<iostream>
#include<climits>
using namespace std;

int kadane(int a[], int size){
    int currentSum = 0, maxSum = INT_MIN, i;
    for(i = 0 ; i < size ; i++){
        currentSum += a[i];
        if(currentSum > maxSum)
            maxSum = currentSum;
        if(currentSum < 0)
            currentSum = 0;
    } 
    return maxSum;
}

int main(){
    int a[] = {-2,7,-3,4};
    int size = sizeof(a)/sizeof(a[0]);

    cout << "Sum = " << kadane(a,size);
}