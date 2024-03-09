#include <stdio.h>
#include <stdlib.h>
typedef struct node_
{
	struct node_ *prev, *next;
	int data;
} node;
node *start;
void append(int value)
{
	node *nptr;
	nptr=(node *)malloc(sizeof(node));
	nptr->data=value;
	if(start==NULL)
	{
		nptr->prev=nptr;
		nptr->next=nptr;
		start=nptr;
	}
	else
	{
		nptr->prev=start->prev;
		nptr->next=start;
		start->prev->next=nptr;
		start->prev=nptr;
	}
}
void addAtBegin(int value)
{
	append(value);
	start=start->prev;
}
void insert(int value,int position)
{
	node *nptr, *ptr;
	int i;
	if(position==1)
		addAtBegin(value);
	else if(start==NULL)
		puts("Empty list");
	else
	{
		i=1;
		ptr=start;
		while(i!=position-1)
		{
			if(ptr->next==start)
			{
				puts("Invalid position");
				return;
			}
			ptr=ptr->next;
			i++;
		}
		nptr=(node *)malloc(sizeof(node));
		nptr->data=value;
		nptr->prev=ptr;
		nptr->next=ptr->next;
		ptr->next->prev=nptr;
		ptr->next=nptr;
	}
}
void del(int position)
{
	node *ptr;
	int i;
	if(start==NULL)
		puts("Empty list");
	else
	{
		i=1;
		ptr=start;
		while(i!=position)
		{
			if(ptr->next==start)
			{
				puts("Invalid position");
				return;
			}
			ptr=ptr->next;
			i++;
		}
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		if(ptr==start)
		{
			if(ptr->next==start)
				start=NULL;
			else
				start=start->next;
		}
		free(ptr);
	}
}
void deallocate()
{
	while(start!=NULL)
		del(1);
}
int count()
{
	node *ptr;
	int c;
	if(start==NULL)
		return 0;
	c=1;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
		c++;
	}
	return c;
}
void display()
{
	node *ptr;
	puts("List");
	if(start!=NULL)
	{
		printf("%d ",start->data);
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
			printf("%d ",ptr->data);
		}
	}
	puts("");
}
void sort()
{
	node *ptr1, *ptr2;
	int i,j,temp,n;
	n=count();
	for(i=0;i<n;i++)
	{
		ptr1=start;
		ptr2=start->next;
		for(j=0;j<n-i-1;j++)
		{
			if(ptr1->data>ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr1=ptr2;
			ptr2=ptr2->next;
		}
	}
}
int main()
{
	start=NULL;
	append(10);
	addAtBegin(20);
	addAtBegin(5);
	append(30);
	insert(15,3);
	display();
	printf("Nodes=%d\n",count());
	sort();
	display();
	del(2);
	del(1);
	display();
	deallocate();
	display();
	printf("nodes=%d\n",count());
	return 0;
}