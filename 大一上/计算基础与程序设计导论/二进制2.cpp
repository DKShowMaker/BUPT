#include<stdio.h>
int main()
{
	char a;
	double n,result,c,d;
	int b,i;
	i=2;
	b=0;
	c=0;
	scanf("%c",&a);
	while(a!='#')
	{
		if(a!='.')
		{
			n=a-48;
			b=b*2+n;
		}
		if(a=='.')
		{
			while(a!='#')
			{
				scanf("%c",&a);
				if(a=='#')
				{
					result=b+c;
					printf("%.6lf",result);
					return 0;
				}
				else
				{
					n=a-48;
					c=c+n/i;
					i=i*2;
				}		
			}
		}
		scanf("%c",&a);	
	}
	printf("%d",b);
	return 0;
}
