#include <stdio.h>
#include <stdlib.h>
void mergesort(int *arr,int l,int u);
void merge(int *arr,int l,int m,int u);
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
	mergesort(arr,0,n-1);
	printf("\nSorted array: ");
	display(arr,0,n-1);
	return 0;
}
void mergesort(int *arr,int l,int u)
{
	int m;
	if(l>=u)
		return;
	m=(l+u)/2;
	mergesort(arr,l,m);
	mergesort(arr,m+1,u);
	printf("\n\nLeft: ");
	display(arr,l,m);
	printf("\nRight: ");
	display(arr,m+1,u);
	merge(arr,l,m,u);
	printf("\nMerged: ");
	display(arr,l,u);
}
void merge(int *arr,int l,int m,int u)
{
	int n1,n2, *L, *R,i,j,k;
	n1=m-l+1;
	n2=u-m;
	L=(int *)malloc(sizeof(int)*n1);
	R=(int *)malloc(sizeof(int)*n2);
	i=0;
	j=0;
	k=l;
	while(i<n1)
		L[i++]=arr[k++];
	while(j<n2)
		R[j++]=arr[k++];
	i=0;
	j=0;
	k=l;
	while(i<n1&&j<n2)
	{
		if(L[i]<R[j])
			arr[k++]=L[i++];
		else
			arr[k++]=R[j++];
	}
	while(i<n1)
		arr[k++]=L[i++];
	while(j<n2)
		arr[k++]=R[j++];
	
}
void display(int *arr,int l,int u)
{
	int i;
	for(i=l;i<=u;i++)
		printf("%d ",arr[i]);
	printf("\n");
}




