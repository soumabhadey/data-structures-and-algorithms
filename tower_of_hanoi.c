#include <stdio.h>
#include <math.h>
void toh(int,char,char,char);
int main(void) {
	int n;
	scanf("%d",&n);
	toh(n,'A','B','C');
	printf("%d steps\n",((int)pow(2,n))-1);
	return 0;
}
void toh(int n,char a,char b,char c) {
	if(n==1) {
		printf("%c to %c\n",a,b);
		return;
	}
	toh(n-1,a,c,b);
	toh(1,a,b,c);
	toh(n-1,c,b,a);
}