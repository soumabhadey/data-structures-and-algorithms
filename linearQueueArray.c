#include <stdio.h>
#define MAX 5
int front,rear,arr[MAX];
void insert();
int isFull();
int isEmpty();
void display();
void del();
int main()
{
	front=rear=-1;
	while(1)
    {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        int ch;
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
            case 0:
				exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
}
void insert()
{
	if(isFull())
		printf("\nQueue is full\n");
	else
	{
        if(isEmpty())
           front++;
        rear++;
        printf("\nEnter item: ");
        int n;
        scanf("%d",&n);
        arr[rear]=n;
        display();
	}
}
int isFull()
{
	return rear==MAX-1;
}
int isEmpty()
{
	return front==-1;
}
void display()
{
	if(isEmpty())
		printf("\nQueue is empty\n");
	else
	{
		printf("\nQueue\n");
		int i;
		for(i=front;i<=rear;i++)
			printf("%d\t",arr[i]);
		printf("\n");
	}
}
void del()
{
	if(isEmpty())
		printf("\nQueue is empty\n");
	else
	{
		printf("\n%d\n",arr[front]);
		if(front==rear)
		   front=rear=-1;
		else
			front++;
		display();
	}
}
