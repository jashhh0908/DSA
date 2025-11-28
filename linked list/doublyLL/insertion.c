#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *getNode() {
    return (struct Node*)malloc(sizeof(struct Node));
}

//main function 
struct Node *create(struct Node *head, int val) {
    if(head == NULL) {
        head = getNode();
        head->data = val;
        head->next = head->prev = NULL;
        return head;
    }
    struct Node *newNode = getNode();
    newNode->data = val;
    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }   
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
    return head;
}

int nodeCount (struct Node *head) {
    int c = 0;
    struct Node *temp = head;
    while(temp != NULL) {
        temp = temp->next;
        c++;
    }
    return c;
}

struct Node *insert(struct Node *head, int val, int pos, int n) {
    struct Node *newNode = getNode();
    newNode->data = val;
    if(pos == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if(head != NULL)//if inserting into empty list, head->prev = newNode will give error hence separate condition 
            head->prev = newNode;
        head = newNode;
    } else if (pos == n+1) {
        struct Node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next = NULL;
    } else if(pos > n+1) {
        printf("out of bounds\n");
        return head;
    } else {
        int i;
        struct Node *temp = head, *ptr = head;
        for(i = 1; i < pos; i++) {
            ptr = temp;
            temp = temp->next;
        }
        temp->prev = newNode;
        newNode->next = temp;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    return head;
}
void display(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    //user-input
    struct Node *head = NULL;
    int val = 0;
    while(val != -1) {
        printf("enter a value (-1 to stop): ");
        scanf("%d", &val);
        if(val == -1)
            break;
        else {
            head = create(head, val);
        }
    }
    printf("Printing LL: "); 
    display(head);

    int n = nodeCount(head);
    int pos;
    printf("\nEnter value & position to insert: ");
    scanf("%d %d", &val, &pos);
    head = insert(head, val, pos, n);
    printf("Printing LL: "); 
    display(head);

    return 0;
}