#include <iostream>
using namespace std;

void leader(int a[], int size)
{
    int leader[size], max = a[size - 1], temp, i, j = 1;
    leader[0] = max;
    for (i = size - 1; i >= 0; i--){
        if(a[i] > max){
            leader[j] = a[i];
            j++;
            max = a[i];
        }
    }

    int start = 0, end = j - 1;
    while(start < end){
        temp = leader[start];
        leader[start] = leader[end];
        leader[end] = temp;
        start++;
        end--;
    }

    for(i = 0; i < j; i++){
        cout << leader[i] << " ";
    }
}

int main()
{
    int a[] = {16, 17, 4, 3, 5, 2};
    int size = sizeof(a) / sizeof(a[0]);

    leader(a, size);
}