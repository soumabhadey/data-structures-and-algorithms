#include <stdio.h>
#include <ctype.h>
#define MAX 50
char infx[MAX],post[MAX],stack[MAX];
int top;
void input();
void convert();
void push(char);
char pop();
int priority(char);
void display();
int main()
{
	input();
	convert();
	display();
	return 0;
}
void input()
{
	printf("enter infix: ");
	gets(infx);
	top=-1;
}
void convert()
{
	char *i=infx, *p=post;
	while(*i)
	{
		if( *i==' ')
		{
			i++;
			continue;
		}
		if(isalpha(*i)||isdigit(*i))
		{
			*p= *i;
			p++;
			i++;
			continue;
		}
		if( *i=='(')
		{
			push(*i);
			i++;
			continue;
		}
		if( *i==')')
		{
			while(stack[top]!='(')
			{
				*p=pop();
				p++;
			}
			pop();
			i++;
			continue;
		}
		if( *i=='$'|| *i=='/'|| *i=='%'|| *i=='*'|| *i=='+'|| *i=='-')
		{
			while(top!=-1&&priority(stack[top])>=priority(*i))
			{
				*p=pop();
				p++;
			}
			push(*i);
			i++;
			continue;
		}
	}
	while(top!=-1)
	{
		*p=pop();
		p++;
	}
	*p='\0';
}
void push(char c)
{
	top++;
	stack[top]=c;
}
char pop()
{
	top--;
	return stack[top+1];
}
int priority(char c)
{
	if(c=='$')
		return 3;
	if(c=='/'||c=='%'||c=='*')
		return 2;
	if(c=='+'||c=='-')
		return 1;
	return 0;
}
void display()
{
	printf("postfix: %s\n",post);
}