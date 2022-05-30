#include<stdio.h>
int isPerfect(int n);
void printPerfect(int n);
int main()
{
	int n,i,m,a,b,j;
	scanf("%d%d",&n,&m);
	i=n;
	b=0;
	j=2;
	while(i<=m)
	{
		a=isPerfect(i);
		if(a==1)
		{
			j=2;
			printf("%d=",i);
			printf("1");
			while(j<i)
			{
				if(i%j==0)
				{
					printf("+%d",j);
				}
				
				j++;
			}
			printf("\n");
			b++;
		}
		i++;
	}
	printf("The total number is %d.",b);
	return 0;
}
int isPerfect(int n)
{
	int i,a,b;
	a=1;
	i=2;
	while(i*i<n)
	{
		if(n%i==0)
		a=a+i+n/i;
		i++;
	}
	if(n==1)
	b=0;
	else if(a==n)
	b=1;
	else
	b=0;
	return b;
}
