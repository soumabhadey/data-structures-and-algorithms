#include <stdio.h>
#define MAX 5
typedef struct dequeue_
{
	int arr[MAX],left,right;
} dequeue;
int isFull(dequeue *);
int isEmpty(dequeue *);
void insertLeft(dequeue *);
void insertRight(dequeue *);
int removeLeft(dequeue *);
int removeRight(dequeue *);
void show(dequeue *);
int main()
{
	dequeue dq;
	int ch;
	dq.left=dq.right=-1;
	while(1)
	{
		puts("\n1. Insert left");
		puts("2. Insert right");
		puts("3. Remove left");
		puts("4. Remove right");
		puts("5. Show");
		puts("0. Exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(isFull(&dq))
					puts("\nFull");
				else
				{
					insertLeft(&dq);
					show(&dq);
				}
				break;
			case 2:
				if(isFull(&dq))
					puts("\nFull");
				else
				{
					insertRight(&dq);
					show(&dq);
				}
				break;
			case 3:
				if(isEmpty(&dq))
					puts("\nEmpty");
				else
				{
					printf("\n%d\n",removeLeft(&dq));
					show(&dq);
				}
				break;
			case 4:
				if(isEmpty(&dq))
					puts("\nEmpty");
				else
				{
					printf("\n%d\n",removeRight(&dq));
					show(&dq);
				}
				break;
			case 5:
				if(isEmpty(&dq))
					puts("\nEmpty");
				else
					show(&dq);
				break;
			case 0:
				return 0;
			default:
				puts("\nInvalid");
		}
	}
}
int isFull(dequeue *dq)
{
	return dq->left==0&&dq->right==MAX-1;
}
int isEmpty(dequeue *dq)
{
	return dq->left==-1;
}
void insertLeft(dequeue *dq)
{
	int item,i;
	printf("\nEnter item: ");
	scanf("%d",&item);
	if(dq->left==-1)
	{
		dq->left=dq->right=0;
		dq->arr[0]=item;
	}
	else if(dq->right!=MAX-1)
	{
		for(i=dq->right;i>=dq->left;i--)
			dq->arr[i+1]=dq->arr[i];
		dq->right++;
		dq->arr[dq->left]=item;
	}
	else
	{
		dq->left--;
		dq->arr[dq->left]=item;
	}
}
void insertRight(dequeue *dq)
{
	int item,i;
	printf("\nEnter item: ");
	scanf("%d",&item);
	if(dq->right==-1)
	{
		dq->left=dq->right=0;
		dq->arr[0]=item;
	}
	else if(dq->left!=0)
	{
		for(i=dq->left;i<=dq->right;i++)
			dq->arr[i-1]=dq->arr[i];
		dq->left--;
		dq->arr[dq->right]=item;
	}
	else
	{
		dq->right++;
		dq->arr[dq->right]=item;
	}
}
int removeLeft(dequeue *dq)
{
	int temp=dq->arr[dq->left];
	if(dq->left==dq->right)
		dq->left=dq->right=-1;
	else
		dq->left++;
	return temp;
}
int removeRight(dequeue *dq)
{
	int temp=dq->arr[dq->right];
	if(dq->left==dq->right)
		dq->left=dq->right=-1;
	else
		dq->right--;
	return temp;
}
void show(dequeue *dq)
{
	int i;
	puts("");
	for(i=dq->left;i<=dq->right;i++)
		printf("%d ",dq->arr[i]);
	puts("");
}
