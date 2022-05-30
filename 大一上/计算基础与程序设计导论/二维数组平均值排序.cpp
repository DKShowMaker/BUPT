#include<stdio.h>
int main()
{
	int m,r,i,j,n;
	float average1,average2,total;
	scanf("%d",&n);
	int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	average1=0;
	for(m=0;m<n;m++)
	{
		for(i=0;i<n;i++)
	{
		total=0;
		for(j=0;j<n;j++)
		{
			total=total+a[i][j];
		}
		average2=total/n;
		if(average1>average2&&i>0)
		{
			for(j=0;j<n;j++)
			{
				r=a[i][j];
				a[i][j]=a[i-1][j];
				a[i-1][j]=r;
			}
		}
		average1=average2;
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
//直接做和即可不必相除 
