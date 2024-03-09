#include <stdio.h>
#include <stdlib.h>
#define MAX1 3
#define MAX2 3
int *matrix, *tuple, *transpose;
void createMatrix()
{
    int i;
    matrix=(int *)malloc(sizeof(int)*MAX1*MAX2);
    printf("Enter elements of %d * %d matrix\n",MAX1,MAX2);
    for(i=0;i<MAX1*MAX2;i++)
        scanf("%d",(matrix+i));
}
void displayMatrix()
{
    int i;
    for(i=0;i<MAX1*MAX2;i++)
    {
        if(i%MAX2==0&&i!=0)
            printf("\n");
        printf("%-10d", *(matrix+i));
    }
    printf("\n");
}
void createTranspose()
{
    int i,j;
    transpose=(int *)malloc(sizeof(int)*MAX2*MAX1);
    for(i=0;i<MAX2;i++)
    {
        for(j=0;j<MAX1;j++)
        {
            *(transpose+(i*MAX1)+j)= *(matrix+(j*MAX2)+i);
        }
    }
}
int count()
{
    int i,c;
    c=0;
    for(i=0;i<MAX1*MAX2;i++)
        if(*(matrix+i)!=0)
            c++;
    return c;
}
void createTuple()
{
    int l,r,c,i;
    tuple=(int *)malloc(sizeof(int)*(count()+1)*3);
    *(tuple+0)=MAX2;
    *(tuple+1)=MAX1;
    *(tuple+2)=count();
    l=3;
    r=0;
    c=0;
    for(i=0;i<MAX2*MAX1;i++)
    {
        if(i%MAX1==0&&i!=0)
        {
            r++;
            c=0;
        }
        if(*(transpose+i)!=0)
        {
            *(tuple+l)=r;
            l++;
            *(tuple+l)=c;
            l++;
            *(tuple+l)= *(transpose+i);
            l++;
        }
        c++;
    }
}
int main()
{
    int i;
    createMatrix();
    printf("Matrix\n");
    displayMatrix();
    createTranspose();
    printf("Transpose matrix\n");
    for(i=0;i<MAX2*MAX1;i++)
    {
        if(i%MAX1==0&&i!=0)
            printf("\n");
        printf("%-10d", *(transpose+i));
    }
    printf("\n");
    printf("Number of non-zero elements = %d\n",count());
    createTuple();
    printf("Tuple\n");
    for(i=0;i<(count()+1)*3;i++)
    {
        if(i%3==0&&i!=0)
            printf("\n");
        printf("%-10d", *(tuple+i));
    }
    printf("\n");
    return 0;
}