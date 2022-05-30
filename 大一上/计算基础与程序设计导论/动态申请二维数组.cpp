#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,**a,i,j;
	scanf("%d%d",&n,&m);
	a=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*m);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j]=-a[i][j]*10;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	free(a[i]);
	free(a);
	a=NULL;
	return 0;
}
