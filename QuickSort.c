#include <stdio.h>
#include <stdlib.h>
void quicksort(int *arr,int l,int u);
int partition(int *arr,int l,int u);
void display(int *arr,int l,int u);
int main()
{
	int *arr,n,i;
	system("cls");
	printf("\nEnter length: ");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	printf("\nOriginal array: ");
	display(arr,0,n-1);
	quicksort(arr,0,n-1);
	printf("\nSorted array: ");
	display(arr,0,n-1);
	return 0;
}
void quicksort(int *arr,int l,int u)
{
	int pivot;
	if(l>=u)
		return;
	printf("\n\nElements: ");
	display(arr,l,u);
	pivot=partition(arr,l,u);
	printf("\nPivot: %d\n",arr[pivot]);
	printf("\nLeft: ");
	display(arr,l,pivot-1);
	printf("\nRight: ");
	display(arr,pivot+1,u);
	quicksort(arr,l,pivot-1);
	quicksort(arr,pivot+1,u);
}
int partition(int *arr,int l,int u)
{
	int i,j,temp;
	i=l+1;
	j=u;
	while(1)
	{
		while(i<=r&&arr[i]<arr[l])
			i++;
		while(j>=l&&arr[j]>arr[l])
			j--;
		if(j<i)
			break;
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	}
	temp=arr[l];
	arr[l]=arr[j];
	arr[j]=temp;
	return j;
}
void display(int *arr,int l,int u)
{
	int i;
	for(i=l;i<=u;i++)
		printf("%d ",arr[i]);
	printf("\n");
}




