#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* search(struct node *head, int key){
    struct node *ptr = head;
    while(ptr != NULL){
        if(ptr->data == key){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
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

    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);
    
    struct node *result = search(head, key);
    if(result != NULL){
        printf("Value %d found in the list.\n", key);
    } else {
        printf("Value %d not found in the list.\n", key);
    }

    free(third);
    free(second);
    free(head);
    return 0;
}