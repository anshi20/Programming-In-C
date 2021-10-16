// Name : Anshika Maheshwari
#include<stdio.h>
void toh(char s[10],char d[20],char h[20],int n)
{
    if(n==1)
    {
        printf("Move the disk %d from %s to %s\n",n,s,d);
        return;
    }
    toh(s,h,d,n-1);
    printf("Move the disk %d from %s to %s\n",n,s,d);
    toh(h,d,s,n-1);
}
int main(){
    int n;
    printf("Enter no. of disks : ");
    scanf("%d",&n);
    char s[10]="Source";
    char h[20]="Auxiliary";
    char d[20]="Destination";
    toh(s,d,h,n);
    return 0;
}
