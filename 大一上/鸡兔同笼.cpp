#include<stdio.h>
int main()
{
	int n,min,max;
	scanf("%d",&n);
	if(n%4==0)
	{
		max=n/2;
		min=n/4;
		printf("%d %d",max,min);
	}
	else
	{
		max=n/2;
		min=(n-2)/4+1;
		printf("%d %d",max,min);
		
	}
	return 0;
}
