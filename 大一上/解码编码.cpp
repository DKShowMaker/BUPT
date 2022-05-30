#include<stdio,h>
int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int a[n],b[n]={0};
	if(m==1)
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[j]<a[i])
				x++;
			}
			b[i]=x;
			x=0;
		}
		for(i=0;i<n;i++)
		printf("%d ",b[i]);
	}
	if(m==2)
	{
		for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		a[n-1]=b[n-1];
		for(i=n-1;i>0;i--)
		{
			if(b[i]==b[i-1])
			a[i-1]=a[i]+1;
			
		}
	}
}
