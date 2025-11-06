#include<iostream>
using namespace std;

void f(int n){
    cout << "1 ";
    f(n-1);
    if(n == 0)
    return;
}
int main(){
    f(5);
    return 0;
}