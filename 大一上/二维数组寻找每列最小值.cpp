#include<stdio.h>
void findMin(int M[][101],int a,int b);
int main()
{
	int i,j;
	int n,m;
	scanf("%d%d",&n,&m);
	int e[n][101];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		scanf("%d",&e[i][j]);
	}
	findMin(e,n,m);
	return 0;
}
void findMin(int M[][101],int a,int b)
{
	int i,j;
	int x[b]={0};
	for(j=0;j<b;j++)
	{
		x[j]=M[0][j];
		for(i=0;i<a;i++)
		{
			if(M[i][j]<x[j])
			x[j]=M[i][j];
		}
	}
	for(i=0;i<b;i++)
	printf("%d ",x[i]);
}
