#include<stdio.h>
int main()
{
	int n,j,i,r;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(j=1;j<n;j++)
	{
		for(i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				r=a[i+1];
				a[i+1]=a[i];
				a[i]=r;
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
