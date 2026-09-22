#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *insertAtEnd(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if(head == NULL){
        ptr->prev = NULL;
        return ptr;
    }
    struct node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    return head;
}
struct node *insertAtBeginning(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    if(head == NULL){
        ptr->next = NULL;
        return ptr;
    }
    head->prev = ptr;
    ptr->next = head;
    return ptr; 
}
struct node *insertAfterNode(struct node *head, struct node *prev, int data){
    if(prev == NULL){
        printf("Previous node cannot be NULL\n");
        return head;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prev->next;
    ptr->prev = prev;
    if(prev->next != NULL){
        prev->next->prev = ptr;
    }
    prev->next = ptr;
    return head;
}
struct node *insertAtIndex(struct node *head, int index, int data){
    if(index < 0){
        printf("Index cannot be negative\n");
        return head;
    }
    if(index == 0){
        return insertAtBeginning(head, data);
    }
    struct node *p = head;
    for(int i=0; i<index-1 && p!=NULL; i++){
        p = p->next;
    }
    if(p == NULL){
        printf("Index out of range\n");
        return head;
    }
    return insertAfterNode(head, p, data);
}
void printList(struct node *ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main(){
    struct node *head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    printList(head);
    head = insertAtBeginning(head, 0);
    printList(head);
    head = insertAfterNode(head, head->next, 1);
    printList(head);
    head = insertAtIndex(head, 2, 5);
    printList(head);
    return 0;
}