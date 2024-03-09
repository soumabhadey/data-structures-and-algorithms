#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
	char info;
	struct node *next;
} *start;
struct node * create(char s[],int index);
void displayList(struct node *ptr);
void changeCaseLower(struct node *ptr);
int main()
{
	char s[]="DATA STRUCTURES";
	start=create(s,0);
	displayList(start);
	printf("\n");
	changeCaseLower(start);
	displayList(start);
	printf("\n");
	return 0;
}
struct node * create(char s[],int index)
{
	struct node *nptr;
	if(s[index]=='\0')
		return NULL;
	nptr=(struct node *)malloc(sizeof(struct node));
	nptr->info=s[index];
	nptr->next=create(s,index+1);
	return nptr;
}
void displayList(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("%c",ptr->info);
	displayList(ptr->next);
}
void changeCaseLower(struct node *ptr)
{
	if(ptr==NULL)
		return;
	if(isalpha(ptr->info)&&isupper(ptr->info))
		ptr->info=(char)(ptr->info+32);
	changeCaseLower(ptr->next);
}
