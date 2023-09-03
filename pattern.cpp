#include<stdio.h>
# define MAX 50
int main()
{
	int arr[MAX][MAX], odd, i, j, n;
    scanf("%d",&n);
    odd = 1 + ((n-1)*2);
    int high=odd;
    int low=0;
    
	for(i=low;i<odd;i++)
    {
       arr[i][0]=n;
       arr[i][odd-1]=n;
	}
	
    for(j=0;j<odd;j++)
	{
		arr[0][j]=n;
		arr[odd-1][j]=n;
	}
    arr[odd/2][odd/2]=1;
	for(i=0;i<odd;i++)
	{
		for(j=0;j<odd;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}



/*
	if(i==0||i==odd-1)
    	{
    		for(j=0;j<odd;j++)
    	   {
    		printf("%d ",n);
		   }
		}
		else
		{
			if(j==0 || j==odd-1)
			     printf("%d ",n);
		}
		printf("\n");
		
*/
