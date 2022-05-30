#include<stdio.h>
int main()
{
	int n,x,max,i;
	x=1;
	max=1;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			x++;
			if(x>max)
			max=x;
		}
		else
		x=1;
	}
	printf("%d",max);
	return 0;
}
