#include<stdio.h>
#define MAX 100

int stack[MAX], top = -1;
void push(int x) {
    if(top == MAX - 1) {
        printf("Stack is full");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if(top == -1) {
        printf("Stack empty");
        return -1;
    }
    int x;
    x = stack[top];
    top--;
    return x;
}
int main() {
    push(4);
    push(3);
    push(2);
    push(1);
    int n = top + 1;
    int reversed[n], i;
    for(i = 0; i < n; i++) {
        reversed[i] = pop();
    }
    printf("reversed: ");
    for(i = 0; i < n; i++) {
        printf("%d ", reversed[i]);
    }
    return 0;
}