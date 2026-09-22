#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int pow;
    struct node* next;
};


struct node* createNode(int c, int p) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}


struct node* insert(struct node* head, int c, int p) {
    struct node* newNode = createNode(c, p);

    if (head == NULL || head->pow < p) {
        newNode->next = head;
        return newNode;
    }

    struct node* temp = head;
    while (temp->next != NULL && temp->next->pow > p) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct node* addPoly(struct node* p1, struct node* p2) {
    struct node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow == p2->pow) {
            result = insert(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow) {
            result = insert(result, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else {
            result = insert(result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }


    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}


void display(struct node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->pow);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *p1 = NULL, *p2 = NULL, *result = NULL;

    // Polynomial 1: 5x^2 + 4x + 2
    p1 = insert(p1, 5, 2);
    p1 = insert(p1, 4, 1);
    p1 = insert(p1, 2, 0);

    // Polynomial 2: 3x^2 + 2x + 1
    p2 = insert(p2, 3, 2);
    p2 = insert(p2, 2, 1);
    p2 = insert(p2, 1, 0);

    printf("Polynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    result = addPoly(p1, p2);

    printf("Sum: ");
    display(result);

    return 0;
}