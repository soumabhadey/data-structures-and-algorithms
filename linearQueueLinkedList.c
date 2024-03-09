#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node_
{
	int data;
   struct node_ *link;
} node;
typedef struct queue_
{
	node *front, *rear;
} queue;
int isEmpty(queue *);
void enqueue(queue *);
void dequeue(queue *);
void show(queue *);
int main()
{
	queue q;
   clrscr();
	q.front=q.rear=NULL;
   int choice;
   do
   {
   	puts("\nMenu");
      puts("1. Enqueue");
      puts("2. Dequeue");
      puts("3. Show");
      puts("0. Exit");
      printf("\nEnter choice: ");
      scanf("%d",&choice);
		switch(choice)
      {
      	case 1:
         	enqueue(&q);
            break;
         case 2:
         	dequeue(&q);
            break;
         case 3:
         	show(&q);
            break;
         case 0:
         	getch();
            return 0;
         default: puts("\nInvalid choice");
      }
   } while(1);
}
int isEmpty(queue *q)
{
	return q->front==NULL;
}
void enqueue(queue *q)
{
	node *nptr;
	nptr=(node *)malloc(sizeof(node));
   if(nptr==NULL)
   	puts("\nOverflow");
   else
   {
   	printf("\nEnter item: ");
      scanf("%d",&nptr->data);
      nptr->link=NULL;
		if(isEmpty(q))
      	q->front=q->rear=nptr;
      else
      {
      	q->rear->link=nptr;
         q->rear=q->rear->link;
      }
		show(q);
   }
}
void dequeue(queue *q)
{
	node *temp;
	if(isEmpty(q))
   	puts("\nUnderflow");
   else
   {
   	printf("\n%d\n",q->front->data);
      temp=q->front;
		if(q->front==q->rear)
			q->front=q->rear=NULL;
      else
      	q->front=q->front->link;
      free(temp);
      temp=NULL;
      show(q);
   }
}
void show(queue *q)
{
	node *ptr;
	if(isEmpty(q))
   	puts("\nEmpty");
   else
   {
   	puts("\nQueue");
   	for(ptr=q->front;ptr!=NULL;ptr=ptr->link)
      	printf("%d\t",ptr->data);
      puts("");
   }
}