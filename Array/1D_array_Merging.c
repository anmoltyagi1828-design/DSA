#include <stdio.h>
int main(){
    int a[100],b[100],c[200],n1,n2,i,j,k;
    printf("Enter the number of elements in the first array: ");
    scanf("%d",&n1);
    printf("Enter the elements of the first array:\n");
    for(i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d",&n2);
    printf("Enter the elements of the second array:\n");
    for(i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    // Merging the two arrays
    for(i=0;i<n1;i++){
        c[i]=a[i];
        
    }
    for(i=0;i<n2;i++){
        c[n1+i]=b[i];
    }
    printf("The merged array is:\n");
    for(i=0;i<n1+n2;i++){
        printf("%d ",c[i]);
    }
    return 0;
}