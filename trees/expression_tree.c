#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 10
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *stack[MAX]; int top = -1;
void push(struct Node *temp) {
    stack[++top] = temp;
}
struct Node *pop() {
    return stack[top--];
}
struct Node *createNode(char ch) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *expressionTree(char exp[]) {
    int i; char ch;
    for(i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        if(isalnum(ch))
            push(createNode(ch));
        else {
            struct Node *right = pop();
            struct Node *left = pop();
            struct Node *newNode = createNode(ch);
            newNode->left = left;
            newNode->right = right;
            push(newNode);
        }
    }
    return pop();
}

void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
int main() {
    char postfix[50];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct Node* root = expressionTree(postfix);

    printf("\nInorder: ");
    inorder(root);
    return 0;
}