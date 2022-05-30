#include<stdio.h>
int mypow(int x,int n);
int main()
{
	int x,n,y;
	scanf("%d%d",&x,&n);
	y=mypow(x,n);
	printf("%d",y);
	return 0;
}
int mypow(int x,int n)
{
	int a,b;
	a=x;
	while(n>1)
	{
		x=a*x;
		n--;
	}
	b=x;
	if(n==0)
	b=1;
	return b;
}
