#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printList(struct node *ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* deleteFirst(struct node *head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node* deleteLast(struct node *head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    struct node *p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
    return head;
}

struct node* deleteAtIndex(struct node *head, int index){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(index == 0){
        struct node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }
    struct node *p = head;
    for(int i=0; i<index-1 && p!=NULL; i++){
        p = p->next;
    }
    if(p == NULL || p->next == NULL){
        printf("Index out of range\n");
        return head;
    }
    struct node *ptr = p->next;
    p->next = ptr->next;
    free(ptr);
    return head;
}

struct node* deleteAfterNode(struct node *head, struct node *prev){
    if(prev == NULL || prev->next == NULL){
        printf("Previous node is NULL or no next node\n");
        return head;
    }
    struct node *ptr = prev->next;
    prev->next = ptr->next;
    free(ptr);
    return head;
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("Original list:\n");
    printList(head);

    head = deleteFirst(head);
    printf("After deleting first node:\n");
    printList(head);

    head = deleteLast(head);
    printf("After deleting last node:\n");
    printList(head);

    head = deleteAtIndex(head, 0);
    printf("After deleting at index 0:\n");
    printList(head);

    return 0;
}