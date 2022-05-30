#include<stdio.h>
void recurPrintFactor(int n,int i);
int isPrime(int n);
int main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	i=a;
	while(i<=b)
	{ 
		printf("%d=",i);
		recurPrintFactor(i,2);
		printf("\n");
		i++;
	}
	return 0;
}
int isPrime(int n)
{
	int i,x;
	i=2;
	x=0;
	while(i*i<=n)
	{
		if(n%i==0)
		x++;
		i++;
	}
	if(x==0)
	return 1;
	else
	return 0;
}
void recurPrintFactor(int n,int i)
{
	if(isPrime(n)==1)
	printf("%d",n);
	else
	{
		if(n%i==0&&isPrime(i)==1)
		{
			printf("%d*",i);
			recurPrintFactor(n/i,2);
		}
		else
		recurPrintFactor(n,i+1);
	}	
}
