#include <stdio.h>
#include <stdlib.h>
int *sp1, *sp2,n;
void input();
void createTuple();
int count();
void tridiagonal();
int main()
{
	input();
	createTuple();
	tridiagonal();
	return 0;
}
void input()
{
	printf("Enter size: ");
	scanf("%d",&n);
	sp1=(int *)malloc(sizeof(int)*n*n);
	puts("Enter elements of matrix:");
	int i;
	for(i=0;i<n*n;i++)
		scanf("%d",sp1+i);
}
void createTuple()
{
	sp2=(int *)malloc(sizeof(int)*3*(count()+1));
	*(sp2+0)=n;
	*(sp2+1)=n;
	*(sp2+2)=count();
	int r=0,c=0,l=3;
	int i;
	for(i=0;i<n*n;i++)
	{
		if(c!=0&&c%n==0)
		{
			c=0;
			r++;
		}
		if(*(sp1+i)!=0)
		{
			*(sp2+l)=r;
			l++;
			*(sp2+l)=c;
			l++;
			*(sp2+l)= *(sp1+i);
			l++;
		}
		c++;
	}
}
int count()
{
	int c=0;
	int i;
	for(i=0;i<n*n;i++)
		if(*(sp1+i)!=0)
			c++;
	return c;
}
void tridiagonal()
{
	int i;
	for(i=3;i<3*(count()+1);i+=3)
	{
		int r= *(sp2+i+0),c= *(sp2+i+1);
		if(r!=c-1&&r!=c+1)
		{
			puts("Not a tridiagonal matrix\n");
			return;
		}
	}
	puts("Tridiagonal matrix\n");
}