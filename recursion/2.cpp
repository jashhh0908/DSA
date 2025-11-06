//reverse array

#include<iostream>
using namespace std;

//using 2 pointers
/*void reverse(int a[], int l, int r){
    if(l == r)
    return;
    else{
        swap(a[l], a[r]);
        reverse(a, l+1, r-1);
    }
}
int main(){
    int a[] = {1,2,3,4,5};
    int size = sizeof(a)/sizeof(a[0]);
    reverse(a,0,size-1);
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}*/

void reverse(int a[], int i, int n){
    if(i == n/2)
    return;
    else{
        swap(a[i],a[n-i-1]);
        reverse(a,++i, n);
    }
}
int main(){
    int a[] = {1,2,3,4,5};
    int size = sizeof(a)/sizeof(a[0]);
    reverse(a,0,size);
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

