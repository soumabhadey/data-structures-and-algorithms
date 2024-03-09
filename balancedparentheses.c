#include <stdio.h>
#include <stdlib.h>
enum boolean {
	true=1,
	false=0
};
struct node {
	char data;
	struct node *next;
};
struct stack {
	struct node *top;
};
void construct(struct stack *);
void push(struct stack *,char);
void pop(struct stack *);
enum boolean isEmpty(struct stack *);
enum boolean checkbalance(char *);
void display();
void construct(struct stack *s) {
	s->top=NULL;
}
void push(struct stack *s,char item) {
	struct node *nptr=(struct node *)malloc(sizeof(struct node));
	nptr->data=item;
	nptr->next=s->top;
	s->top=nptr;
}
void pop(struct stack *s) {
	struct node *temp=s->top;
	s->top=s->top->next;
	free(temp);
}
enum boolean isEmpty(struct stack *s) {
	return s->top==NULL;
}
enum boolean checkbalance(char *e) {
	struct stack s1;
	construct(&s1);
	while(*e) {
		if(*e=='(')
			push(&s1,*e);
		if(*e==')') {
			if(isEmpty(&s1))
				return false;
			pop(&s1);
		}
		e++;
	}
	return isEmpty(&s1);
}
int main() {
	printf("enter expression: ");
		char expression[50];
		scanf("%[^\n]s",expression);
		enum boolean balanced=checkbalance(expression);
		if(balanced)
			printf("balanced\n");
		else
			printf("unbalanced\n");
	return 0;
}





