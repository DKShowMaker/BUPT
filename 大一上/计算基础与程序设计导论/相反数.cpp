#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		a[i]=a[i]*(-1)*10;
	}
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}

