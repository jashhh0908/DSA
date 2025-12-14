#include<stdio.h>
#include<ctype.h>
#define MAX 100

char stack[MAX]; int top = -1;
void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }

int precedence(char c) {
    if(c == '^') return 3;
    if(c == '/' || c == '*') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

void convert(char exp[]) {
    int i = 0, k = 0;
    char ch, output[MAX];
    while(exp[i]!= '\0') {
        ch = exp[i];
        if(isalnum(ch))
            output[k++] = ch;
        else if(ch == '(')
            push(ch);
        else if(ch == ')'){
            while(top != -1 && stack[top] != '(')
                output[k++] = pop();
            pop();
        }
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
                output[k++] = pop();
            push(ch);
        }
        i++;
    }
    while(top != -1)
        output[k++] = pop();
    output[k] = '\0';
    printf("Postfix: %s", output);
}

int main() {
    char exp[MAX];
    printf("Enter: ");
    scanf("%s", &exp);
    convert(exp);
}