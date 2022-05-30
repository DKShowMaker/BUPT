#include<stdio.h>
int main()
{
	int n,a,b,c,p,l,d;
	a=0;
	b=0;
	c=0;
	n=0;
	do
	{
		scanf("%d",&n);
		d=n;
		while(n%2==0&&n%10!=0)
		{
			n=n/2;
			a++;
		}
		
		while(n%5==0&&n%10!=0)
		{
			n=n/5;
			b++;
		}
		if(n%10==0)
		{
			while(n%2==0&&n!=0)
			{
				n=n/2;
				a++;
			}
			while(n%5==0&&n!=0)
			{
				n=n/5;
				b++;
			}
		}	
	}
	while(d!=0);
	if(a<=b)
	a=a;
	else
	a=b;
	printf("%d",a);
	return 0;
}

