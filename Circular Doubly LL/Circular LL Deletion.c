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
struct node *deleteFirst(struct node *head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    struct node *ptr = head;
    struct node *p = head;
    while(p->next != head){
        p = p->next;
    }
    if(head->next == head){
        free(head);
        return NULL;
    }
    p->next = head->next;
    head = head->next;
    free(ptr);
    return head;
}
struct node *deleteLast(struct node *head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    struct node *p = head;
    struct node *q = NULL;
    while(p->next != head){
        q = p;
        p = p->next;
    }
    if(q == NULL){
        free(head);
        return NULL;
    }
    q->next = head;
    free(p);
    return head;
}
struct node *deleteAtIndex(struct node *head, int index){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(index == 0){
        return deleteFirst(head);
    }
    struct node *p = head;
    struct node *q = NULL;
    for(int i=0; i<index && p->next != head; i++){
        q = p;
        p = p->next;
    }
    if(p == head){
        printf("Index out of range\n");
        return head;
    }
    q->next = p->next;
    free(p);
    return head;
}
struct node *deleteAfterNode(struct node *head, struct node *prev){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(prev == NULL || prev->next == head){
        printf("No node to delete after the given node\n");
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
    third->next = head;

    printf("Original list:\n");
    display(head);

    head = deleteFirst(head);
    printf("After deleting first node:\n");
    display(head);

    head = deleteLast(head);
    printf("After deleting last node:\n");
    display(head);

    head = deleteAtIndex(head, 0);
    printf("After deleting at index 0:\n");
    display(head);

    head = deleteAfterNode(head, head);
    printf("After deleting after the first node:\n");
    display(head);

    free(third);
    free(second);
    free(head);
    return 0;
}