#include<iostream>
using namespace std;

int stack[5], top = -1;
void push(int x);
void pop();
void display();
int main(){
    int ch;
    while(true){
        cout << "\n---Stack Operations---\n";
        cout << "1. Push \n2.Pop \n3.Display \n4.Exit\n";
        cin >> ch;
        switch(ch){
            case 1:
                int x;
                cout << "Enter element to push: ";
                cin >> x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

void push(int x) {
    if(top == 4) {
        cout << "\nStack is full!";
    }
    else{
        top++;
        stack[top] = x;
        cout << "\nElement added";
    }
}

void pop(){
    if(top == -1){
        cout << "\nStack is empty";
    }
    else{
        top--;
    }
}

void display(){
    int i;
    cout << "\nCurrent status of stack: ";
    for(i = top; i >= 0; i--){
        cout << "\n" << stack[i];
    }
}