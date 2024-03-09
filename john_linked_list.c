#include <stdio.h>
#include <stdlib.h>
struct node {
	int info;
	int color;
	struct node *next;
} *start;
void findup();
struct node * create(struct node *,int);
void addbeg();
void find2large();
struct node * del2large(struct node *,int);
void printrev(struct node *);
void display(struct node *);
int main(void) {
	printf("reading 4 numbers.....\n");
	start=NULL;
	start=create(start,4);
	printf("reading new number.....\n");
	addbeg();
	findup();
	find2large();
	printf("Reverse: ");
	printrev(start);
	printf("\n");
	return 0;
}
void findup() {
	struct node *ptr1, *ptr2;
	printf("Duplicates: ");
	for(ptr1=start;ptr1!=NULL;ptr1=ptr1->next) {
		if(ptr1->color==2)
			continue;
		for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next) {
			if(ptr2->color==2)
				continue;
			if(ptr2->info==ptr1->info) {
				ptr2->color=2;
				if(ptr1->color==2)
					continue;
				ptr1->color=2;
				printf("%d ",ptr1->info);
			}
		}
		ptr1->color=2;
	}
	printf("\n");
}
struct node * create(struct node *ptr,int n) {
	if(n==0)
		return NULL;
	ptr=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&(ptr->info));
	ptr->color=1;
	ptr->next=create(ptr->next,n-1);
	return ptr;
}
void addbeg() {
	struct node *nptr;
	nptr=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&(nptr->info));
	nptr->color=1;
	nptr->next=start;
	start=nptr;
}
void find2large() {
	int large1,large2,i;
	struct node *ptr;
	large1=start->info;
	large2=start->next->info;
	if(large2>large1) {
		large1=start->next->info;
		large2=start->info;
	}
	for(ptr=start->next->next;ptr!=NULL;ptr=ptr->next) {
		if(ptr->info>large2)
			large2=ptr->info;
		if(large2>large1)
			large2=(large1+large2)-(large1=large2);
	}
	start=del2large(start,large2);
}
struct node * del2large(struct node *ptr,int item) {
	int flag;
	struct node *temp;
	if(ptr==NULL)
		return NULL;
	flag=0;
	if(ptr->info==item)
		flag=1;
	ptr->next=del2large(ptr->next,item);
	if(flag) {
		temp=ptr;
		ptr=ptr->next;
		free(temp);
	}
	return ptr;
}
void printrev(struct node *ptr) {
	if(ptr==NULL)
		return;
	printrev(ptr->next);
	printf("%d ",ptr->info);
}
void display(struct node *ptr) {
	if(ptr==NULL)
		return;
	printf("%d ",ptr->info);
	display(ptr->next);
}



