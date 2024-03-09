#include <stdio.h>
#include <stdlib.h>
void insertionsort(int *arr,int n);
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
	insertionsort(arr,n);
	printf("\nSorted array: ");
	display(arr,n);
	return 0;
}
void insertionsort(int *arr,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0&&arr[j]>temp;j--)
			arr[j+1]=arr[j];
		arr[j+1]=temp;
		printf("\nStep %d: ",i);
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




