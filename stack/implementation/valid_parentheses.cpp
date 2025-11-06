#include<iostream>
using namespace std;

char stack[100];
int top = -1;
void push(char x){
    if(top == 99){
        cout << "\nStack overflow";
    }
    else{
        top++;
        stack[top] = x;
    }
}

char pop(){
    if(top == -1){
        cout << "\nStack is empty";
        return '\0';
    }
    else{
        char c = stack[top];
        top--;
        return c;
    }
}

bool isMatching(char open, char close){
    return (open == '(' && close == ')' ||
            open == '[' && close == ']' ||
            open == '{' && close == '}');
}

bool isValid(char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            push(str[i]);
        }
        else{
            if (top == -1 || !isMatching(pop(), str[i])){
                return false;
            }
        }
    }   
    return top == -1;
}

int main(){
    char str[100];
    cout << "Enter string: ";
    cin >> str;
    if(isValid(str)){
        cout << "Yes";
    }
    else{
        cout << "no";
    }
}