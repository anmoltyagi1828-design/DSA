#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

int countNodes(struct node *head){
    int count = 0;
    struct node *ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
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

    int totalNodes = countNodes(head);
    printf("Total number of nodes in the linked list: %d\n", totalNodes);

    free(third);
    free(second);
    free(head);
    return 0;
}