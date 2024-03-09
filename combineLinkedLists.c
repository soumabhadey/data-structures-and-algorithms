#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
typedef struct node_
{
	int data;
	struct node_ *link;
} node;
typedef struct linkedList
{
	 node *start;
} list;
void display(node *start);
void append(node **start,int value);
void createC(node *start1,node *start2,node **start);
void createD(node *start1,node *start2,node **start);
int main()
{

	list A,B,C,D;
	int a[9]={3,7,10,15,16,9,22,17,32},b[9]={16,2,9,13,37,8,10,1,28},i;
	clrscr();
	A.start=B.start=C.start=D.start=NULL;
	for(i=0;i<9;i++)
	{
		append(&A.start,a[i]);
		append(&B.start,b[i]);
	}
	createC(A.start,B.start,&C.start);
	puts("Linked list C");
	display(C.start);
	createD(A.start,B.start,&D.start);
	puts("Linked list D");
	display(D.start);
	getch();
	return 0;
}
void append(node **start,int value)
{
	node *nptr, *ptr;
	nptr=(node *)malloc(sizeof(node));
	nptr->data=value;
	nptr->link=NULL;
	if(*start==NULL)
		*start=nptr;
	else
	{
		ptr= *start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=nptr;
	}
}
void createC(node *start1,node *start2,node **start)
{
	node *ptr1, *ptr2;
	ptr1=start1;
	while(ptr1!=NULL)
	{
		ptr2=start2;
		while(ptr2!=NULL)
		{
			if(ptr1->data==ptr2->data)
			{
				append(start,ptr1->data);
				break;
			}
			ptr2=ptr2->link;
		}
		ptr1=ptr1->link;
	}
}
void createD(node *start1, node *start2, node **start)
{
	node *ptr1, *ptr2;
	int present;
	ptr1=start1;
	while(ptr1!=NULL)
	{
		append(start,ptr1->data);
		ptr1=ptr1->link;
	}
	ptr1=start2;
	while(ptr1!=NULL)
	{
		present=FALSE;
		ptr2= *start;
		while(ptr2!=NULL)
		{
			if(ptr1->data==ptr2->data)
			{
				present=TRUE;
				break;
			}
			ptr2=ptr2->link;
		}
		if(!present)
			append(start,ptr1->data);
		ptr1=ptr1->link;
	}
}
void display(node *start)
{
	node *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	puts("");
}
