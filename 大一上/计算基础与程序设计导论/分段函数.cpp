#include<stdio.h>
int fun(int);
int main()
{
	int x,y;
	scanf("%d",&x);
	y=fun(x);
	printf("The result is:y=%d",y);
	return 0;
}
int fun(int n)
{
	int x;
	if(n<1)
	x=n;
	if(1<=n&&n<=10)
	x=2*n-1;
	if(10<n&&n<=100)
	x=3*n-11;
	if(n>100)
	x=n*n-24;
	return x;
}
