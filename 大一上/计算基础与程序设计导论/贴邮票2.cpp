#include<stdio.h>
int main()
{
	int n,x,a,b,c,d,min;
	min=1000;
	scanf("%d",&n);
	for(d=0;d<=n/34;d++)
	{
		for(c=0;c<=n/21;c++)
		{
			for(b=0;b<=n/10;b++)
			{
				for(a=0;a<=n;a++)
				{
					if(n==a+10*b+21*c+34*d)
					{
						x=a+b+c+d;
						if(x<min)
						min=x;
					}
				}
			}
		}
	}
	printf("%d",min);
}
