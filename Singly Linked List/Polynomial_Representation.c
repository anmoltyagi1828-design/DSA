#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* addTerm(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (!head) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printPolynomial(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}
int main() {
    struct Node* poly = NULL;
    poly = addTerm(poly, 3, 2);
    poly = addTerm(poly, 5, 1);
    poly = addTerm(poly, 2, 0);

    printf("Polynomial: ");
    printPolynomial(poly);

    return 0;
}