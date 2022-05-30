#include<stdio.h>
int main()
{
	int x,a,p,b,l;
	b=1;
	p=10;
	scanf("%d",&x);
	if(1<=x&&x<=10000)
	{
		a=x*x;
		while(a/p!=0)
		{
			p=p*10;
		}
		while(b!=x&&b!=0)
		{
			b=a-(a/(p/10))*(p/10);
			p=p/10;
		}
		if(b==x)
		printf("Yes");
		else
		printf("No");
	}
	else
	printf("%d out of range",x);
	return 0;
}
