#include<stdio.h>
int main()
{
	int n,i,x,y,m;
	m=0;
	x=0;
	y=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	int b[n];
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
		x++;
		else
		y++;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			b[m]=a[i];
			m++;
		}
		else
		{
			b[x]=a[i];
			x++;
		}
	}
	for(i=0;i<n;i++)
	printf("%d ",b[i]);
	printf("\n");
	return 0;
}
