#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node *getNode() {
    return (struct Node*)malloc(sizeof(struct Node));   
};

struct Node *create(int value){
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    struct Node *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
}

/*
        1
       / \
      2   3
    /  \
   4    5
*/
    