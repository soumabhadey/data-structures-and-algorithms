#include <stdio.h>
#include <stdlib.h>
#define MAX1 3
#define MAX2 3
int main()
{
    int *A, *B, *C, *T1, *T2, *T3;
    int i;
    A=(int *)malloc(sizeof(int)*MAX1*MAX2);
    B=(int *)malloc(sizeof(int)*MAX1*MAX2);
    C=(int *)malloc(sizeof(int)*MAX1*MAX2);
    printf("Enter elements of A\n");
    createMatrix(A);
    printf("Enter elements of B\n");
    createMatrix(B);
    T1=(int *)malloc(sizeof(int)*(count(A)+1)*3);
    createTuple(A,T1);
    T2=(int *)malloc(sizeof(int)*(count(B)+1)*3);
    createTuple(B,T2);
    T3=(int *)malloc(sizeof(int)*(count2(A,B)+1)*3);
    calculate(T1,T2,T3,count2(A,B));
    printf("Resultant tuple\n");
    for(i=0;i<(count2(A,B)+1)*3;i++)
    {
        if(i%3==0&&i!=0)
            printf("\n");
        printf("%d ", *(T3+i));
    }
    return 0;
}
void createMatrix(int *X)
{
    int i;
    for(i=0;i<MAX1*MAX2;i++)
        scanf("%d",X+i);
}
int count(int *X)
{
    int i,c;
    c=0;
    for(i=0;i<MAX1*MAX2;i++)
        if(*(X+i)!=0)
            c++;
    return c;
}
void createTuple(int *X, int *T)
{
    int l,r,c,i;
    *(T+0)=MAX1;
    *(T+1)=MAX2;
    *(T+2)=count(X);
    l=3;
    r=0;
    c=0;
    for(i=0;i<MAX1*MAX2;i++)
    {
        if(i%3==0&&i!=0)
        {
            r++;
            c=0;
        }
        if(*(X+i)!=0)
        {
            *(T+l)=r;
            l++;
            *(T+l)=c;
            l++;
            *(T+l)= *(X+i);
            l++;
        }
        c++;
    }
}
int count2(int *X, int *Y)
{
    int i,c;
    c=0;
    for(i=0;i<MAX1*MAX2;i++)
        if(*(X+i)!=0|| *(Y+i)!=0)
            c++;
    return c;
}
void calculate(int *T1, int *T2, int *T3, int count)
{
    int *r1, *c1, *a, *r2, *c2, *b;
    int i,j,l;
    r1=T1+MAX2;
    c1=r1+1;
    a=c1+1;
    r2=T2+MAX2;
    c2=r2+1;
    b=c2+1;
    i=j=1;
    *(T3+0)=MAX1;
    *(T3+1)=MAX2;
    *(T3+2)=count;
    l=3;
    while(i<T1[2]+1&&j<=T2[2]+1)
    {
        if(*r1== *r2 && *c1== *c2)
        {
            *(T3+l)= *r1;
            l++;
            *(T3+l)= *c1;
            l++;
            *(T3+l)= *a + *b;
            l++;
            r1+=3;
            c1+=3;
            a+=3;
            r2+=3;
            c2+=3;
            b+=3;
            i++;
            j++;
        }
        else if((*r1*3+ *c1)<(*r2*3+ *c2))
        {
            *(T3+l)= *r1;
            l++;
            *(T3+l)= *c1;
            l++;
            *(T3+l)= *a;
            l++;
            r1+=3;
            c1+=3;
            a+=3;
            i++;
        }
        else
        {
            *(T3+l)= *r2;
            l++;
            *(T3+l)= *c2;
            l++;
            *(T3+l)= *b;
            l++;
            r2+=3;
            c2+=3;
            b+=3;
            j++;
        }
    }
    while(i<T1[2]+1)
    {
        *(T3+l)= *r1;
        l++;
        *(T3+l)= *c1;
        l++;
        *(T3+l)= *a;
        l++;
        r1+=3;
        c1+=3;
        a+=3;
        i++;
    }
    while(j<T2[2]+1)
    {
        *(T3+l)= *r2;
        l++;
        *(T3+l)= *c2;
        l++;
        *(T3+l)= *b;
        l++;
        r2+=3;
        c2+=3;
        b+=3;
        j++;
    }
}