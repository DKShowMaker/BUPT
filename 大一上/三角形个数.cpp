#include<stdio.h>
int main()
{
	int n,a,b,c,i;
	scanf("%d",&n);
	a=1;
	b=1;
	i=0;
	while(a<n-1)
	{
		while(b<n-a)
		{
			c=n-a-b;
			if(a+b>c&&a+c>b&&b+c>a&&a>=b&&b>=c)
			{
				i++; 
				
			}
			
			b++;
		}
		b=1;
		a++;
	}
	printf("%d",i);
	
}
