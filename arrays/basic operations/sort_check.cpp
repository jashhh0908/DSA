#include<iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int a[size], i;
    cout << "Enter elements: ";
    for(i = 0; i < size; i++){
        cin >> a[i];
    }

    bool sorted = true;
    for(i = 0; i < size; i++){
        if(a[i] > a[i + 1]){
            sorted = false;
            break;
        }
    }

    if(sorted){
        cout << "\nArray is sorted";
    }
    else
        cout <<"\nArray is not sorted";
}