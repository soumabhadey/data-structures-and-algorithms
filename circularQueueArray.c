#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int arr[MAX],front,rear;
void insert();
void del();
void display();
int main()
{
	int ch;
	system("cls");
	front=rear=-1;
	while(1)
	{
		printf("\nMenu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid choice\n");
		}
	}
}
void insert()
{
	int n;
	if((front==0&&rear==MAX-1)||rear+1==front)
		printf("\nCircular queue is full\n");
	else
	{
		printf("\nEnter item: ");
		scanf("%d",&n);
		if(front==-1&&rear==-1)
			front=rear=0;
		else
			rear=(rear+1)%MAX;
		arr[rear]=n;
		display();
	}
}
void del()
{
	if(front==-1&&rear==-1)
		printf("\nCircular queue is empty\n");
	else
	{
		printf("%d\n",arr[front]);
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%MAX;
		display();
	}
}
void display()
{
	int i;
	if(front==-1&&rear==-1)
		printf("\nCircular queue is empty\n");
	else
	{
		printf("\nCircular queue\n");
		for(i=front;i!=rear;i=(i+1)%MAX)
			printf("%d\t",arr[i]);
		printf("%d\n",arr[i]);
	}
}