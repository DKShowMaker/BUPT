#include<stdio.h>
int convert(int n);
int main()
{
	int x,y;
	scanf("%d",&x);
	y=convert(x);
	printf("%d",y);
	return 0;
}
int convert(int n)
{
	if(n==0||n==1)
	return n;
	else
	return n%10+convert(n/10)*2;
}
