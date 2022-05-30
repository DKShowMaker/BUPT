#include<stdio.h>
int main()
{
	int x,y,n,i,j;
	scanf("%d",&n);

	for(i=2;i<=n/2;i++)
	{
		x=0;
		y=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			x++;
		}
		for(j=2;j<(n-i);j++)
		{
			if((n-i)%j==0)
			y++;
		}
		if(x==0&&y==0)
		printf("%d and %d\n",i,n-i);
	}
	return 0;
}
