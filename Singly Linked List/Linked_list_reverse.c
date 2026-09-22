#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* reverseList(struct node *head){
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextNode;

    while(current != NULL){
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
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
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    head = reverseList(head);

    printf("Reversed list:\n");
    ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    free(third);
    free(second);
    free(head);
    return 0;
}
