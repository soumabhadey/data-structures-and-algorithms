#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int binarySearch(int *,int,int,int);
void sort(int *,int);
void swap(int *,int *);
int main()
{
	int n, *arr,i,search;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	puts("Enter elements");
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	printf("Enter search item: ");
	scanf("%d",&search);
	sort(arr,n);
	if(binarySearch(arr,0,n-1,search))
		puts("Successful");
	else
		puts("Unsuccessful");
	return 0;
}
int binarySearch(int *arr,int l,int u,int search)
{
	int m;
	if(l>u)
		return FALSE;
	m=(l+u)/2;
	if( *(arr+m)==search)
		return TRUE;
	if( *(arr+m)<search)
		return binarySearch(arr,m+1,u,search);
	return binarySearch(arr,l,m-1,search);
}
void sort(int *arr,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if( *(arr+i)> *(arr+j))
				swap(arr+i,arr+j);
}
void swap(int *a,int *b)
{
	int temp;
	temp= *a;
	*a= *b;
	*b=temp;
}