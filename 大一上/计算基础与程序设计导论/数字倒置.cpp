#include<stdio.h>
int reverseNum(int n);
int main()
{
	int x,y;
	scanf("%d",&x);
	y=reverseNum(x);
	printf("The reverse form of number %d is %d.",x,y);
	return 0;
}
int reverseNum(int n)
{
	int l,p,i,a;
	l=0;
	p=1;
	i=1;
	a=0;
	while(n/p!=0)
	{
		p=p*10;
		l=l+1;
	}
	while(l>0)
	{
		a=a+n/(p/10)*i;
		n=n-n/(p/10)*(p/10);
		p=p/10;
		i=i*10;
		l--;
	}
	return a;
}
