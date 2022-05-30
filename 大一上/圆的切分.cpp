#include<stdio.h>
int main()
{
	int n,x,m;
	scanf("%d",&n);
	x=1;
	m=0;
	while(m<=n)
	{
		x=x+m;
		m++;
	}
	printf("%d",x);
	return 0;
}
