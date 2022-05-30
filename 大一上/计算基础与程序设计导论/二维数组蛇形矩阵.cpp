#include<stdio.h>
int main()
{
	int n,d,i,j,m,b,c,e;
	scanf("%d",&n);
	int a[n][n];
	i=1;
	j=-1;
	b=2;
	c=1;
	a[0][0]=1;
	if(n%2==0)
	{
		e=0;
		d=1;
	}
	else
	{
		d=0;
		e=1;
	}
	for(m=1;m<2*n-1;m++)
	{		
		if(m<=n-1)
		{
			if(j==-1)
		{
			for(i=m;i>=0;i--)
			{
				j=m-i;
				a[i][j]=b;
				b++;
			}
		}
		else if(i==-1)
		{
			for(j=m;j>=0;j--)
			{
				i=m-j;
				a[i][j]=b;
				b++;
			}
		}
		}
		else if(m>n-1)
		{
			if(d==c-1)
			{
				for(e=m-c;e>=c;e--)
				{
					d=m-e;
					a[e][d]=b;
					b++;
				}
				c++;
				e++;
			}
			else if(e==c-1)
			{
				for(d=m-c;d>=c;d--)
				{
					e=m-d;
					a[e][d]=b;
					b++;
				}
				c++;
				d++;
			}
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
