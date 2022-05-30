#include<stdio.h>
int main()
{
	int l;
	long long p,n;
	scanf("%d",&n);
	l=1;
	p=10;
	while(n/p!=0)
	{
		p=p*10;
		l++;
	}
	if(l%3==1)
	{
		l=l-1;
		printf("%d",n/(p/10));
		n=n-(n/(p/10))*(p/10);
		p=p/10;
	}
	else if(l%3==2)
	{
		l=l-2;
		printf("%d",n/(p/100));
		n=n-(n/(p/100))*(p/100);
		p=p/100;
	}
	else if(l%3==0)
	{
		printf("%d",n/(p/1000));
		n=n-(n/(p/1000))*(p/1000);
		l=l-3;
		p=p/1000;
	}
	while(l>0)
	{
		printf(",");
		printf("%d",n/(p/10));
		n=n-(n/(p/10))*(p/10);
		p=p/10;
		printf("%d",n/(p/10));
		n=n-(n/(p/10))*(p/10);
		p=p/10;
		printf("%d",n/(p/10));
		n=n-(n/(p/10))*(p/10);
		p=p/10;
		l=l-3;
	}
	return 0;
}
//зЂвт0 
