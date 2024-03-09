#include <stdio.h>
#include <stdlib.h>
void selectionsort(int *arr,int n);
void display(int *arr,int n);
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
	display(arr,n);
	selectionsort(arr,n);
	printf("\nSorted array: ");
	display(arr,n);
	return 0;
}
void selectionsort(int *arr,int n)
{
	int i,j,temp,small,pos;
	for(i=0;i<n;i++)
	{
		small=arr[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(small>arr[j])
			{
				small=arr[j];
				pos=j;
			}
		}
		if(arr[i]!=small)
		{
			arr[pos]=arr[i];
			arr[i]=small;
		}
		printf("\nStep %d: ",i+1);
		display(arr,n);
	}
}
void display(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}




