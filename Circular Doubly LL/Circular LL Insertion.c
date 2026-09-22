#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node *head){
    struct node *ptr = head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    do{
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}
struct node *insertAtEnd(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if(head == NULL){
        ptr->next = ptr;
        return ptr;
    }
    struct node *p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
struct node *insertAtBeginning(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if(head == NULL){
        ptr->next = ptr;
        return ptr;
    }
    struct node *p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    for(int i = 0; i < index - 1; i++){
        if(p->next == head){
            printf("Index out of range\n");
            free(ptr);
            return head;
        }
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main(){
    struct node *head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtBeginning(head, 0);
    head = insertAtIndex(head, 2, 5);
    display(head);
    return 0;
}