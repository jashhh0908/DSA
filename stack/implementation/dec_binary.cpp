//decimal to binary conversion

#include<iostream>
using namespace std;

int stack[8], top = -1;
void push(int x){
    if(top == 7) {
        cout << "\nStack is full!";
    }
    else{
        top++;
        stack[top] = x;
    }
}

int main(){
    int n, i;
    cout << "Enter a decimal number: ";
    cin >> n;

    while(n > 0){
        int remainder = n % 2;
        push(remainder);
        n /= 2;
    }

    cout << "Its binary equivalent: ";
    for(i = top; i >= 0; i--){
        cout << " " << stack[i];
    }
}