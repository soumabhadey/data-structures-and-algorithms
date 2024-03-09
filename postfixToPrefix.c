#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 20
char stack[MAX][MAX],temp[2],s1[MAX],s2[MAX],s3[MAX],post[1];
int top;
void input();
void convert();
void display();
void push(char *);
void pop(char *);
int main()
{
	input();
	convert();
	display();
	return 0;
}
void input()
{
	puts("Enter postfix expression");
	gets(post);
}
void convert()
{
	top=-1;
	char *i=post;
	while(*i)
	{
		if(*i==32)
		{
			i++;
		}
		else if(isalpha(*i)||isdigit(*i))
		{
			temp[0]= *i;
			temp[1]='\0';
			push(temp);
			i++;
		}
		else if(*i=='$'|| *i=='/'|| *i=='%'|| *i=='*'|| *i=='+')
		{
			temp[0]= *i;
			temp[1]='\0';
			pop(s1);
			pop(s2);
			strcpy(s3,temp);
			strcat(s3,s2);
			strcat(s3,s1);
			push(s3);
			i++;
		}
	}
}
void push(char *s)
{
	top++;
	strcpy(stack[top],s);
}
void pop(char *s)
{
	strcpy(s,stack[top]);
	top--;
}
void display()
{
	puts("Prefix expression");
	puts(stack[0]);
}
