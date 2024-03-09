#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct details
{
	char name[100];
	int age;
	int salary;
};
struct person
{
	struct details data;
	struct person *link;
}
*start;
void append(char n[100],int a,int s);
void sort();
void display();
int main()
{
	char n[100];
	int a,s,i;
	start=NULL;
	puts("Enter details of 10 people");
	for(i=1;i<=10;i++)
	{
		gets(n);
		scanf("%d %d",&a,&s);
		getchar();
		append(n,a,s);
	}
	sort();
	display();
	return 0;
}
void append(char n[100],int a,int s)
{
	struct person *nptr, *ptr;
	nptr=(struct person *)malloc(sizeof(struct person));
	strcpy(nptr->data.name,n);
	nptr->data.age=a;
	nptr->data.salary=s;
	nptr->link=NULL;
	if(start==NULL)
		start=nptr;
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=nptr;
	}
}
void sort()
{
	struct details temp;
	int i,j;
	struct person *ptr1, *ptr2;
	for(i=0;i<10;i++)
	{
		ptr1=start;
		ptr2=start->link;
		for(j=0;j<10-i-1;j++)
		{
			if(strcmp(ptr1->data.name,ptr2->data.name)>0)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr1=ptr2;
			ptr2=ptr2->link;
		}
	}
}
void display()
{
	struct person *ptr;
	ptr=start;
	printf("%50s %10s %10s\n","name","age","salary");
	while(ptr!=NULL)
	{
		printf("%50s %10d %10d\n",ptr->data.name,ptr->data.age,ptr->data.salary);
		ptr=ptr->link;
	}
}
