#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct client;
struct lawyer;
struct client
{
	char name[10];
	int age;
	struct client *link;
};
struct lawyer
{
	char name[10];
	struct client *start;
} arr[4];
struct client * create();
void add(struct lawyer *lptr,char nm[10],int ag);
int main()
{
	int i,K;
	for(i=0;i<4;i++)
	{
		printf("Enter lawyer name: ");
		scanf("%s",arr[i].name);
		printf("Enter clients and age. Enter 0 to stop\n");
		arr[i].start=create();
	}
	printf("Enter lawyer number: ");
	scanf("%d",)
	listclients(K);
	return 0;
}
struct client * create()
{
	struct client *nptr;
	int ag;
	char nm[10];
	scanf("%s",nm);
	if(strcmp(nm,"0")==0)
		return NULL;
	scanf("%d",&ag);
	nptr=(struct client *)malloc(sizeof(struct client));
	strcpy(nptr->name,nm);
	nptr->age=ag;
	nptr->link=create();
	return nptr;
}
void add(struct lawyer *lptr,char nm[10],int ag)
{
	struct client *nptr=(struct client *)malloc(sizeof(struct client));
	strcpy(nptr->name,nm);
	nptr->age=ag;
	nptr->link=lptr->start;
	lptr->start=nptr;
	sort(lptr);
}
