#include <stdio.h>
int main(){
    int a[50][50],b[50][50],r1,c1,i,j;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            b[j][i] = a[i][j];
        }
    }
    printf("The transpose of the matrix is:\n");
    for (int i = 0; i < c1; i++) {
        for (int j = 0; j < r1; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}