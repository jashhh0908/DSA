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

void inorder(struct Node* root) {
    struct Node* temp = root;
    if(temp == NULL) return;
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

struct Node *min(struct Node* root) {
    struct Node *temp = root;
    while(temp != NULL && temp->left != NULL)
        temp = temp->left;
    return temp;
}

struct Node *deleteNode(struct Node *root, int value) {
    if(root == NULL)
        return NULL;
    if(value < root->data) //traverse left side 
        root->left = deleteNode(root->left, value);
    else if(value > root->data) //traverse right side 
        root->right = deleteNode(root->right, value);
    else {
        //case for leaf node and 1 child node (left)
        if(root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        //case for 1 child node (right); works for leaf node also but the first condition solves it anyway 
        else if(root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        //case for 2 child nodes
        //here we are basically taking the inorder successor of the deleted node when we traverse right subtree
        struct Node *temp = min(root->right); //find the minimum value in the right subtree and replace it with deleted node
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main() {
    int nodes, value, del;
    printf("Enter no of nodes: ");
    scanf("%d", &nodes);
    
    printf("Enter root node: ");
    scanf("%d", &value);
    struct Node *root = create(value);
    insert(root, value);
    
    printf("Enter child nodes: ");
    for(int i = 0; i < nodes - 1; i++) {
        scanf("%d", &value);
        insert(root, value);
    }
    printf("Tree: ");
    inorder(root);

    printf("Enter node to delete: ");
    scanf("%d", &del);
    deleteNode(root, del);
    printf("Tree: ");
    inorder(root);
    return 0;
}
 