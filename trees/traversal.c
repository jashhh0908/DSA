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

void preorder(struct Node* root) {
    struct Node* temp = root;
    if(temp == NULL) return;
    printf("%d ", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void inorder(struct Node* root) {
    struct Node* temp = root;
    if(temp == NULL) return;
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

void postorder(struct Node* root) {
    struct Node* temp = root;
    if(temp == NULL) return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ", temp->data);
}

int main() {
    struct Node *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("Preorder: ");
    preorder(root);
    printf("\nInorder: "); 
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
}

/*
        1
       / \
      2   3
    /  \
   4    5
*/
    