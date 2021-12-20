#include<stdio.h>
#include<stdlib.h>
int func(int arr[], int k, int n)
{
    int i,j,count=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j && arr[i]==arr[j])
            {
                break;
            }
        }
        if(j==n)
               count++;
        if(count==k)
               return arr[i];
    }
    return -1;
}
int main()
{
    int n,k;
    printf("Enter no. of elements of the array  : ");
    scanf("%d",&n);
    int i,arr[n];
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
       scanf("%d",&arr[i]);
    printf("\nEnter value of k : ");
    scanf("%d",&k);
    printf("\n%dth non repeating element is : %d",k,func(arr,k,n));
    return 0;
    return 0;
}
