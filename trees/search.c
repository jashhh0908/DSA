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

struct Node *insert(struct Node *root, int value) {
    if(root == NULL) return create(value);
    else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int search(struct Node *root, int key) {
    if(root == NULL)
        return 0;
    if(root->data < key) {
        return search(root->right, key);
    } 
    else if (root->data > key) {
        return search(root->left, key);
    }
    else 
        return 1;
}
int main() {
    int nodes, value;
    printf("Enter no of nodes: ");
    scanf("%d", &nodes);
    
    printf("Enter root node: ");
    scanf("%d", &value);
    struct Node *root = create(value);
    insert(root, value);
    
    printf("Enter child nodes: ");
    for(int i = 0; i < nodes - 1; i++ ) {
        scanf("%d", &value);
        insert(root, value);
    }
    
    printf("Enter node to search: ");
    scanf("%d", &value);
    int flag = search(root, value);
    if(flag)
        printf("Node found");
    else
        printf("Node not found");
    return 0;
}
 