#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
struct node_
{
    int data;
    struct node_ *link;
} *start;
typedef struct node_ node; 
void insertBeg(int);
void insertEnd(int);
void insertSort(int);
void appendLocation(int,int);
void displayList();
void del(int);
void emptyList();
int count();
void reverseList();
void ascendingBubbleSort();
void descendingBubbleSort();
void ascendingSelectionSort();
void descendingSelectionSort();
int main()
{
    int val,ch,loc;
    char cont;
    start=NULL;
    do
    {
        puts("Menu");
        puts("1. Insert at beginning");
        puts("2. Insert at end");
        puts("3. Insert in sorted manner");
        puts("4. Append at location");
        puts("5. Delete");
        puts("6. Empty list");
        puts("7. Count number of nodes");
        puts("8. Display list");
        puts("9. Reverse list");
        puts("10. Sort in ascending order using bubble sort");
        puts("11. Sort in descending order using bubble sort");
        puts("12. Sort in ascending order using selection sort");
        puts("13. Sort in descending order using selection sort");
        puts("Enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
        	case 1:
            	puts("Enter value");
            	scanf("%d",&val);
            	insertBeg(val);
            	puts("Updated list");
            	displayList();
            	break;
        	case 2:
            	puts("Enter value");
            	scanf("%d",&val);
            	insertEnd(val);
            	puts("Updated list");
            	displayList();
            	break;
        	case 3:
            	puts("Enter value");
            	scanf("%d",&val);
            	insertSort(val);
            	puts("Updated list");
            	displayList();
            	break;
        	case 4:
            	puts("Enter value");
            	scanf("%d",&val);
            	puts("Enter location");
            	scanf("%d",&loc);
            	appendLocation(val,loc);
            	puts("Updated list");
            	displayList();
            	break;
        	case 5:
            	puts("Enter location");
            	scanf("%d",&loc);
            	del(loc);
            	puts("Updated list");
            	displayList();
            	break;
        	case 6:
        		emptyList();
        		puts("Updated list");
        		displayList();
        		break;
       		case 7:
       			printf("Number of nodes = %d\n",count());
       			break;
 			case 8:
 				puts("Current list");
 				displayList();
 				break;
			case 9:
				reverseList();
				puts("Updated list");
				displayList();
				break;
			case 10:
				ascendingBubbleSort();
				puts("Updated list");
				displayList();
				break;
			case 11:
				descendingBubbleSort();
				puts("Updated list");
				displayList();
				break;
			case 12:
				ascendingSelectionSort();
				puts("Updated list");
				displayList();
				break;
			case 13:
				descendingSelectionSort();
				puts("Updated list");
				displayList();
				break;
       		default:
       			puts("Invalid choice");
        }
        fflush(stdin);
        puts("Continue? y/n");
        cont=getchar();
    }while(cont=='y'||cont=='Y');
    return  0;
}
void insertBeg(int val)
{
	node *nptr;
    nptr=(node *)malloc(sizeof(node));
    nptr->data=val;
    nptr->link=start;
    start=nptr;
}
void insertEnd(int val)
{
	node *save, *nptr;
    save=start;
    nptr=(node *)malloc(sizeof(node));
    nptr->data=val;
    nptr->link=NULL;
    if(start==NULL)
        start=nptr;
    else
    {
        while(save->link!=NULL)
            save=save->link;
        save->link=nptr;
    }
}
void insertSort(int val)
{
	node *save, *nptr;
    save=start;
    nptr=(node *)malloc(sizeof(node));
    nptr->data=val;
    nptr->link=NULL;
    if(start==NULL)
        start=nptr;
    else if(start->data>=val)
    {
        nptr->link=start;
        start=nptr;
    }
    else
    {
        while(save->link->data<=val&&save->link!=NULL)
            save=save->link;
        nptr->link=save->link;
        save->link=nptr;
    }
}
void appendLocation(int val,int loc)
{
    int i;
    node *save, *nptr;
    save=start;
    nptr=(node *)malloc(sizeof(node));
    nptr->data=val;
    nptr->link=NULL;
    if(loc==1)
    {
        nptr->link=start;
        start=nptr;
    }
    else
    {
        i=1;
        while(i<loc-1)
        {
            if(save==NULL)
            {
            	puts("Empty list");
            	return;
            }
			if(save->link==NULL)
            {
                puts("Out of bounds");
                return;
            }
            save=save->link;
            i++;
        }
        nptr->link=save->link;
        save->link=nptr;
    }
}
void displayList()
{
	node *save;
    save=start;
    while(save!=NULL)
    {
        printf("%d ",save->data);
        save=save->link;
    }
    puts("");
}
void del(int loc)
{
	node *ptr, *save;
    int i;
    save=start;
    
    if(start==NULL)
    {
    	puts("Empty list");
    	return;
    }
    else if(loc==1)
    {
    	ptr=start;
    	start=start->link;
    	free(ptr);
    }
    /*else if(loc==2)
    {
    	if(start->link==NULL)
    		puts("Out of bounds");
   		else
   		{
   			ptr=start->link;
   			start->link=start->link->link;
   			free(ptr);
		}
    }*/
    else
    {
    	save=start;
        i=1;
        while(i<=loc-1)
        {
            if(save->link==NULL)
            {
                puts("Out of bounds");
                return;
            }
            save=save->link;
            i++;
        }
        ptr=save->link;
        save->link=save->link->link;
        free(ptr);
    }
}
void emptyList()
{
	node *ptr;
	while(start!=NULL)
	{
		ptr=start;
		start=start->link;
		free(ptr);
	}
}
int count()
{
	node *save;
	int c;
	save=start;
	c=0;
	while(save!=NULL)
	{
		c++;
		save=save->link;
	}
	return c;
}
void reverseList()
{
	node *ptr1, *ptr2, *ptr3;
	ptr1=start;
	ptr2=NULL;
	while(ptr1!=NULL)
	{
		ptr3=ptr2;
		ptr2=ptr1;
		ptr1=ptr1->link;
		ptr2->link=ptr3;
	}
	start=ptr2;
}
void ascendingBubbleSort()
{
	int i,j,n,temp;
	node *ptr1, *ptr2;
	n=count();
	for(i=0;i<n;i++)
	{
		ptr1=start;
		ptr2=ptr1->link;
		for(j=0;j<n-i-1;j++)
		{
			if(ptr1->data>ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr1=ptr2;
			ptr2=ptr2->link;
		}
	}
}
void descendingBubbleSort()
{
	int i,j,n,temp;
	node *ptr1, *ptr2;
	n=count();
	for(i=0;i<n;i++)
	{
		ptr1=start;
		ptr2=ptr1->link;
		for(j=0;j<n-i-1;j++)
		{
			if(ptr1->data<ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr1=ptr2;
			ptr2=ptr2->link;
		}
	}
}
void ascendingSelectionSort()
{
	int i,j,temp,small,n;
	node *ptr1, *ptr2, *pos;
	n=count();
	ptr1=start;
	for(i=0;i<n-1;i++)
	{
		small=ptr1->data;
		pos=ptr1;
		ptr2=ptr1->link;
		for(j=i+1;j<n;j++)
		{
			if(small>ptr2->data)
			{
				small=ptr2->data;
				pos=ptr2;
			}
			ptr2=ptr2->link;
		}
		temp=ptr1->data;
		ptr1->data=pos->data;
		pos->data=temp;
	}
}
void descendingSelectionSort()
{
	int i,j,temp,large,n;
	node *ptr1, *ptr2, *pos;
	n=count();
	ptr1=start;
	for(i=0;i<n-1;i++)
	{
		large=ptr1->data;
		pos=ptr1;
		ptr2=ptr1->link;
		for(j=i+1;j<n;j++)
		{
			if(large<ptr2->data)
			{
				large=ptr2->data;
				pos=ptr2;
			}
			ptr2=ptr2->link;
		}
		temp=ptr1->data;
		ptr1->data=pos->data;
		pos->data=temp;
	}
}