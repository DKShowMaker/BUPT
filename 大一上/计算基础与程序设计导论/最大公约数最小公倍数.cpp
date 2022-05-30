#include<stdio.h>
int main()
{
	int m,n,a,b,c,j,i;
	scanf("%d%d",&m,&n);
	b=1;
	if(m%2==0&&n%2==0)
	{
		i=m/2;
		j=n/2;
		b=b*2;
		while(i%2==0&&j%2==0)
	{
		i=i/2;
		j=j/2;
		b=b*2;
		 
	}
	}
	else
	{
		i=m;
		j=n;
	}
	while(i!=j)
	{
		if(i>j)
		i=i-j;
		if(i<j)
		j=j-i;
	}
	a=b*j;
	c=a*(m/a)*(n/a);
	printf("%d %d",a,c);
	return 0;
}
