#include <stdio.h>
#define MAX 5
int main()
{
    int arr[MAX],top1=-1,top2=MAX,item,ch1,ch2;
    while(1)
    {
        printf("Choose stack\n");
        printf("1. Stack1\n");
        printf("2. stack2\n");
        printf("Enter choice: ");
        scanf("%d",&ch1);
        printf("Choose operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("Enter choice: ");
        scanf("%d",&ch2);
        switch(ch1)
        {
            case 1:
                switch(ch2)
                {
                    case 1:
                        if(abs(top1-top2)==1)
                            printf("Full\n");
                        else
                        {
                            printf("Enter item: ");
                            scanf("%d",&item);
                            top1++;
                            arr[top1]=item;
                        }
                        break;
                    case 2:
                        if(top1==-1)
                            printf("Empty\n");
                        else
                        {
                            printf("%d\n",arr[top1]);
                            top1--;
                        }
                }
                printf("Stack1\n");
                for(int i=top1;i>=0;i--)
                    printf("%d\n",arr[i]);
                break;
            case 2:
                switch(ch2)
                {
                    case 1:
                        if(abs(top1-top2)==1)
                            printf("Full\n");
                        else
                        {
                            printf("Enter item: ");
                            scanf("%d",&item);
                            top2--;
                            arr[top2]=item;
                        }
                        break;
                    case 2:
                        if(top2==MAX)
                            printf("Empty\n");
                        else
                        {
                            printf("%d\n",arr[top2]);
                            top2++;
                        }
                }
                printf("Stack2\n");
                for(int i=top2;i<MAX;i++)
                    printf("%d\n",arr[i]);
        }
    }
}