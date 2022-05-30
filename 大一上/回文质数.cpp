#include<stdio.h>
int isPrime(int x);
int isHui(int n);
int main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	i=a;
	while(i<=b)
	{
		if(isHui(i)==1)
			if(isPrime(i)==1)
			printf("%d\n",i);
		i++;
	}
	return 0;
}
int isPrime(int x)
{
	int j,m;
	m=0;
	j=2;
	while(j<x)
	{
		if(x%j==0)
		m++;
		j++;
	}
	if(m==0)
	return 1;
	else
	return 0;
}
int isHui(int n)
{
	long long l,p,a,b,x,length;
	l=1;
	p=10;
	x=0;
	while(n/p!=0)
	{
		p=p*10;
		l++; 
	}
	length=l;
	if(length%2==0)
	{
		while(length>0)
		{
			a=n/(p/10);
			b=n%10;
			length=length-2;
			n=n/10-a*(p/100);
			p=p/100;
			if(a==b)
			x++;
		}
		if(x==l/2)
		return 1;
		else
		return 0;
	}
	else
	{
		while(length>1)
		{
			a=n/(p/10);
			b=n%10;
			length=length-2;
			n=n/10-a*(p/100);
			p=p/100;
			if(a==b)
			x++;
		}
		if(x==(l-1)/2)
		return 1;
		else
		return 0;
	}
}

