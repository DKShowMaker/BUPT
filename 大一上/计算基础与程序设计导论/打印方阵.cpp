#include<stdio.h>
int main()
{
	int n,i,j,c=1,s;
	scanf("%d",&n);
	int a[n][n]={0};
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			a[i][j]=c;
			c++;
		}
		j=j-1;
		for(s=j-1;s>=0;s--)
		{
			a[s][j]=c;
			c++;
		}
		
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
