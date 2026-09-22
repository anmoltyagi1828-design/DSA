#include <stdio.h>

int main() {
    int arr[100], n, choice, pos, value, i;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n--- 1D Array Operations ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                // Insertion
                if (n >= 100) {
                    printf("Array is full!\n");
                    break;
                }

                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                    break;
                }

                printf("Enter value to insert: ");
                scanf("%d", &value);

                for (i = n - 1; i >= pos; i--) {
                    arr[i + 1] = arr[i];
                }

                arr[pos - 1] = value;
                n++;

                printf("Element inserted successfully.\n");
                break;

            case 2:
                // Deletion
                if (n == 0) {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;

            case 3:
                // Traversal
                if (n == 0) {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Array elements are: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}