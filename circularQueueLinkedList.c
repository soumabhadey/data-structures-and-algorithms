#include <stdio.h>
#include <stdlib.h>
typedef struct node_
{
	int data;
   struct node_ *link;
} node;
typedef struct circularQueue_
{
	node *front, *rear;
} circularQueue;
int isEmpty(circularQueue *);
void enque(circularQueue *);
int delque(circularQueue *);
void show(circularQueue *);
int main(void)
{
	int ch;
	circularQueue cq;
   cq.front=cq.rear=NULL;
   do
   {
   	puts("\n1. Enque");
      puts("2. Delque");
      puts("3. Show");
      puts("0. Exit");
      printf("\nEnter choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
      	case 1:
         	enque(&cq);
            break;
         case 2:
         	if(isEmpty(&cq))
            	puts("\nUnderflow");
            else
            	printf("\n%d\n",delque(&cq));
            break;
         case 3:
				if(isEmpty(&cq))
            	puts("\nEmpty");
            else
            	show(&cq);
            break;
         case 0:
         	return 0;
         default:
         	puts("\nInvalid");
      }
   } while(1);
}
int isEmpty(circularQueue *cq)
{
	return cq->front==NULL;
}
void enque(circularQueue *cq)
{
	node *nptr=(node *)malloc(sizeof(node));
   if(nptr==NULL)
   {
   	puts("\nOverflow");
      return;
   }
   if(isEmpty(cq))
   	cq->front=cq->rear=nptr;
   else
   {
   	cq->rear->link=nptr;
      cq->rear=nptr;
   }
   cq->rear->link=cq->front;
   printf("\nEnter item: ");
   scanf("%d",&cq->rear->data);
}
int delque(circularQueue *cq)
{
	node *temp=cq->front;
   int item=cq->front->data;
   if(cq->front==cq->rear)
   	cq->front=cq->rear=NULL;
   else
   {
   	cq->front=cq->front->link;
      cq->rear->link=cq->front;
   }
   free(temp);
   temp=NULL;
	return item;
}
void show(circularQueue *cq)
{
	node *ptr;
   puts("");
   for(ptr=cq->front;ptr!=cq->rear;ptr=ptr->link)
   	printf("%d ",ptr->data);
   printf("%d\n",cq->rear->data);
}
