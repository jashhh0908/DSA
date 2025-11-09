void inorder(struct Node* root) {
    struct Node* temp = root;
    if(temp == NULL) return;
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}