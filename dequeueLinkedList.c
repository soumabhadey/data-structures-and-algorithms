#include <stdio.h>
#include <stdlib.h>
typedef struct node_
{
	int data;
	struct node_ *link;
} node;
typedef struct dequeue_
{
	node *left, *right;
} dequeue;
void insertLeft(dequeue *);
void insertRight(dequeue *);
int removeLeft(dequeue *);
int removeRight(dequeue *);
void display(dequeue *);
int isEmpty(dequeue *);
void construct(dequeue *);
void destruct(dequeue *);
int main()
{
	int ch;
	dequeue dq;
	construct(&dq);
	do
	{
		puts("1. insert left");
		puts("2. insert right");
		puts("3. remove left");
		puts("4. remove right");
		puts("5. display");
		puts("0. exit");
		puts("enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertLeft(&dq);
				break;
			case 2:
				insertRight(&dq);
				break;
			case 3:
				if(isEmpty(&dq))
					puts("underflow");
				else
					printf("%d\n",removeLeft(&dq));
				break;
			case 4:
				if(isEmpty(&dq))
					puts("underflow");
				else
					printf("%d\n",removeRight(&dq));
				break;
			case 5:
				display(&dq);
				break;
			case 0:
				destruct(&dq);
				return 0;
			default:
				puts("invalid");
		}
	} while(1);
}
void construct(dequeue *dq)
{
	dq->left=dq->right=NULL;
}
void insertLeft(dequeue *dq)
{
	node *nptr;
	nptr=(node *)malloc(sizeof(node));
	if(nptr==NULL)
	{
		puts("overflow");
		return;
	}
	puts("enter item");
	scanf("%d",&nptr->data);
	nptr->link=dq->left;
	if(dq->left==NULL)
		dq->left=dq->right=nptr;
	else
		dq->left=nptr;
}
void insertRight(dequeue *dq)
{
	node *nptr;
	nptr=(node *)malloc(sizeof(node));
	if(nptr==NULL)
	{
		puts("overflow");
		return;
	}
	puts("enter item");
	scanf("%d",&nptr->data);
	nptr->link=NULL;
	if(dq->right==NULL)
		dq->left=dq->right=nptr;
	else
	{
		dq->right->link=nptr;
		dq->right=nptr;
	}
}
int removeLeft(dequeue *dq)
{
	int item;
	node *temp;
	temp=dq->left;
	if(dq->left==dq->right)
		dq->left=dq->right=NULL;
	else
		dq->left=dq->left->link;
	item=temp->data;
	free(temp);
	return item;
}
int removeRight(dequeue *dq)
{
	int item;
	node *temp, *ptr;
	temp=dq->right;
	if(dq->left==dq->right)
		dq->left=dq->right=NULL;
	else
	{
		for(ptr=dq->left;ptr->link!=dq->right;ptr=ptr->link);
		ptr->link=NULL;
		dq->right=ptr;
	}
	item=temp->data;
	free(temp);
	return item;
}
void display(dequeue *dq)
{
	node *ptr;
	if(isEmpty(dq))
	{
		puts("empty");
		return;
	}
	for(ptr=dq->left;ptr!=NULL;ptr=ptr->link)
		printf("%d ",ptr->data);
	puts("");
}
int isEmpty(dequeue *dq)
{
	return dq->left==NULL;
}
void destruct(dequeue *dq)
{
	while(dq->left!=NULL)
		removeLeft(dq);
}