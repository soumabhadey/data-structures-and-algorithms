#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
struct node_
{
	struct node_ *prev;
	int data;
	struct node_ *next;
};
typedef struct node_ node;
node *start;
void append(int);
void display();
void insertBeginning(int);
int main()
{
	int ch,val;
	char cont;
	start=NULL;
	do
	{
		puts("Menu");
		puts("1. Append");
		puts("2. Display list");
		puts("3. Insert at beginning");
		puts("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				puts("Enter value");
				scanf("%d",&val);
				append(val);
				puts("Updated list");
				display();
				break;
			case 2:
				puts("Current list");
				display();
				break;
			case 3:
				puts("Enter value");
				scanf("%d",&val);
				insertBeginning(val);
				puts("Updated list");
				display();
				break;
			default:
				puts("Invalid choice");
		}
		fflush(stdin);
		puts("Do you want to continue? y/n");
		cont=getchar();
	}
	while(cont=='y');
	return 0;
}
void append(int val)
{
	node *nptr=(node *)malloc(sizeof(node)), *ptr;
	nptr->data=val;
	nptr->next=NULL;
	if(start==NULL)
	{
		nptr->prev=NULL;
		start=nptr;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		nptr->prev=ptr;
		ptr->next=nptr;
	}
}
void display()
{
	node *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	puts("");
}
void insertBeginning(int val)
{
	node *nptr;
	nptr=(node *)malloc(sizeof(node));
	nptr->data=val;
	nptr->prev=NULL;
	nptr->next=start;
	start=nptr;
	if(nptr->next!=NULL)
		nptr->next->prev=nptr;
}