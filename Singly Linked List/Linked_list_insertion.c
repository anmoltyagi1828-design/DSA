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
struct node *insertatfirst(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node *insertatend(struct node *head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    if(head == NULL){   
        ptr->next = NULL;
        return ptr;
    }

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct node *insertatbtw(struct node *head,int data, int index){
    struct node *ptr =(struct node *)malloc(sizeof(struct node));
    struct node *p =head;
    for(int i=0; i!=index-1 && p!=NULL;i++){
        p = p->next;
    }
    if(p == NULL){
        printf("Index out of range\n");
        return head;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;

}
struct node *insertafternode(struct node *head,struct node *prev,int data){
    struct node *ptr =(struct node *)malloc(sizeof(struct node));
    if(prev == NULL){
        printf("Previous node cannot be NULL\n");
        return head;
    }
    ptr->data = data;
    ptr->next = prev->next;
    prev->next = ptr;
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
    printList(head);
    head = insertatend(head,45);
    printf("\n");
    printList(head); 
    return 0;
}