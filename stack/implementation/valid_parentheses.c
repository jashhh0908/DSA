#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

int isValid(char str[]) {
    int i;
    top = -1;   // reset stack

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1 || !isMatching(pop(), str[i])) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    if (isValid(str))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
