#include<stdio.h>
int main()
{
	int n,i,m,j,x,y;
	x=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	int b[m];
	for(j=0;j<m;j++)
	scanf("%d",&b[j]);
	for(j=0;j<m;j++)
	{
		x=0;
		y=0;
		for(i=0;i<n&&y==0;i++)
		{
			if(n==1)
			printf("NULL\n");
			else if(a[i]==b[j])
			{
				if(i-1<0)
				printf("%d\n",a[i+1]);
				else if(i+1==n)
				printf("%d\n",a[i-1]);
				else
				printf("%d %d\n",a[i-1],a[i+1]);
				x=0;
				y=1;
			}
			else
			x++;	
		}
		if(x!=0)
		printf("NULL\n");
	}
	return 0;
}
