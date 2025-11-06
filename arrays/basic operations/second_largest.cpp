#include<iostream>
#include<climits>
using namespace std;

int func(int a[], int size){
    int max = INT_MIN;
    int second = INT_MIN;
    int i;
    for(i = 0; i < size; i++){
        if(a[i] > max){
            second = max;
            max = a[i];
        }
        else if(a[i] > second && a[i] != max){
            second = a[i];
        }
    }
    if(second == INT_MIN) return -1;
    else return second;
}

int main(){
    int a[] = {
        13,
        11,
        3,
        45,
        59,
    };
    int size = sizeof(a) / sizeof(a[0]);
    cout << "Second largest = " << func(a,size);
}