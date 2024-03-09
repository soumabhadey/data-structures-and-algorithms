#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int stack[10],top=-1;
int evalpost(char *);
void push(int);
int pop();
void sort(int *,int);
int main(void) {
	int a[5],i;
	char expr[20];
	system("cls");
	printf("reading 5 numbers.....\n");
	for(i=0;i<5;i++)
		scanf("%d",a+i);
	getchar();
	gets(expr);
	sort(a,5);
	if(logsearch(a,0,4,evalpost(expr)))
		printf("present\n");
	else
		printf("not present\n");
	return 0;
}
int evalpost(char *ptr) {
	int r,num,a,b;
	while(*ptr) {
		if(*ptr==32) {
			ptr++;
			continue;
		}
		if(*ptr>='0'&& *ptr<='9') {
			num=0;
			while(*ptr>='0'&& *ptr<='9') {
				r= *ptr-((int)'0');
				num=num*10+r;
				ptr++;
			}
			push(num);
			continue;
		}
		if(*ptr=='$'|| *ptr=='/'|| *ptr=='%'|| *ptr=='*'|| *ptr=='+'|| *ptr=='-') {
			b=pop();
			a=pop();
			switch(*ptr) {
				case '$':
					push((int)pow(a,b));
					break;
				case '/':
					push(a/b);
					break;
				case '%':
					push(a%b);
					break;
				case '*':
					push(a*b);
					break;
				case '+':
					push(a+b);
					break;
				case '-':
					push(a-b);
			}
			ptr++;
		}
	}
	return pop();
}
void push(int n) {
	stack[++top]=n;
}
int pop() {
	return stack[top--];
}
void sort(int *a,int n) {
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
				a[j+1]=(a[j]+a[j+1])-(a[j]=a[j+1]);
}
int logsearch(int *a,int l,int u,int search) {
	int m;
	if(l>u)
		return 0;
	m=(l+u)/2;
	if(a[m]==search)
		return 1;
	if(a[m]<search)
		return logsearch(a,m+1,u,search);
	return logsearch(a,l,m-1,search);
}









