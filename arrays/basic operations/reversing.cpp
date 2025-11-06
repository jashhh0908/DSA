#include <iostream>
using namespace std;

void reverse(int a[], int size)
{
    int start = 0, end = size - 1, temp;
    while(start < end){
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

void print(int a[], int size)
{
    int i;
    for(i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

int main()
{
    int a[] = {
        1,
        2,
        3,
        4,
        5,
    };
    int size = sizeof(a) / sizeof(a[0]);
    reverse(a, size);
    print(a,size);
}