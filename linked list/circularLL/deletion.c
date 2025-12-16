#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *getNode(void) {
    return (struct Node*)malloc(sizeof(struct Node));
}

struct Node *deleteBeg(struct Node *head) {
    if(head == NULL) {
        printf("list is empty\n");
        return head;
    }
    if(head->next == head) {
        free(head);
        return NULL;
    }
    struct Node *temp = head, *node_to_del = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
    free(node_to_del);
    return head;
}

struct Node *deleteEnd(struct Node *head) {
    if(head == NULL) {
        printf("list is empty\n");
        return head;
    }
    if(head->next == head) {
        free(head);
        return NULL;
    }
    struct Node *prev = NULL, *last = head;
    while(last->next != head) {
        prev = last;
        last = last->next;
    }
    prev->next = head;
    free(last);
    return head;
}

struct Node *deleteInBetween(struct Node *head, int pos) {
    if(head == NULL) {
        printf("Empty List\n");
        return NULL;
    }
    if(pos == 1) {
        return deleteBeg(head);
    }
    struct Node *node_to_del = head, *prev = head;
    for(int i = 1; i < pos; i++) {
        prev = node_to_del;
        node_to_del = node_to_del->next;
        if(node_to_del == head) {
            printf("Out of bounds\n");
            return head;
        }
    }
    if(node_to_del->next == head)
        return deleteEnd(head);
        
    prev->next = node_to_del->next;
    free(node_to_del);
    return head;

}
void display(struct Node *head) {
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    printf("List: ");
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}
int main() {
    struct Node *head = getNode();
    struct Node *second = getNode();
    struct Node *third = getNode();
    struct Node *fourth = getNode();

    head->data = 7;
    head->next = head;

    // second->data = 8;
    // second->next = third;

    // third->data = 9;
    // third->next = fourth;

    // fourth->data = 10;
    // fourth->next = head;

    head = deleteInBetween(head, 2);
    display(head);
}