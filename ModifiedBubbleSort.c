#include <stdio.h>
#include <stdlib.h>
void modifiedbubblesort(int *arr,int n);
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
	modifiedbubblesort(arr,n);
	printf("\nSorted array: ");
	display(arr,n);
	return 0;
}
void modifiedbubblesort(int *arr,int n)
{
	int i,j,temp,flag=1;
	for(i=0;i<n&&flag;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
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




