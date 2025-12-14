#include<stdio.h>
#include<ctype.h>
#define MAX 100

int stack[MAX]; int top = -1;
void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

void evaluate(char exp[]) {
    int i = 0; char ch;
    while(exp[i] != '\0'){
        ch = exp[i];
        if(isdigit(ch))
            push(ch-'0');
        else {
            int y = pop();
            int x = pop();
            switch(ch) {
                case '+': push(x+y); break;
                case '-': push(x-y); break;
                case '*': push(x*y); break;
                case '/': push(x/y); break;
            }
        }
        i++;
    }
    printf("Ans = %d", stack[top]);
}

int main() {
    char exp[MAX];
    printf("Enter: ");
    scanf("%s", &exp);
    evaluate(exp);
}