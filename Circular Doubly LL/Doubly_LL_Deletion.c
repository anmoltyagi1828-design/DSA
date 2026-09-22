#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
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
    if(head != NULL){
        head->prev = NULL;
    }
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
    while(p->next != NULL){
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);
    return head;
}
struct node* deleteAtIndex(struct node *head, int index){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(index == 0){
        return deleteFirst(head);
    }
    struct node *p = head;
    for(int i=0; i<index && p!=NULL; i++){
        p = p->next;
    }
    if(p == NULL){
        printf("Index out of range\n");
        return head;
    }
    if(p->next != NULL){
        p->next->prev = p->prev;
    }
    if(p->prev != NULL){
        p->prev->next = p->next;
    }
    free(p);
    return head;
}
struct node* deleteAfterNode(struct node *head, struct node *prev){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(prev == NULL || prev->next == NULL){
        printf("No node to delete after the given node\n");
        return head;
    }
    struct node *ptr = prev->next;
    prev->next = ptr->next;
    if(ptr->next != NULL){
        ptr->next->prev = prev;
    }
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
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = NULL;
    third->prev = second;

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

    head = deleteAfterNode(head, head);
    printf("After deleting after the first node:\n");
    printList(head);
}