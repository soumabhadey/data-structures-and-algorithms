#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct stack {
	struct node *top;
};
void display();
int evaluate(char *);
void push(struct stack *,int);
int main(void) {
	display();
	getch();
	return 0;
}
void display() {
	printf("enter postfix expression: ");
	char expression[50];
	scanf("%[^\n]s",expression);
	printf("%d\n",evaluate(expression));
}
int evaluate(char *e) {
	struct stack s1;
	s1.top=NULL;
	while(*e) {
		if(*e==32) {
			e++;
			continue;
		}
		if(isdigit(*e)) {
			int r,num=0;
			while(isdigit(*e)) {
				r=*e-48;
				num=num*10+r;
				e++;
			}
			push(&s1,num);
			continue;
		}
		if(*e=='$'||*e=='/'||*e=='%'||*e=='*'||*e=='+'||*e=='-') {
			int b=pop(&s1);
			int a=pop(&s1);
			switch(*e) {
				case '$':
					push(&s1,(int)pow(a,b));
					break;
				case '/':
					push(&s1,a/b);
					break;
				case '%':
					push(&s1,a%b);
					break;
				case '*':
					push(&s1,a*b);
					break;
				case '+':
					push(&s1,a+b);
					break;
				case '-':
					push(&s1,a-b);
            }
        }
	}
	return pop(&s1);
}
void push(struct stack *s,int item) {
	struct node *nptr=(struct node *)malloc(sizeof(struct node));
	nptr->data=item;
    nptr->next=s->top;
	s->top=nptr;
}
int pop(struct stack *s) {
	int item=s->top->data;
	s->top=s->top->next;
	return item;
}









