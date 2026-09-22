#include <stdio.h>
int main(){
    int a[50][50],b[50][50],c[50][50],m,n,p,q,i,j;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d",&m,&n);
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d",&p,&q);
    if(n!=p){
        printf("Matrix multiplication not possible\n");
        return 0;
    }
    printf("Enter the elements of second matrix:\n");
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            scanf("%d",&b[i][j]);
        }
    }
    // Multiplying the two matrices
    for(i=0;i<m;i++){
        for(j=0;j<q;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("The product of the two matrices is:\n");
    for(i=0;i<m;i++){
        for(j=0;j<q;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}