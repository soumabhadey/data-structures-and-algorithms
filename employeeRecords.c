#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
struct employee
{
	char name[MAX];
	char ssn[MAX];
	char sex[MAX];
	int salary;
	struct employee *next;
} *start;
struct employee * create(char nme[][MAX],char sn[][MAX],char sx[][MAX],int slary[],int lnk[],int index);
void displayList(struct employee *ptr);
void findByName(struct employee *ptr,char nme[]);
void findBySecurity(struct employee *ptr,char sss[]);
void findBySex(struct employee *ptr,int k);
void delByName(struct employee *ptr,char nnn[],int index);
void del(int index);
void addRecord(struct employee *ptr,struct employee e,int index);
void add(struct employee e,int index);
int main()
{
	char nme[][MAX]={
		"","Davis","Kelly","Green","","Brown","Lewis","","Cohen","Rubin","","Evans","","Harris"
	};
	char sn[][MAX]={
		"","192-38-7282","165-64-3351","175-56-2251","009","178-52-1065","181-58-9939","","177-44-4557","135-46-6262","","168-56-8113","","208-56-1654"
	};
	char sx[][MAX]={
		"","Female","Male","Male","","Female","Female","","Male","Female","","Male","","Female"
	};
	int slary[]={
		0,22800,19000,27200,191600,14700,16400,0,19000,15500,0,34200,0,22800
	};
	int lnk[]={
		0,12,7,14,6,9,10,11,2,5,13,4,1,3
	};
	struct employee e;
	start=(struct employee *)malloc(sizeof(struct employee));
	strcpy(start->name,nme[5-1]);
	strcpy(start->ssn,sn[5-1]);
	strcpy(start->sex,sx[5-1]);
	start->salary=slary[5-1];
	start->next=create(nme,sn,sx,slary,lnk,lnk[5-1]);
	displayList(start->next);
	printf("\n\n\n\n\n");
	findByName(start->next,"Evans");
	findByName(start->next,"Smith");
	findByName(start->next,"Lewis");
	printf("\n\n\n\n\n");
	findBySecurity(start->next,"165-64-3351");
	findBySecurity(start->next,"136-46-6262");
	findBySecurity(start->next,"177-44-5555");
	printf("\n\n\n\n\n");
	findBySex(start->next,2);
	findBySex(start->next,5);
	findBySex(start->next,1);
	printf("\n\n\n\n\n");
	delByName(start->next,"Davis",2);
	delByName(start->next,"Jones",2);
	delByName(start->next,"Rubin",2);
	displayList(start->next);
	printf("\n\n\n\n\n");
	strcpy(e.name,"Fletcher");
	strcpy(e.ssn,"168-52-3388");
	strcpy(e.sex,"Female");
	e.salary=21000;
	e.next=NULL;
	addRecord(start->next,e,2);
	strcpy(e.name,"Nelson");
	strcpy(e.ssn,"175-32-2468");
	strcpy(e.sex,"Male");
	e.salary=19000;
	e.next=NULL;
	addRecord(start->next,e,2);
	displayList(start->next);
	return 0;
}
struct employee * create(char nme[][MAX],char sn[][MAX],char sx[][MAX],int slary[],int lnk[],int index)
{
	struct employee *nptr;
	if(index==5)
		return start;
	nptr=(struct employee *)malloc(sizeof(struct employee));
	strcpy(nptr->name,nme[index-1]);
	strcpy(nptr->ssn,sn[index-1]);
	strcpy(nptr->sex,sx[index-1]);
	nptr->salary=slary[index-1];
	nptr->next=create(nme,sn,sx,slary,lnk,lnk[index-1]);
	return nptr;
}
void displayList(struct employee *ptr)
{
	if(ptr==start)
		return;
	printf("%-20s %-20s %-20s %-20d\n",ptr->name,ptr->ssn,ptr->sex,ptr->salary);
	displayList(ptr->next);
}
void findByName(struct employee *ptr,char nnn[])
{
	if(ptr==start)
	{
		printf("Not found\n");
		return;
	}
	if(strcmp(ptr->name,nnn)==0)
	{
		printf("%-20s %-20s %-20s %-20d\n",ptr->name,ptr->ssn,ptr->sex,ptr->salary);
		return;
	}
	findByName(ptr->next,nnn);
}
void findBySecurity(struct employee *ptr,char sss[])
{
	if(ptr==start)
	{
		printf("Not found\n");
		return;
	}
	if(strcmp(ptr->ssn,sss)==0)
	{
		printf("%-20s %-20s %-20s %-20d\n",ptr->name,ptr->ssn,ptr->sex,ptr->salary);
		return;
	}
	findBySecurity(ptr->next,sss);
}
void findBySex(struct employee *ptr,int k)
{
	if(ptr==start)
		return;
	if(k==1&&strcmp(ptr->sex,"Male")==0)
		printf("%-20s %-20s %-20s %-20d\n",ptr->name,ptr->ssn,ptr->sex,ptr->salary);
	else if(k==2&&strcmp(ptr->sex,"Female")==0)
		printf("%-20s %-20s %-20s %-20d\n",ptr->name,ptr->ssn,ptr->sex,ptr->salary);
	findBySex(ptr->next,k);
}
void delByName(struct employee *ptr,char nnn[],int index)
{
	if(ptr==start)
		return;
	if(strcmp(ptr->name,nnn)==0)
	{
		del(index);
		return;
	}
	delByName(ptr->next,nnn,index+1);
}
void del(int index)
{
	struct employee *ptr=start,*temp;
	int i=1;
	while(i!=index-1)
	{
		ptr=ptr->next;
		i++;
	}
	temp=ptr->next;
	ptr->next=ptr->next->next;
	itoa(atoi(start->ssn)-1,start->ssn,10);
	start->salary-=temp->salary;
	free(temp);
}
void addRecord(struct employee *ptr,struct employee e,int index)
{
	if(ptr==start||strcmp(e.name,ptr->name)<=0)
	{
		add(e,index);
		return;
	}
	addRecord(ptr->next,e,index+1);
}
void add(struct employee e,int index)
{
	struct employee *ptr=start,*nptr=(struct employee *)malloc(sizeof(struct employee));
	int i=1;
	while(i!=index-1)
	{
		ptr=ptr->next;
		i++;
	}
	strcpy(nptr->name,e.name);
	strcpy(nptr->ssn,e.ssn);
	strcpy(nptr->sex,e.sex);
	nptr->salary=e.salary;
	nptr->next=ptr->next;
	ptr->next=nptr;
	itoa(atoi(start->ssn)+1,start->ssn,10);
	start->salary+=nptr->salary;
}