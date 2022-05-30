#include<stdio.h>
int main()
{
	int n,m,i,j,k,d,f,e,min,max;
	k=0;
	scanf("%d%d",&n,&m);
	int a[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		max=a[i][0];
		for(j=0;j<m;j++)
		{
			if(a[i][j]>max)
			{
				max=a[i][j];
				d=j;
			} 
		}
		min=a[0][d];
		for(e=0;e<n;e++)
		{
			if(a[e][d]<min)
			{
				min=a[e][d];
				f=e;
			}
		}
		if(min==max)
		k++;
	}
	if(k!=0)
	printf("The saddle point is (%d,%d)=%d.",f,d,min);
	else
	printf("There is no saddle point in the matrix.");
	return 0;
}
