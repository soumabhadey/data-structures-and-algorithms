#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
struct node
{
    int data;
    struct node *link;
};
struct stack
{
    struct node *top;
};
void push(struct stack *s, int item);
void pop(struct stack *s);
int isEmpty(struct stack *s);
void peek(struct stack *s);
void show(struct stack *s);
void makeEmpty(struct stack *s);
int main()
{
    int choice,item;
    struct stack s;
    s.top=NULL;
    while(TRUE)
    {
        puts("0. Exit");
        puts("1. Push");
        puts("2. Pop");
        puts("3. Peek");
        puts("4. Show");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            makeEmpty(&s);
            return 0;
        case 1:
            printf("Enter item: ");
            scanf("%d",&item);
            push(&s,item);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            peek(&s);
            break;
        case 4:
            show(&s);
            break;
        default:
            puts("Invalid");
        }
    }
}
void push(struct stack *s, int item)
{
    struct node *nptr=(struct node *)malloc(sizeof(struct node));
    nptr->data=item;
    nptr->link=s->top;
    s->top=nptr;
}
void pop(struct stack *s)
{
    struct node *temp;
    if(isEmpty(s))
    {
        puts("Empty");
        return;
    }
    temp=s->top;
    s->top=s->top->link;
    printf("%d\n",temp->data);
    free(temp);
}
int isEmpty(struct stack *s)
{
    return s->top==NULL;
}
void peek(struct stack *s)
{
    if(isEmpty(s))
    {
        puts("Empty");
        return;
    }
    printf("%d\n",s->top->data);
}
void show(struct stack *s)
{
    struct node *ptr;
    if(isEmpty(s))
    {
        puts("Empty");
        return;
    }
    ptr=s->top;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
}
void makeEmpty(struct stack *s)
{
    struct node *temp;
    while(s->top!=NULL)
    {
        temp=s->top;
        s->top=s->top->link;
        free(temp);
    }
}