#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *next;
} *start;
struct node * create(int n);
void display(struct node *ptr);
int count(struct node *ptr);
void insertBegin();
void insertEnd();
void insertPos();
void delBegin();
void delEnd();
void delPos();
void sort();
void search(struct node *ptr,int pos,int item);
int main()
{
	int n,ch;
	start=NULL;
	do
	{
		printf("Menu\n");
		printf("1. Create\n");
		printf("2. Display\n");
		printf("3. Count\n");
		printf("4. Insert at beginning\n");
		printf("5. Insert at end\n");
		printf("6. Insert at position\n");
		printf("7. Delete from beginning\n");
		printf("8. Delete from end\n");
		printf("9. Delete from position\n");
		printf("10. Sort\n");
		printf("11. Search\n");
		printf("0. Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter number of nodes: ");
				scanf("%d",&n);
				start=create(n);
				break;
			case 2:
				printf("List: ");
				display(start);
				printf("\n");
				break;
			case 3:
				printf("Number of nodes: %d\n",count(start));
				break;
			case 4:
				insertBegin();
				break;
			case 5:
				insertEnd();
				break;
			case 6:
				insertPos();
				break;
			case 7:
				delBegin();
				break;
			case 8:
				delEnd();
				break;
			case 9:
				delPos();
				break;
			case 10:
				sort();
				break;
			case 11:
				printf("Enter item: ");
				scanf("%d",&n);
				search(start,1,n);
				break;
			case 0:
				return 0;
			default:
				printf("Invalid choice\n");
		}
	} while(1);
}
struct node * create(int n)
{
	struct node *nptr;
	int item;
	if(n==0)
		return NULL;
	nptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter item: ");
	scanf("%d",&item);
	nptr->info=item;
	nptr->next=create(n-1);
	return nptr;
}
void display(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("%d ",ptr->info);
	display(ptr->next);
}
int count(struct node *ptr)
{
	if(ptr==NULL)
		return 0;
	return 1+count(ptr->next);
}
void insertBegin()
{
	int item;
	struct node *nptr;
	nptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter item: ");
	scanf("%d",&item);
	nptr->info=item;
	nptr->next=start;
	start=nptr;
}
void insertEnd()
{
	int item;
	struct node *nptr, *ptr;
	nptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter item: ");
	scanf("%d",&item);
	nptr->info=item;
	nptr->next=NULL;
	if(start==NULL)
	{
		start=nptr;
		return;
	}
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=nptr;
}
void insertPos()
{
	int pos,item,i;
	struct node *nptr, *ptr;
	printf("Enter position: ");
	scanf("%d",&pos);
	if(pos<1||pos>count(start)+1)
	{
		printf("Invalid position\n");
		return;
	}
	if(pos==1)
	{
		insertBegin();
		return;
	}
	if(pos==count(start)+1)
	{
		insertEnd();
		return;
	}
	nptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter  item: ");
	scanf("%d",&item);
	nptr->info=item;
	ptr=start;
	i=1;
	while(i!=pos-1)
	{
		ptr=ptr->next;
		i++;
	}
	nptr->next=ptr->next;
	ptr->next=nptr;
}
void  delBegin()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=start;
	start=start->next;
	printf("%d\n",temp->info);
	free(temp);
}
void delEnd()
{
	struct node *temp, *ptr;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(start->next==NULL)
	{
		printf("%d\n",start->info);
		free(start);
		start=NULL;
		return;
	}
	ptr=start;
	while(ptr->next->next!=NULL)
		ptr=ptr->next;
	temp=ptr->next;
	ptr->next=NULL;
	printf("%d\n",temp->info);
	free(temp);
}
void delPos()
{
	int pos,i;
	struct node *ptr, *temp;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("Enter position: ");
	scanf("%d",&pos);
	if(pos<1||pos>count(start))
	{
		printf("Invalid position\n");
		return;
	}
	if(pos==1)
	{
		delBegin();
		return;
	}
	if(pos==count(start))
	{
		delEnd();
		return;
	}
	ptr=start;
	i=1;
	while(i!=pos-1)
	{
		ptr=ptr->next;
		i++;
	}
	temp=ptr->next;
	ptr->next=ptr->next->next;
	printf("%d\n",temp->info);
	free(temp);
}
void sort()
{
	int i,j,temp,n;
	struct node *ptr1, *ptr2;
	n=count(start);
	if(start==NULL||start->next==NULL)
		return;
	for(i=0;i<n;i++)
	{
		ptr1=start;
		ptr2=start->next;
		for(j=0;j<n-i-1;j++)
		{
			if(ptr1->info>ptr2->info)
			{
				temp=ptr1->info;
				ptr1->info=ptr2->info;
				ptr2->info=temp;
			}
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
	}
}
void search(struct node *ptr,int pos,int item)
{
	if(ptr==NULL)
	{
		printf("Not found\n");
		return;
	}
	if(ptr->info==item)
	{
		printf("Found at node %d\n",pos);
		return;
	}
	search(ptr->next,pos+1,item);
}


