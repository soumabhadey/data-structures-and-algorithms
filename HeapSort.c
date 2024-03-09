#include <stdio.h>
void heapsort(int[],int);
void heapify(int[],int,int);
void swap(int*,int*);
void printarray(int[],int);
int main(void) {
    printf("enter number of elements: ");
    int N;
    scanf("%d",&N);
    printf("enter elements: ");
    int a[N];
    int i;
    for(i=0;i<N;i++)
        scanf("%d",a+i);
    heapsort(a,N);
    printarray(a,N);
    printf("\n");
    return 0;
}
void heapsort(int a[],int N) {
    for(int i=N/2-1;i>=0;i--)
        heapify(a,N,i);
    for(int i=N-1;i>=0;i--) {
        swap(a,a+i);
        heapify(a,i,0);
    }
}
void heapify(int a[],int N,int i) {
    int large=i;
    int left=i*2+1;
    int right=i*2+2;
    if(left<N&&a[left]>a[large])
        large=left;
    if(right<N&&a[right]>a[large])
        large=right;
    if(large!=i) {
        swap(a+i,a+large);
        heapify(a,N,large);
    }
}
void swap(int *a,int *b) {
    *b=(*a+*b)-(*a=*b);
}
void printarray(int a[],int N) {
    for(int i=0;i<N;i++)
        printf("%d ",a[i]);
}
