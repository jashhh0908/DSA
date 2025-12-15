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

//main function
struct Node *insert(struct Node *root, int value) {
    // struct Node *temp = create(value);
    // if(root == NULL) return temp;
    // this will assign it correctly but there will be extra nodes created in the memory which are unreferenced and just floating
    if(root == NULL) return create(value);
    else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

//as it displays nodes in sorted order, it is the best way to display
void inorder(struct Node* root) {
    struct Node* temp = root;
    if(temp == NULL) return;
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

int main() {
    int nodes, value;
    struct Node *root = NULL;

    printf("Enter no of nodes: ");
    scanf("%d", &nodes);

    printf("Enter nodes: ");
    for(int i = 0; i < nodes; i++) {
        scanf("%d", &value);
        root = insert(root, value);   
    }

    printf("Inorder: ");
    inorder(root);
    return 0;
}
