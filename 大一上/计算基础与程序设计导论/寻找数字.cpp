#include<stdio.h>
int main()
{
	int n,i,x,b;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(b=0;b<10;b++)
	{
		x=0;
		for(i=0;i<n;i++)
		{
			if(b==a[i])
			{
				x++;
			}
		}
		if(x==1)
		printf("%d",b);
	}
	return 0;
}
