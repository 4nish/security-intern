#include <stdio.h>

int main()
{

    int n;
    printf("enter the dimensions of matrix ");
    scanf("%d", &n);
    int arr[n][n];
    printf("\nthe dimensions of matrix are %d * %d ",n,n);
    //larger values of n would result in segmentation fault
}