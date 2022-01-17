#include<stdio.h>
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int arr[], int lb, int ub)
{
	int pivot = arr[ub];
	int i = lb-1,j;
	for(j = lb; j < ub; j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i+1],&arr[ub]);
	return i+1;
}
void QuickSort(int arr[], int lb, int ub)
{
	if(lb<ub)
	{
		int p = Partition(arr,lb,ub);
		
		//recursive call on the subarray left to pivot element..
		QuickSort(arr,lb,p-1);
	
		//recursive call on the subarray right to pivot element..
		QuickSort(arr,p+1,ub);	 
	}
}
int main(){
	int a[]={8, 7, 1, 9, 4, 10, 6};
	int i, num = sizeof(a)/sizeof(a[0]);
	printf("\nArray before sorting : \n");
	for(i=0;i<num;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nArray after sorting : \n");
	QuickSort(a,0,num-1);
	for(i=0;i<num;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
